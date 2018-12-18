// code7bit.cpp --- source code non-clean 8-bit characters converter
// Copyright (C) 2018 Katayama Hirofumi MZ <katayama.hirofumi.mz@gmail.com>.
// This file is public domain software.
// ---
// This program converts non-clean 8-bit characters in the source file into
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
#include <cassert>      // for assert

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

// show version info
void show_version(void)
{
    std::cout <<  "code7bit version 1.9 " __DATE__ " by katahiromz" << std::endl;
}

// show help
void show_help(void)
{
    std::cout <<
        "code7bit --- source code non-clean 8-bit characters converter\n"
        "\n"
        "This program converts non-clean 8-bit characters in the source file into\n"
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
bool parse_command_line(int argc, char **argv)
{
    int opt, opt_index;
    std::string arg;

    opterr = 0;  /* NOTE: opterr == 1 is not compatible to getopt_port */

    if (argc <= 1)
    {
        std::cerr << "ERROR: No arguments. Try with --help." << std::endl;
        return false;
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
            return false;
        }
    }

    if (g_do_convert && g_do_reverse)
    {
        std::cerr << "ERROR: '-c' and '-r' are exclusive." << std::endl;
        return false;
    }

    if (!g_do_convert && !g_do_reverse && !g_do_test)
    {
        std::cerr << "ERROR: Either '-c', '-r' or '-t' should be specified."
                  << std::endl;
        return false;
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

    return true;
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

#ifdef _WIN32
    return !!DeleteFileA(backup_file.c_str());
#else
    return _unlink(backup_file.c_str()) == 0;
#endif
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

inline unsigned int hex_to_num(char ch)
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

bool utf8_getch(const char *pch, unsigned int& wch, int& len)
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
        wch = ((ch & 0x03) << 18) | ((pch[1] & 0x3F) << 12) | \
              ((pch[2] & 0x3F) << 6) | (pch[3] & 0x3F);
        return true;
    }

    return false;
}

bool utf8_setch(char *pch, unsigned int wch, int& len)
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
    if (0x0800 <= wch && wch <= 0xFFFF)
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
    len = 0;
    return false;
}

bool is_3digit_octal_sequence(const std::string& contents, size_t i)
{
    if (i + 4 <= contents.size() &&
        contents[i] == '\\' &&
        is_octal(contents[i + 1]) &&
        is_octal(contents[i + 2]) &&
        is_octal(contents[i + 3]))
    {
        return true;
    }
    return false;
}

bool convert_3digit_octal_sequence(std::string& contents, size_t i,
                                   const char *file, size_t line)
{
    assert(contents[i] == '\\');
    char ch = contents[i + 1] - '0';
    ch <<= 3;
    ch |= contents[i + 2] - '0';
    ch <<= 3;
    ch |= contents[i + 3] - '0';
    std::string str;
    str += ch;
    contents.replace(i, 4, str);
    return true;
}

bool is_4digit_ucn_sequence(const std::string& contents, size_t i)
{
    if (i + 6 <= contents.size() &&
        contents[i] == '\\' && contents[i + 1] == 'u' &&
        is_xdigit(contents[i + 2]) &&
        is_xdigit(contents[i + 3]) &&
        is_xdigit(contents[i + 4]) &&
        is_xdigit(contents[i + 5]))
    {
        return true;
    }
    return false;
}

bool convert_4digit_ucn_sequence(std::string& contents, size_t& i,
                                 const char *file, size_t line)
{
    assert(contents[i] == '\\');
    assert(contents[i + 1] == 'u');

    unsigned int wch;
    wch = hex_to_num(contents[i + 2]);
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
        assert(0);
        return false;
    }

    contents.replace(i, 6, std::string(buf, len));
    i += len - 1;
    return true;
}

bool is_8digit_ucn_sequence(const std::string& contents, size_t i)
{
    if (i + 10 <= contents.size() &&
        contents[i] == '\\' && contents[i + 1] == 'U' &&
        is_xdigit(contents[i + 2]) &&
        is_xdigit(contents[i + 3]) &&
        is_xdigit(contents[i + 4]) &&
        is_xdigit(contents[i + 5]) &&
        is_xdigit(contents[i + 6]) &&
        is_xdigit(contents[i + 7]) &&
        is_xdigit(contents[i + 8]) &&
        is_xdigit(contents[i + 9]))
    {
        return true;
    }
    return false;
}

bool convert_8digit_ucn_sequence(std::string& contents, size_t& i,
                                 const char *file, size_t line)
{
    assert(contents[i] == '\\');
    assert(contents[i + 1] == 'U');

    unsigned int wch;
    wch = hex_to_num(contents[i + 2]);
    wch <<= 4;
    wch |= hex_to_num(contents[i + 3]);
    wch <<= 4;
    wch |= hex_to_num(contents[i + 4]);
    wch <<= 4;
    wch |= hex_to_num(contents[i + 5]);
    wch <<= 4;
    wch |= hex_to_num(contents[i + 6]);
    wch <<= 4;
    wch |= hex_to_num(contents[i + 7]);
    wch <<= 4;
    wch |= hex_to_num(contents[i + 8]);
    wch <<= 4;
    wch |= hex_to_num(contents[i + 9]);

    char buf[32];
    int len;
    if (!utf8_setch(buf, wch, len))
    {
        std::cerr << file << " (" << line
                  << "): ERROR: Invalid Unicode code." << std::endl;
        assert(0);
        return false;
    }

    contents.replace(i, 6, std::string(buf, len));
    i += len - 1;
    return true;
}

bool convert_utf8_chars(std::string& contents, size_t& i,
                        const char *file, size_t line)
{
    int len;
    char buf[16];
    unsigned int wch;

    assert(contents[i] & 0x80);

    if (!utf8_getch(&contents[i], wch, len))
    {
        std::cerr << file << " (" << line
                  << "): ERROR: Invalid UTF-8 code." << std::endl;
        assert(0);
        return false;
    }

    if (wch > 0xFFFF)
    {
        std::sprintf(buf, "\\U%08X", wch);
    }
    else
    {
        std::sprintf(buf, "\\u%04X", wch);
    }

    contents.replace(i, len, std::string(buf));
    i += strlen(buf) - 1;
    return true;
}

bool convert_to_octal(std::string& contents, size_t& i,
                      const char *file, size_t line)
{
    char buf[16];
    std::sprintf(buf, "\\%03o", (int)(unsigned char)contents[i]);
    contents.replace(i, 1, std::string(buf));
    i += strlen(buf) - 1;
    return true;
}

bool
do_convert_contents(const char *file, std::string& contents,
                    bool reverse, bool& has_change)
{
    size_t line = 1;
    enum MODE
    {
        MODE_INITIAL, MODE_C_COMMENT, MODE_CXX_COMMENT,
        MODE_SINGLE_QUOTE, MODE_DOUBLE_QUOTE
    } mode = MODE_INITIAL;
    bool unicode = false;

    for (size_t i = 0; i < contents.size(); ++i)
    {
        const char *psz = contents.c_str();
        bool check_raw = false;

        //std::cout << line << ": " << mode << ":" <<
        //             psz[i] << ":" << check_raw << std::endl;

        if (mode == MODE_C_COMMENT)   // in C-style comment
        {
            if (psz[i] == '*' && psz[i + 1] == '/')
            {
                mode = MODE_INITIAL;
                ++i;
            }
        }
        else if (mode == MODE_CXX_COMMENT)    // in C++ comment
        {
            if (psz[i] == '\n')
            {
                mode = MODE_INITIAL;
            }
        }
        else if (mode == MODE_SINGLE_QUOTE)   // in '...'
        {
            if (reverse && (psz[i] & 0x80))
            {
                // non-clean character found!
                std::cerr << file << " (" << line
                          << "): ERROR: Already non-clean character exists "
                             "in single quote. Unable to revert."
                          << std::endl;
                return false;
            }
            if (psz[i] == '\\')
            {
                if (reverse)    // reverse conversion
                {
                    if (unicode)
                    {
                        if (is_4digit_ucn_sequence(contents, i))
                        {
                            has_change = true;
                            if (!convert_4digit_ucn_sequence(contents, i, file, line))
                            {
                                return false;
                            }
                        }
                        else if (is_8digit_ucn_sequence(contents, i))
                        {
                            has_change = true;
                            if (!convert_8digit_ucn_sequence(contents, i, file, line))
                                return false;
                        }
                        else
                        {
                            // skip escaped character
                            ++i;
                        }
                    }
                    else    // non-Unicode
                    {
                        if (is_3digit_octal_sequence(contents, i))
                        {
                            has_change = true;
                            if (!convert_3digit_octal_sequence(contents, i, file, line))
                                return false;
                        }
                        else
                        {
                            // skip escaped character
                            ++i;
                        }
                    }
                }
                else    // normal conversion
                {
                    if (unicode)
                    {
                        if (is_4digit_ucn_sequence(contents, i))
                        {
                            std::cerr << file << " (" << line
                                      << "): ERROR: Already 4-digit UCN sequence exists "
                                         "in double quote. Unablet to convert."
                                      << std::endl;
                            return false;
                        }
                        else if (is_8digit_ucn_sequence(contents, i))
                        {
                            std::cerr << file << " (" << line
                                      << "): ERROR: Already 8-digit UCN sequence exists "
                                         "in double quote. Unablet to convert."
                                      << std::endl;
                            return false;
                        }
                        // skip escaped character
                        ++i;
                    }
                    else    // non-Unicode
                    {
                        if (is_3digit_octal_sequence(contents, i))
                        {
                            std::cerr << file << " (" << line
                                      << "): ERROR: Already 3-digit octal sequence exists "
                                         "in double quote. Unablet to convert."
                                      << std::endl;
                            return false;
                        }
                        else
                        {
                            // skip escaped character
                            ++i;
                        }
                    }
                }
            }
            else if (psz[i] == '\'')
            {
                unicode = false;
                mode = MODE_INITIAL;
            }
            else if (psz[i] & 0x80)
            {
                check_raw = true;
            }
        }
        else if (mode == MODE_DOUBLE_QUOTE)   // in "..."
        {
            if (reverse && (psz[i] & 0x80))
            {
                // non-clean character found!
                std::cerr << file << " (" << line
                          << "): ERROR: Already non-clean character exists "
                             "in double quote. Unable to revert."
                          << std::endl;
                return false;
            }
            if (psz[i] == '\\')
            {
                if (reverse)    // reverse conversion
                {
                    if (unicode)
                    {
                        if (is_4digit_ucn_sequence(contents, i))
                        {
                            has_change = true;
                            if (!convert_4digit_ucn_sequence(contents, i, file, line))
                                return false;
                        }
                        else if (is_8digit_ucn_sequence(contents, i))
                        {
                            has_change = true;
                            if (!convert_8digit_ucn_sequence(contents, i, file, line))
                                return false;
                        }
                    }
                    else    // non-Unicode
                    {
                        if (is_3digit_octal_sequence(contents, i))
                        {
                            has_change = true;
                            if (!convert_3digit_octal_sequence(contents, i, file, line))
                                return false;
                        }
                        else
                        {
                            // skip escaped character
                            ++i;
                        }
                    }
                }
                else    // normal conversion
                {
                    if (unicode)
                    {
                        if (is_4digit_ucn_sequence(contents, i))
                        {
                            std::cerr << file << " (" << line
                                      << "): ERROR: Already 4-digit UCN sequence exists "
                                         "in single quote. Unablet to convert."
                                      << std::endl;
                            return false;
                        }
                        else if (is_8digit_ucn_sequence(contents, i))
                        {
                            std::cerr << file << " (" << line
                                      << "): ERROR: Already 8-digit UCN sequence exists "
                                         "in single quote. Unablet to convert."
                                      << std::endl;
                            return false;
                        }
                        else
                        {
                            // skip escaped character
                            ++i;
                        }
                    }
                    else    // non-Unicode
                    {
                        if (is_3digit_octal_sequence(contents, i))
                        {
                            std::cerr << file << " (" << line
                                      << "): ERROR: Already 3-digit octal sequence exists "
                                         "in single quote. Unablet to convert."
                                      << std::endl;
                            return false;
                        }
                        else
                        {
                            // skip escaped character
                            ++i;
                        }
                    }
                }
            }
            else if (psz[i] == '"')
            {
                if (psz[i + 1] == '"')
                {
                    // double double quotation!
                    ++i;
                }
                else
                {
                    unicode = false;
                    mode = MODE_INITIAL;
                }
            }
            else if (psz[i] & 0x80)
            {
                check_raw = true;
            }
        }
        else    // otherwise
        {
            assert(mode == MODE_INITIAL);
            if (psz[i] == '/' && psz[i + 1] == '*')
            {
                // beginning of C-style comment
                mode = MODE_C_COMMENT;
                ++i;
            }
            else if (psz[i] == '/' && psz[i + 1] == '/')
            {
                // beginning of C++ comment
                mode = MODE_CXX_COMMENT;
                ++i;
            }
            else if (psz[i] == '\'')
            {
                // beginning of '...'
                mode = MODE_SINGLE_QUOTE;
                unicode = false;
            }
            else if (psz[i] == '"')
            {
                // beginning of "..."
                mode = MODE_DOUBLE_QUOTE;
                unicode = false;
            }
            else if (psz[i] == 'L' && psz[i + 1] == '\'')
            {
                // beginning of L'...'
                mode = MODE_SINGLE_QUOTE;
                unicode = true;
                ++i;
            }
            else if (psz[i] == 'L' && psz[i + 1] == '"')
            {
                // beginning of L"..."
                mode = MODE_DOUBLE_QUOTE;
                unicode = true;
                ++i;
            }
            else if (psz[i] & 0x80)
            {
                check_raw = true;
            }
        }

        if (check_raw && (psz[i] & 0x80))   // found non-clean character!
        {
            has_change = true;
            if (unicode)
            {
                if (!convert_utf8_chars(contents, i, file, line))
                    return false;
            }
            else
            {
                if (!convert_to_octal(contents, i, file, line))
                    return false;
            }
        }

        if (contents[i] == '\n')    // newline
        {
            ++line;
            if (mode == MODE_CXX_COMMENT)
                mode = MODE_INITIAL;
        }
    }

    return true;
}

bool do_convert(const char *file, std::string& contents, bool reverse, bool check_only, bool& has_change)
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
    for (size_t i = 0; i < contents.size(); ++i)
    {
        if (contents[i] == 0)
        {
            std::cerr << file << ": ERROR: UTF-16 is not supported yet." << std::endl;
            return false;
        }
    }

    // do convert contents
    has_change |= has_utf8_bom;
    if (!do_convert_contents(file, contents, reverse, has_change))
    {
        return false;
    }

    if (!has_change)
    {
        std::cerr << file << ": No change." << std::endl;
        return true;
    }

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

    if (!reverse)
    {
        // add header
        if (!g_no_header)
        {
            if (contents.find("\r\n") != std::string::npos)
                contents.insert(0, g_strHeaderCRLF);
            else
                contents.insert(0, g_strHeaderLF);
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

    if (reverse)
        std::cerr << file << ": Reverted." << std::endl;
    else
        std::cerr << file << ": Converted." << std::endl;

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
        return do_convert(file, contents, false, check_only, has_change);
    }
    else if (g_do_reverse)
    {
        return do_convert(file, contents, true, check_only, has_change);
    }
    else if (g_do_test)
    {
        return do_convert(file, contents, g_do_reverse, check_only, has_change);
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
    std::vector<bool> changed_flags;
    for (size_t i = 0; i < g_files.size(); ++i)
    {
        bool flag = false;
        if (!do_file(g_files[i].c_str(), true, flag))
            return EXIT_FAILURE;

        if (flag)
            has_change = true;

        changed_flags.push_back(flag);
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
        if (changed_flags[i])
        {
            has_change = false;
            if (!do_file(g_files[i].c_str(), false, has_change))
                ok = false;
        }
    }
    return ok ? EXIT_SUCCESS : EXIT_FAILURE;
}

int main(int argc, char **argv)
{
    if (!parse_command_line(argc, argv))
        return EXIT_FAILURE;

    return do_it();
}
