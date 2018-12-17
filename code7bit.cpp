// code7bit.cpp --- source code dirty 8-bit characters converter
// Copyright (C) 2018 Katayama Hirofumi MZ <katayama.hirofumi.mz@gmail.com>.
// This file is public domain software.
// ---
// This program converts dirty 8-bit characters in the source file into
// octal sequences "\OOO" or "\uXXXX", and vice versa.
//
// NOTE: UTF-16 is not supported yet.

#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>      // standard C library
#include <cstdio>       // standard I/O
#include <string>       // for std::string
#include <vector>       // for std::vector
#include <iostream>     // for std::cout and std::cerr
#include <fstream>      // for std::ifstream and std::ofstream
#include <streambuf>    // for std::istreambuf_iterator
#include <io.h>         // for _unlink
#include <clocale>      // for std::setlocale

#ifdef _WIN32
    #include <windows.h>
#endif

#ifdef USE_GETOPT_PORT
    #include "getopt.h" // for portable getopt_long
#else
    #include <getopt.h> // for GNU getopt_long
#endif

// the backup suffix
#define BACKUP_SUFFIX   ".bak"

// global variables
std::vector<std::string> g_files;
bool g_do_convert = false;
bool g_do_reverse = false;
bool g_do_test = false;
bool g_verbose = false;
bool g_backup = false;
bool g_no_header = false;

// BOMs
const char g_utf8_bom[] = "\xEF\xBB\xBF";   // UTF-8 BOM
const char g_utf16_be_bom[] = "\xFE\xFF";   // UTF-16 BE BOM
const char g_utf16_le_bom[] = "\xFF\xFE";   // UTF-16 LE BOM

// the header
std::string g_strHeaderLF =
    "// This file is converted by code7bit.\n"
    "// code7bit: https://github.com/katahiromz/code7bit\n"
    "// To revert conversion, please execute \"code7bit -r <file>\".\n";
std::string g_strHeaderCRLF =
    "// This file is converted by code7bit.\r\n"
    "// code7bit: https://github.com/katahiromz/code7bit\r\n"
    "// To revert conversion, please execute \"code7bit -r <file>\".\r\n";

// return value
enum RET
{
    RET_SUCCESS = 0,
    RET_INVALID_ARGUMENT
};

// show version info
void show_version(void)
{
    std::cout <<  "code7bit version 1.5 " __DATE__ " by katahiromz" << std::endl;
}

// show help
void show_help(void)
{
    std::cout <<
        "code7bit --- source code dirty 8-bit characters converter\n"
        "\n"
        "This program converts dirty 8-bit characters in the source file into\n"
        "octal sequences \"\\OOO\" or \"\\uXXXX\", and vice versa.\n"
        "\n"
        "Usage: code7bit [options] file.c ...\n"
        "Options:\n"
        "--help              Show this help.\n"
        "--version           Show version info.\n"
        "-c                  Normal conversion.\n"
        "-r                  Reverse conversion.\n"
        "-v                  Verbose mode.\n"
        "-b                  Create backup for file.\n"
        "-t                  Do test only.\n"
        "-n                  No header added." << std::endl;
}

// option info for getopt_long
struct option opts[] =
{
    { "help", no_argument, NULL, 'h' },
    { "version", no_argument, NULL, 'V' },
    { "convert", no_argument, NULL, 'c' },
    { "reverse", no_argument, NULL, 'r' },
    { "verbose", no_argument, NULL, 'v' },
    { "backup", no_argument, NULL, 'b' },
    { "test", no_argument, NULL, 't' },
    { "no-header", no_argument, NULL, 'n' },
    { NULL, 0, NULL, 0 },
};

// external symbols for getopt_long
extern "C"
{
    extern char *optarg;
    extern int optind, opterr, optopt;
}

// parse the command line
int parse_command_line(int argc, char **argv)
{
    int opt, opt_index;
    std::string arg;

    opterr = 0;  /* NOTE: opterr == 1 is not compatible to getopt_port */

    if (argc <= 1)
    {
        std::cerr << "ERROR: No arguments. Try with --help." << std::endl;
        return RET_INVALID_ARGUMENT;
    }

    while ((opt = getopt_long(argc, argv, "hVcrvbtn", opts, &opt_index)) != -1)
    {
        switch (opt)
        {
        case 'h':   // help
            show_help();
            std::exit(EXIT_SUCCESS);
            break;
        case 'V':   // version
            show_version();
            std::exit(EXIT_SUCCESS);
            break;
        case 'c':   // convert
            g_do_convert = true;
            break;
        case 'r':   // reverse
            g_do_reverse = true;
            break;
        case 'v':   // verbose
            g_verbose = true;
            break;
        case 'b':   // backup
            g_backup = true;
            break;
        case 't':   // test
            g_do_test = true;
            break;
        case 'n':   // no header
            g_no_header = true;
            break;
        default:
            switch (optopt)
            {
            case 0:
                std::cerr << "ERROR: Invalid option." << std::endl;
                break;
            default:
                std::cerr << "ERROR: Invalid option '-" << (char)optopt
                          << "'." << std::endl;
                break;
            }
            return RET_INVALID_ARGUMENT;
        }
    }

    if (g_do_convert && g_do_reverse)
    {
        std::cerr << "ERROR: '-c' and '-r' are exclusive." << std::endl;
        return RET_INVALID_ARGUMENT;
    }
    if (!g_do_convert && !g_do_reverse && !g_do_test)
    {
        std::cerr << "ERROR: Either '-c', '-r' or '-t' should be specified."
                  << std::endl;
        return RET_INVALID_ARGUMENT;
    }

    for (int i = optind; i < argc; ++i)
    {
        g_files.push_back(argv[i]);
    }

    if (g_verbose)
    {
        show_version();
        for (int i = 0; i < argc; ++i)
        {
            std::cout << "argv[" << i << "]: '" << argv[i]
                      << "'" << std::endl;
        }
    }

    return RET_SUCCESS;
}

bool fp_copy(FILE *fp1, FILE *fp2)
{
    char            buffer[512];
    size_t          n;

    while ((n = fread(buffer, sizeof(buffer), 1, fp1)) != 0)
    {
        if (fwrite(buffer, n, 1, fp2) == 0)
            return false;
    }
    return true;
}

bool do_backup(const char *file)
{
    std::string backup_file = file;
    backup_file += BACKUP_SUFFIX;

#ifdef _WIN32
    return !!CopyFileA(file, backup_file.c_str(), FALSE);
#else
    bool ok = false;
    if (FILE *fp1 = fopen(file, "rb"))
    {
        if (FILE *fp2 = fopen(backup_file.c_str(), "wb"))
        {
            ok = fp_copy(fp1, fp2);
            fclose(fp2);
        }
        fclose(fp1);
    }
    if (!ok)
    {
        _unlink(backup_file.c_str());
        std::cerr << file << ": ERROR: Cannot write backup file '"
                  << backup_file << "'." << std::endl;
    }
    return ok;
#endif
}

bool do_delete_backup(const char *file)
{
    std::string backup_file = file;
    backup_file += BACKUP_SUFFIX;

    return _unlink(backup_file.c_str()) == 0;
}

inline bool is_octal(char ch)
{
    return '0' <= ch && ch <= '7';
}

inline bool is_xdigit(char ch)
{
    return ('0' <= ch && ch <= '9') ||
           ('a' <= ch && ch <= 'f') ||
           ('A' <= ch && ch <= 'F');
}

inline int hex_to_num(char ch)
{
    if ('0' <= ch && ch <= '9')
        return ch - '0';
    if ('a' <= ch && ch <= 'f')
        return ch - 'a' + 10;
    if ('A' <= ch && ch <= 'F')
        return ch - 'A' + 10;
    return 0;
}

inline int utf8_next(const char *pch)
{
    char ch = *pch;
    if (ch == 0)
        return 0;
    if ((ch & 0x80) == 0)
        return 1;
    if ((ch & 0xE0) == 0xC0)
        return 2;
    if ((ch & 0xF0) == 0xE0)
        return 3;
    if ((ch & 0xF8) == 0xF0)
        return 4;
    return -1;
}

bool utf8_getch(const char *pch, wchar_t& wch, int& len)
{
    char ch = *pch;
    len = utf8_next(pch);
    if (len <= 0)
        return false;

    switch (len)
    {
    case 1:
        wch = (ch & 0x7F);
        return true;
    case 2:
        wch = ((ch & 0x1F) << 6) | (pch[1] & 0x3F);
        return true;
    case 3:
        wch = ((ch & 0x0F) << 12) | ((pch[1] & 0x3F) << 6) | (pch[2] & 0x3F);
        return true;
    case 4:
        wch = ((ch & 0x03) << 18) | ((pch[1] & 0x3F) << 12) | ((pch[2] & 0x3F) << 6) | (pch[3] & 0x3F);
        return true;
    }

    return false;
}

bool utf8_setch(char *pch, wchar_t wch, int& len)
{
    if (0 <= wch && wch <= 0x007F)
    {
        len = 1;
        *pch = (char)wch;
        return true;
    }
    if (0x0080 <= wch && wch <= 0x07FF)
    {
        len = 2;
        *pch++ = (char)(((wch >> 6) & 0x1F) | 0xC0);
        *pch = (char)((wch & 0x3F) | 0x80);
        return true;
    }
    if (0x0800 <= wch && wch <= 0x0FFF)
    {
        len = 3;
        *pch++ = (char)(((wch >> 12) & 0x0F) | 0xE0);
        *pch++ = (char)(((wch >> 6) & 0x3F) | 0x80);
        *pch = (char)((wch & 0x3F) | 0x80);
        return true;
    }
    if (0x10000 <= wch && wch <= 0x10FFFF)
    {
        len = 4;
        *pch++ = (char)(((wch >> 18) & 0x07) | 0xF0);
        *pch++ = (char)(((wch >> 12) & 0x3F) | 0x80);
        *pch++ = (char)(((wch >> 6) & 0x3F) | 0x80);
        *pch = (char)((wch & 0x3F) | 0x80);
        return true;
    }

    return false;
}

// 8-bit ASCII to 7-bit ASCII
bool do_convert(const char *file, std::string& contents, bool check_only, bool& has_change)
{
    // check BOM
    bool has_utf8_bom = (contents.size() >= 3 && memcmp(&contents[0], g_utf8_bom, 3) == 0);
    bool has_utf16be_bom = (contents.size() >= 2 && memcmp(&contents[0], g_utf16_be_bom, 2) == 0);
    bool has_utf16le_bom = (contents.size() >= 2 && memcmp(&contents[0], g_utf16_le_bom, 2) == 0);

    // UTF-16 is not supported yet.
    if (has_utf16be_bom || has_utf16le_bom)
    {
        std::cerr << file << ": ERROR: UTF-16 is not supported yet." << std::endl;
        return false;
    }

    // UTF-16 is not supported yet.
    for (size_t i = 0; i < contents.size(); ++i)
    {
        if (contents[i] == 0)
        {
            std::cerr << file << ": ERROR: UTF-16 is not supported yet." << std::endl;
            return false;
        }
    }

    // already has octal sequence?
    if (contents.size() > 4)
    {
        size_t line = 1;
        for (size_t i = 0; i < contents.size() - 4; ++i)
        {
            // find "\OOO"
            if (contents[i] == '\\' &&
                is_octal(contents[i + 1]) &&
                is_octal(contents[i + 2]) &&
                is_octal(contents[i + 3]))
            {
                std::cerr << file << " (" << line
                          << "): ERROR: Already has octal sequence." << std::endl;
                return false;
            }
            if (contents[i] == '\\' &&
                contents[i + 1] == 'u' &&
                is_xdigit(contents[i + 2]) &&
                is_xdigit(contents[i + 3]) &&
                is_xdigit(contents[i + 4]) &&
                is_xdigit(contents[i + 5]))
            {
                std::cerr << file << " (" << line
                          << "): ERROR: Already has \\uXXXX sequence." << std::endl;
                break;
            }
            if (contents[i] == '\n')
                ++line;
        }
    }

    // is there any target?
    bool has_target = false;
    for (size_t i = 0; i < contents.size(); ++i)
    {
        if (contents[i] & 0x80)
        {
            has_target = true;
            break;
        }
    }
    if (!has_target)
    {
        std::cerr << file << ": No change." << std::endl;
        return true;
    }
    has_change = true;

    if (check_only)
        return true;

    // delete UTF-8 BOM
    if (has_utf8_bom)
    {
        contents.erase(0, 3);
        std::cerr << file << ": NOTICE: Deleted UTF-8 BOM." << std::endl;
    }

    // convert extended codes into "\\%03o" or "\uXXXX"
    bool in_quote = false, unicode = false;
    size_t line = 1;
    for (size_t i = 0; i < contents.size(); ++i)
    {
        if (in_quote)
        {
            switch (contents[i])
            {
            case '\\':
                ++i;
                break;
            case '"':
                if (contents[i + 1] == '"')
                {
                    ++i;
                }
                else
                {
                    unicode = in_quote = false;
                }
                break;
            }
        }
        else
        {
            switch (contents[i])
            {
            case '"':
                in_quote = true;
                unicode = false;
                break;
            case 'L':
                if (contents[i + 1] == '"')
                {
                    ++i;
                    in_quote = unicode = true;
                }
                break;
            }
        }
        if (contents[i] & 0x80)
        {
            char buf[8];
            if (unicode)
            {
                wchar_t wch;
                int len;
                if (!utf8_getch(&contents[i], wch, len))
                {
                    std::cerr << file << " (" << line
                              << "): ERROR: Invalid UTF-8 code." << std::endl;
                    return false;
                }
                std::sprintf(buf, "\\u%04X", wch);
                contents.replace(i, len, std::string(buf));
                i += 6 - 1;
            }
            else
            {
                std::sprintf(buf, "\\%03o", (int)(unsigned char)contents[i]);
                contents.replace(i, 1, std::string(buf));
                i += 4 - 1;
            }
        }
        if (contents[i] == '\n')
        {
            if (in_quote)
            {
                std::cerr << file << " (" << line
                          << "): WARNING: Newline without ending quote." << std::endl;
            }
            unicode = in_quote = false;
            ++line;
        }
    }

    // delete header
    if (contents.size() >= g_strHeaderLF.size() &&
        memcmp(&contents[0], &g_strHeaderLF[0], g_strHeaderLF.size()) == 0)
    {
        contents.erase(0, g_strHeaderLF.size());
    }
    else if (contents.size() >= g_strHeaderCRLF.size() &&
             memcmp(&contents[0], &g_strHeaderCRLF[0], g_strHeaderCRLF.size()) == 0)
    {
        contents.erase(0, g_strHeaderCRLF.size());
    }

    // add header
    if (!g_no_header)
    {
        if (contents.find("\r\n") != std::string::npos)
            contents.insert(0, g_strHeaderCRLF);
        else
            contents.insert(0, g_strHeaderLF);
    }

    // do backup
    if (!do_backup(file))
    {
        return false;
    }

    // write to file
    std::ofstream ofs(file, std::ios::out | std::ios::binary);
    if (!ofs.is_open())
    {
        std::cerr << "ERROR: Cannot open '" << file << "'." << std::endl;
        return false;
    }
    ofs.write(contents.c_str(), contents.size());
    ofs.close();

    if (!g_backup)
    {
        // delete backup
        do_delete_backup(file);
    }

    return true;
}

// 7-bit ASCII to 8-bit ASCII
bool do_reverse(const char *file, std::string& contents, bool check_only, bool& has_change)
{
    // check BOM
    bool has_utf8_bom = (contents.size() >= 3 && memcmp(&contents[0], g_utf8_bom, 3) == 0);
    bool has_utf16be_bom = (contents.size() >= 2 && memcmp(&contents[0], g_utf16_be_bom, 2) == 0);
    bool has_utf16le_bom = (contents.size() >= 2 && memcmp(&contents[0], g_utf16_le_bom, 2) == 0);

    // UTF-16 is not supported yet.
    if (has_utf16be_bom || has_utf16le_bom)
    {
        std::cerr << file << ": ERROR: UTF-16 is not supported yet." << std::endl;
        return false;
    }

    // UTF-16 is not supported yet.
    for (size_t i = 0; i < contents.size(); ++i)
    {
        if (contents[i] == 0)
        {
            std::cerr << file << ": ERROR: UTF-16 is not supported yet." << std::endl;
            return false;
        }
    }

    // is there any target?
    bool has_target = false;
    if (contents.size() > 4)
    {
        for (size_t i = 0; i < contents.size() - 4; ++i)
        {
            // find "\OOO" or "\uXXXX"
            if (contents[i] == '\\' &&
                is_octal(contents[i + 1]) &&
                is_octal(contents[i + 2]) &&
                is_octal(contents[i + 3]))
            {
                has_target = true;
                break;
            }
            if (contents[i] == '\\' &&
                contents[i + 1] == 'u' &&
                is_xdigit(contents[i + 2]) &&
                is_xdigit(contents[i + 3]) &&
                is_xdigit(contents[i + 4]) &&
                is_xdigit(contents[i + 5]))
            {
                has_target = true;
                break;
            }
        }
    }
    if (!has_target)
    {
        std::cerr << file << ": No change." << std::endl;
        return true;
    }
    has_change = true;

    if (check_only)
        return true;

    // delete UTF-8 BOM
    if (has_utf8_bom)
    {
        contents.erase(0, 3);
        std::cerr << file << ": NOTICE: Deleted UTF-8 BOM." << std::endl;
    }

    // delete header
    if (contents.size() >= g_strHeaderLF.size() &&
        memcmp(&contents[0], &g_strHeaderLF[0], g_strHeaderLF.size()) == 0)
    {
        contents.erase(0, g_strHeaderLF.size());
    }
    else if (contents.size() >= g_strHeaderCRLF.size() &&
             memcmp(&contents[0], &g_strHeaderCRLF[0], g_strHeaderCRLF.size()) == 0)
    {
        contents.erase(0, g_strHeaderCRLF.size());
    }

    // reverse conversion
    if (contents.size() > 4)
    {
        size_t line = 1;
        for (size_t i = 0; i < contents.size() - 4; ++i)
        {
            // find "\OOO"
            if (contents[i] == '\\' &&
                is_octal(contents[i + 1]) &&
                is_octal(contents[i + 2]) &&
                is_octal(contents[i + 3]))
            {
                char ch = contents[i + 1] - '0';
                ch <<= 3;
                ch |= contents[i + 2] - '0';
                ch <<= 3;
                ch |= contents[i + 3] - '0';
                std::string str;
                str += ch;
                contents.replace(i, 4, str);
                if (!((i + 1) + 4 < contents.size()))
                    break;
            }
            if (contents[i] == '\\' &&
                contents[i + 1] == 'u' &&
                is_xdigit(contents[i + 2]) &&
                is_xdigit(contents[i + 3]) &&
                is_xdigit(contents[i + 4]) &&
                is_xdigit(contents[i + 5]))
            {
                wchar_t wch = hex_to_num(contents[i + 2]);
                wch <<= 4;
                wch |= hex_to_num(contents[i + 3]);
                wch <<= 4;
                wch |= hex_to_num(contents[i + 4]);
                wch <<= 4;
                wch |= hex_to_num(contents[i + 5]);

                char buf[16];
                int len;
                if (!utf8_setch(buf, wch, len))
                {
                    std::cerr << file << " (" << line
                              << "): ERROR: Invalid Unicode code." << std::endl;
                    return false;
                }
                contents.replace(i, 6, std::string(buf, len));
            }
        }
    }

    // do backup
    if (!do_backup(file))
    {
        return false;
    }

    // write to file
    std::ofstream ofs(file, std::ios::out | std::ios::binary);
    if (!ofs.is_open())
    {
        std::cerr << "ERROR: Cannot open '" << file << "'." << std::endl;
        return false;
    }
    ofs.write(contents.c_str(), contents.size());
    ofs.close();

    if (!g_backup)
    {
        // delete backup
        do_delete_backup(file);
    }

    return true;
}

bool do_file(const char *file, bool check_only, bool& has_change)
{
    std::ifstream ifs(file, std::ios::in | std::ios::binary);
    if (!ifs.is_open())
    {
        std::cerr << "ERROR: Cannot open '" << file << "'." << std::endl;
        return false;
    }

    std::string contents;
    contents.assign(std::istreambuf_iterator<char>(ifs),
                    std::istreambuf_iterator<char>());
    ifs.close();

    if (g_do_convert)
    {
        return do_convert(file, contents, check_only, has_change);
    }
    else if (g_do_reverse)
    {
        return do_reverse(file, contents, check_only, has_change);
    }
    else if (g_do_test)
    {
        return do_convert(file, contents, true, has_change);
    }
    return false;
}

int do_it(void)
{
    if (g_verbose)
    {
        for (size_t i = 0; i < g_files.size(); ++i)
        {
            std::cout << "g_files[" << (int)i << "]: '" << g_files[i]
                      << "'" << std::endl;
        }
    }

    if (g_files.empty())
    {
        std::cerr << "ERROR: No files specified.\n";
        return EXIT_FAILURE;
    }

    bool has_change = false;
    for (size_t i = 0; i < g_files.size(); ++i)
    {
        if (!do_file(g_files[i].c_str(), true, has_change))
            return EXIT_FAILURE;
    }

    if (g_do_test)
    {
        std::cerr << "All tests successful." << std::endl;
        return EXIT_SUCCESS;
    }

    if (!has_change)
        return EXIT_SUCCESS;

    bool ok = true;
    for (size_t i = 0; i < g_files.size(); ++i)
    {
        if (!do_file(g_files[i].c_str(), false, has_change))
            ok = false;
    }
    return ok ? EXIT_SUCCESS : EXIT_FAILURE;
}

int main(int argc, char **argv)
{
    if (int ret = parse_command_line(argc, argv))
        return EXIT_FAILURE;

    return do_it();
}
