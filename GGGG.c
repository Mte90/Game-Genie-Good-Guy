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


int main(int argc, char *argv[])
{
    int Lnum;
    int Codes;
    int fd;
    static char Line[200][cSizeOfDefaultString];

    if(argc != 5)
    {
        fprintf(
            stderr,
            "Usage: GGGG <code> <type> <input> <output>\n"
            "\n"
            "Game Genie Code:\n"
            "  0: <offset>:<value> (both in hex, value is 8-bit)\n"
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
        fprintf(stderr, "\n%s: ERROR: Missing some parameters\n", argv[0]);
        exit(1);
    }

    gg_type Type = parse_gg_type(argv[2]);
    if (Type == GG_TYPE_UNKNOWN)
    {
        fprintf(stderr, "%s: %s: unknown system type\n", argv[0], argv[2]);
        exit(1);
    }

    const char* File1 = argv[3];
    const char* File2 = argv[4];
    remove(File2);
    if(!gCopyFile (File1, File2,true))
    {
        fprintf(stderr, "%s: ERROR: ROM doesn't exists\n", argv[0]);
        exit(1);
    }
    Codes = split_normalize_codes(Line, argv[1]);
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
        fprintf(stderr, "%s: Can't open file %s: %s\n", argv[0], File2, strerror(errno));
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
                fprintf(stderr, "%s: ERROR: unable to apply code\n", argv[0]);
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
                fprintf(stderr, "%s: ERROR: unable to apply code\n", argv[0]);
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
                fprintf(stderr, "%s: ERROR: unable to apply code\n", argv[0]);
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
                fprintf(stderr, "%s: ERROR: unable to apply code\n", argv[0]);
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
                fprintf(stderr, "%s: ERROR: unable to apply code\n", argv[0]);
                continue;
            }
        }
    }

    close(fd);
    return 0;   /* End of main program */
}
