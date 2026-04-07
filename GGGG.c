// *********************************************************************
//  Created with UbxBasic - BASIC To C++ Translator (V) 1.0.4.7 (2016/05/01)
// ----------------------------------------------------------------------
//                 BCX (c) 1999 - 2009 by Kevin Diggins
// *********************************************************************
//              Translated for compiling with a C Compiler
//                            On a nix OS
// *********************************************************************
#include <ctype.h>      // dos/linux
#include <errno.h>
#include <fcntl.h>      // dos/linux
#include <stdint.h>
#include <stdio.h>      // dos/linux
#include <string.h>     // dos/linux
#include <stddef.h>     // dos/linux
#include <stdlib.h>     // dos/linux
#include <stdbool.h>    // linux only
#include <unistd.h>     // linux only

#include "copyfile.h"
#include "decode.h"
#include "modify.h"

#define VERSION "2.0"

typedef enum
{
    GG_TYPE_UNKNOWN = -1,
    GG_TYPE_RAW = 0,
    GG_TYPE_GBGGMS,
    GG_TYPE_GENESIS,
    GG_TYPE_NES,
    GG_TYPE_SNES,
} gg_type;

#define cSizeOfDefaultString 2048

#define streq(a, b) (strcmp(a, b) == 0)


static int split_normalize_codes(char Buf[][cSizeOfDefaultString], char *T)
{
    int count = 0;
    char *token;
    token = strtok(T, "+\n");
    do
    {
        char *out = Buf[count++];
        while (*token)
        {
            if (*token != '-' && !isspace(*token))
            {
                *out = toupper(*token);
                ++out;
            }
            ++token;
        }
        *out = '\0';
    } while((token = strtok(NULL, "+\n")) != NULL);
    return count;
}


static gg_type parse_gg_type(const char *type)
{
    if (streq(type, "0") || streq(type, "raw"))
    {
        return GG_TYPE_RAW;
    }

    if (streq(type, "1") || streq(type, "gb") || streq(type, "gg") || streq(type, "ms"))
    {
        return GG_TYPE_GBGGMS;
    }

    if (streq(type, "2") || streq(type, "genesis") || streq(type, "md") || streq(type, "megadrive"))
    {
        return GG_TYPE_GENESIS;
    }

    if (streq(type, "3") || streq(type, "nes"))
    {
        return GG_TYPE_NES;
    }

    if (streq(type, "4") || streq(type, "snes"))
    {
        return GG_TYPE_SNES;
    }

    return GG_TYPE_UNKNOWN;
}


static void usage(bool error)
{
    fprintf(
        error ? stderr : stdout,
        "Usage: GGGG [options] <code> <type> <input> [output]\n"
        "\n"
        "Options:\n"
        "  -i   Update <input> inplace, otherwise write to <output>\n"
        "  -V   Show version information\n"
        "\n"
        "Game Genie Code:\n"
        "  0: <offset>:<value> (both in hex, value is 8-bit)\n"
        "     <offset>=<value> (higan format)\n"
        "     <offset>=<compare>?<value>\n"
        "  1: XXX-XXX or XXX-XXX-XXX\n"
        "  2: XXXX-XXXX\n"
        "  3: XXXXXX or XXXXXXXX\n"
        "  4: XXXX-XXXX\n"
        "\n"
        "System Type:\n"
        "  0: Raw dump\n"
        "  1: Game Boy/Game Gear/Master System\n"
        "  2: Genesis/Mega Drive\n"
        "  3: Nintendo\n"
        "  4: Super Nintendo\n"
        "\n"
        "Input: A valid ROM file for the <type> system.\n"
        "Output: The file will be removed and patched.\n");
}


int main(int argc, char *argv[])
{
    int Lnum;
    int Codes;
    int fd;
    int o;
    bool inplace = false;
    const char *program = argv[0];
    static char Line[200][cSizeOfDefaultString];

    while ((o = getopt(argc, argv, "hiV")) != -1)
    {
        switch (o)
        {
            case 'h':
                usage(false);
                return 0;
            case 'i':
                inplace = true;
                break;
            case 'V':
                printf("GGGG %s\n", VERSION);
                return 0;
            case '?':
                // Don't output anything -- getopt already did.
                return 1;
        }
    }

    if ((argc - optind) != (inplace ? 3 : 4))
    {
        usage(true);
        fprintf(stderr, "\n%s: ERROR: Missing some parameters\n", program);
        return 1;
    }

    char *argv_codes = argv[optind];
    const char *argv_system = argv[optind + 1];
    const char *argv_input = argv[optind + 2];
    const char *argv_output = inplace ? argv_input : argv[optind + 3];

    gg_type Type = parse_gg_type(argv_system);
    if (Type == GG_TYPE_UNKNOWN)
    {
        fprintf(stderr, "%s: %s: unknown system type\n", program, argv_system);
        exit(1);
    }

    const char* File1 = argv_input;
    const char* File2 = argv_output;
    if (!inplace)
    {
        remove(File2);
        if (!gCopyFile (File1, File2,true))
        {
            fprintf(stderr, "%s: ERROR: ROM doesn't exists\n", program);
            return 1;
        }
    }

    Codes = split_normalize_codes(Line, argv_codes);
    printf("Codes to inject: %i\n", Codes);
    const char* ext = strrchr(File1, '.');
    if (ext)
    {
        ext++;
    }
    printf("ROM to patch: %s\n", File1);
    printf("Patch at: %s\n", File2);
    if ((fd = open(File2, O_RDWR)) < 0)
    {
        fprintf(stderr, "%s: Can't open file %s: %s\n", program, File2, strerror(errno));
        exit(1);
    }
    printf("\nLog:\n");
    for(Lnum = 0; Lnum < Codes; Lnum += 1)
    {
        struct codebits decoded;
        const char *Code = Line[Lnum];

        printf("Parsing code: %s\n", Code);
        if (Type == GG_TYPE_RAW)
        {
            if (!decodeRaw(Code, &decoded))
            {
                continue;
            }
            printf("%s - %X:%X\n", Line[Lnum], decoded.off, decoded.rep);
            if (!modifyRaw(fd, ext, &decoded))
            {
                fprintf(stderr, "%s: ERROR: unable to apply code\n", program);
                continue;
            }
        }
        if (Type == GG_TYPE_GBGGMS)
        {
            if (!decodeGbGgMs(Code, &decoded))
            {
                continue;
            }
            printf("%s - %X:%X\n", Line[Lnum], decoded.off, decoded.rep);
            if (!modifyGbGgMs(fd, &decoded))
            {
                fprintf(stderr, "%s: ERROR: unable to apply code\n", program);
                continue;
            }
        }
        if (Type == GG_TYPE_GENESIS)
        {
            if (!decodeGenesis(Code, &decoded))
            {
                continue;
            }
            printf("%s - %X:%X\n", Line[Lnum], decoded.off, decoded.rep);
            if (!modifyGenesis(fd, &decoded))
            {
                fprintf(stderr, "%s: ERROR: unable to apply code\n", program);
                continue;
            }
        }
        if (Type == GG_TYPE_NES)
        {
            if (!decodeNES(Code, &decoded))
            {
                continue;
            }
            printf("%s - %X:%X:%X\n", Line[Lnum], decoded.off, decoded.cmp, decoded.rep);
            if (!modifyNES(fd, &decoded))
            {
                fprintf(stderr, "%s: ERROR: unable to apply code\n", program);
                continue;
            }
        }
        if (Type == GG_TYPE_SNES)
        {
            if (!decodeSNES(Code, &decoded))
            {
                continue;
            }
            printf("%s - %X:%X\n", Line[Lnum], decoded.off, decoded.rep);
            if (!modifySNES(fd, &decoded))
            {
                fprintf(stderr, "%s: ERROR: unable to apply code\n", program);
                continue;
            }
        }
    }

    close(fd);
    return 0;   /* End of main program */
}
