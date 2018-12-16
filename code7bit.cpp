// code7bit.cpp --- source code 7-bit converter
// Copyright (C) 2018 Katayama Hirofumi MZ <katayama.hirofumi.mz@gmail.com>.
// This file is public domain software.
// ---
// This program converts full 8-bit characters in the source file to
// octal sequences "\OOO", and vice versa.
//
// NOTE: UTF-16 is not supported yet.

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>       // standard C I/O
#include <string>       // for std::string
#include <vector>       // for std::vector
#include <iostream>     // for std::cout and std::cerr
#include <fstream>      // for std::ifstream and std::ofstream
#include <streambuf>    // for std::istreambuf_iterator
#include <io.h>         // for _unlink

#ifdef _WIN32
    #include <windows.h>
#endif

#ifdef USE_GETOPT_PORT
    #include "getopt.h" // for portable getopt_long
#else
    #include <getopt.h> // for GNU getopt_long
#endif

// global variables
std::vector<std::string> g_files;
bool g_do_convert = false;
bool g_do_reverse = false;
bool g_do_test = false;
bool g_verbose = false;
bool g_backup = false;
bool g_no_header = false;
const char g_utf8_bom[] = "\xEF\xBB\xBF";
const char g_utf16_be_bom[] = "\xFE\xFF";
const char g_utf16_le_bom[] = "\xFF\xFE";

std::string g_strHeader1 =
    "// This file is converted by code7bit.\n"
    "// code7bit: https://github.com/katahiromz/code7bit\n"
    "// To revert conversion, please execute code7bit -r <file>.\n";
std::string g_strHeader2 =
    "// This file is converted by code7bit.\r\n"
    "// code7bit: https://github.com/katahiromz/code7bit\r\n"
    "// To revert conversion, please execute code7bit -r <file>.\r\n";

// return value
enum RET
{
    RET_SUCCESS = 0,
    RET_INVALID_ARGUMENT
};

// show version info
void show_version(void)
{
    std::cout << 
        "######################################\n"
        "# code7bit version 1.0 by katahiromz #\n"
        "######################################" << std::endl;
}

// show help
void show_help(void)
{
    std::cout <<
        "code7bit --- source code 7-bit converter\n"
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
        std::cerr << "ERROR: Either '-c', '-r' or '-t' should be specified." << std::endl;
        return RET_INVALID_ARGUMENT;
    }

    for (int i = optind; i < argc; ++i)
    {
        g_files.push_back(argv[i]);
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
    backup_file += ".bak";

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
    backup_file += ".bak";

    return _unlink(backup_file.c_str()) == 0;
}

inline bool is_octal(char ch)
{
    return '0' <= ch && ch <= '7';
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
        for (size_t i = 0; i < contents.size() - 4; ++i)
        {
            // find "\OOO"
            if (contents[i] == '\\' &&
                is_octal(contents[i + 1]) &&
                is_octal(contents[i + 2]) &&
                is_octal(contents[i + 3]))
            {
                std::cerr << file << ": ERROR: Already has octal sequence." << std::endl;
                return false;
            }
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

    // convert extended codes into "\\%03o"
    for (size_t i = 0; i < contents.size(); ++i)
    {
        if (contents[i] & 0x80)
        {
            char buf[8];
            std::sprintf(buf, "\\%03o", (int)(unsigned char)contents[i]);
            contents.replace(i, 1, std::string(buf));
            i += 4 - 1;
        }
    }

    // delete header
    if (contents.size() >= g_strHeader1.size() &&
        memcmp(&contents[0], &g_strHeader1[0], g_strHeader1.size()) == 0)
    {
        contents.erase(0, g_strHeader1.size());
    }
    else if (contents.size() >= g_strHeader2.size() &&
             memcmp(&contents[0], &g_strHeader2[0], g_strHeader2.size()) == 0)
    {
        contents.erase(0, g_strHeader2.size());
    }

    // add header
    if (!g_no_header)
    {
        if (contents.find("\r\n") != std::string::npos)
            contents.insert(0, g_strHeader2);
        else
            contents.insert(0, g_strHeader1);
    }

    // do backup
    if (g_backup && !do_backup(file))
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

    // delete backup
    do_delete_backup(file);

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
            // find "\OOO"
            if (contents[i] == '\\' &&
                is_octal(contents[i + 1]) &&
                is_octal(contents[i + 2]) &&
                is_octal(contents[i + 3]))
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
    if (contents.size() >= g_strHeader1.size() &&
        memcmp(&contents[0], &g_strHeader1[0], g_strHeader1.size()) == 0)
    {
        contents.erase(0, g_strHeader1.size());
    }
    else if (contents.size() >= g_strHeader2.size() &&
             memcmp(&contents[0], &g_strHeader2[0], g_strHeader2.size()) == 0)
    {
        contents.erase(0, g_strHeader2.size());
    }

    // reverse conversion
    if (contents.size() > 4)
    {
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
        }
    }

    // do backup
    if (g_backup && !do_backup(file))
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

    // delete backup
    do_delete_backup(file);

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
        show_version();

        std::cout << "non-option arguments:" << std::endl;
        for (size_t i = 0; i < g_files.size(); ++i)
        {
            std::cout << "g_files[" << (int)i << "]: " << g_files[i] << std::endl;
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
