// *********************************************************************
//  Created with UbxBasic - BASIC To C++ Translator (V) 1.0.4.7 (2016/05/01)
// ----------------------------------------------------------------------
//                 BCX (c) 1999 - 2009 by Kevin Diggins
// *********************************************************************
//              Translated for compiling with a C Compiler
//                            On a nix OS
// *********************************************************************
#include <ctype.h>      // dos/linux
#include <fcntl.h>      // dos/linux
#include <stdint.h>
#include <stdio.h>      // dos/linux
#include <string.h>     // dos/linux
#include <strings.h>
#include <stddef.h>     // dos/linux
#include <stdlib.h>     // dos/linux
#include <stdarg.h>     // dos/linux
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>    // linux only
#include <unistd.h>     // linux only

#include "copyfile.h"
#include "decode.h"

// ***************************************************
// Compiler Defines
// ***************************************************

// *************************************************
//        User's GLOBAL ENUM blocks
// *************************************************

typedef enum
{
    GG_TYPE_UNKNOWN = -1,
    GG_TYPE_RAW = 0,
    GG_TYPE_GBGGMS,
    GG_TYPE_GENESIS,
    GG_TYPE_NES,
    GG_TYPE_SNES,
} gg_type;

// *************************************************
//            System Defined Constants
// *************************************************

size_t  g_dum1_;  // dummy var for not used returns
#define cSizeOfDefaultString 2048

// *************************************************
//            User Defined Constants
// *************************************************


// *************************************************
//               Standard Prototypes
// *************************************************

char* BCX_TmpStr(size_t, size_t , int );
char*   chr(int);
off_t   lof (const char*);

// *************************************************
//                System Variables
// *************************************************

// *************************************************
//          User Defined Types And Unions
// *************************************************

// *************************************************
//            User Global Variables
// *************************************************

// *************************************************
//               Standard Macros
// *************************************************

#define GET(A,B,C)g_dum1_= fread(B,1,C,A)
#define PUT(A,B,C)g_dum1_= fwrite(B,1,C,A)


// *************************************************
//            User Global Initialized Arrays
// *************************************************



// *************************************************
//                 Runtime Functions
// *************************************************

#define streq(a, b) (strcmp(a, b) == 0)

#ifndef BCXTmpStrSize
#define BCXTmpStrSize  2048
#endif
char *BCX_TmpStr (size_t Bites, size_t  iPad, int iAlloc)
{
    static int   StrCnt;
    static char *StrFunc[BCXTmpStrSize];
    StrCnt = (StrCnt + 1) & (BCXTmpStrSize - 1);
    if(StrFunc[StrCnt]) {
        free (StrFunc[StrCnt]);
        StrFunc[StrCnt] = NULL;
    }
#if defined BCX_MAX_VAR_SIZE
    if(Bites * sizeof(char) > BCX_MAX_VAR_SIZE)
    {
        printf("Buffer Overflow caught in BCX_TmpStr - requested space of %d EXCEEDS %d\n", (int)(Bites * sizeof(char)), BCX_MAX_VAR_SIZE);
        abort();
    }
#endif
    if(iAlloc) StrFunc[StrCnt] = (char*)calloc(Bites + iPad + 1, sizeof(char));
    return StrFunc[StrCnt];
}


char *chr (int a)
{
    char *strtmp = BCX_TmpStr(2, 1, 1);
    strtmp[0]  = a;
    return strtmp;
}


off_t lof (const char * FileName)
{
    int retstat;
    struct stat sb;
    retstat = stat(FileName, &sb);
    if(retstat != -1)
        return sb.st_size;
    return 0;
}


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


// ************************************
//       User Subs and Functions
// ************************************

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

// *************************************************
//                  Main Program
// *************************************************

int main(int argc, char *argv[])
{
    int Lnum, Num;
    int Cmp, Off, Rep;
    int Codes;
    FILE *FP2;
    unsigned char c;
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
    if((FP2 = fopen(File2, "rb+")) == 0)
    {
        fprintf(stderr, "%s: Can't open file %s\n", argv[0], File2);
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
            Off = decoded.off;
            Cmp = decoded.cmp;
            Rep = decoded.rep;

            if(ext && (strcasecmp(ext, "pce") == 0 || (strcasecmp(ext, "sms") == 0 && lof(File1) % 1024)))
            {
                Off +=   512;
            }
            if(Off < lof(File1))
            {
                fseek(FP2, Off, 0);
                PUT(FP2, chr(Rep), 1 );
                printf("%s\n", Line[Lnum]);
            }
        }
        if (Type == GG_TYPE_GBGGMS)
        {
            if (!decodeGbGgMs(Code, &decoded))
            {
                continue;
            }
            Off = decoded.off;
            Cmp = decoded.cmp;
            Rep = decoded.rep;

            if(decoded.len == 6)
            {
                for(Num = 0; Num <= lof(File1) / 8192; Num += 1)
                {
                    if(Off < lof(File1))
                    {
                        fseek(FP2, Off, 0);
                        PUT(FP2, chr(Rep), 1 );
                        printf("%s - %X:%X:%X\n", Line[Lnum], Off, Cmp, Rep);
                    }
                    Off +=   8192;
                }

            }
            if(decoded.len == 9)
            {
                for(Num = 0; Num <= lof(File1) / 8192; Num += 1)
                {
                    if(Off < lof(File1))
                    {
                        fseek(FP2, Off, 0);
                        GET(FP2, &c, 1 );
                        if (c == Cmp)
                        {
                            fseek(FP2, Off, 0);
                            PUT(FP2, chr(Rep), 1 );
                            printf("%s - %X:%X:%X\n", Line[Lnum], Off, Cmp, Rep);
                        }
                    }
                    Off +=   8192;
                }

            }
        }
        if (Type == GG_TYPE_GENESIS)
        {
            if (!decodeGenesis(Code, &decoded))
            {
                continue;
            }
            Off = decoded.off;
            Cmp = decoded.cmp;
            Rep = decoded.rep;

            if(Off < lof(File1))
            {
                fseek(FP2, Off, 0);
                PUT(FP2, chr(Rep >> 8), 1 );
                fseek(FP2, Off + 1, 0);
                PUT(FP2, chr(Rep & 0xff), 1 );
                printf("%s - %X:%X\n", Line[Lnum], Off, Rep);
            }
        }
        if (Type == GG_TYPE_NES)
        {
            if (!decodeNES(Code, &decoded))
            {
                continue;
            }
            Off = decoded.off + 0x8000 - 0xc000;
            Cmp = decoded.cmp;
            Rep = decoded.rep;

            if(decoded.len == 6)
            {
                if(lof(File1) % 1024 != 0 )
                {
                    Off +=   16;
                }
                if(lof(File1) >= 49169 )
                {
                    for(Num = 0; Num <= lof(File1) / 8192; Num += 1)
                    {
                        if(Off < lof(File1))
                        {
                            fseek(FP2, Off, 0);
                            PUT(FP2, chr(Rep), 1 );
                            printf("%s - %X:%X:%X\n", Line[Lnum], Off, Cmp, Rep);
                        }
                        Off +=   8192;
                    }

                }
                else
                {
                    fseek(FP2, Off, 0);
                    PUT(FP2, chr(Rep), 1 );
                    printf("%s - %X:%X:%X\n", Line[Lnum], Off, Cmp, Rep);
                }
            }
            if(decoded.len == 8)
            {
                if(lof(File1) % 1024 != 0 )
                {
                    Off +=   16;
                }
                for(Num = 0; Num <= lof(File1) / 8192; Num += 1)
                {
                    if(Off < lof(File1))
                    {
                        fseek(FP2, Off, 0);
                        GET(FP2, &c, 1);
                        if (c == Cmp)
                        {
                            fseek(FP2, Off, 0);
                            PUT(FP2, chr(Rep), 1 );
                            printf("%s - %X:%X:%X\n", Line[Lnum], Off, Cmp, Rep);
                        }
                    }
                    Off +=   8192;
                }

            }
        }
        if (Type == GG_TYPE_SNES)
        {
            if (!decodeSNES(Code, &decoded))
            {
                continue;
            }
            Off = decoded.off;
            Cmp = decoded.cmp;
            Rep = decoded.rep;

            if(lof(File1) % 1024 != 0 )
            {
                Off +=   512;
            }
            Num = 65493;
            if(lof(File1) % 1024 != 0 )
            {
                Num +=   512;
            }
            fseek(FP2, Num, 0);
            GET(FP2, &c, 1 );
            if (c != 33 && c != 49)
            {
                Off = ((Off & 0xff000000) >> 9) | (Off & 0x7fff);
            }
            if(Off >= 4194304 && Off <= 8388607 )
            {
                Off -=   4194304;
            }
            if(Off >= 8388608 && Off <= 12582911 )
            {
                Off -=   8388608;
            }
            if(Off >= 12582912 && Off <= 16777215 )
            {
                Off -=   12582912;
            }
            if(Off < lof(File1))
            {
                fseek(FP2, Off, 0);
                PUT(FP2, chr(Rep), 1 );
                printf("%s - %X:%X\n", Line[Lnum], Off, Rep);
            }
        }
    }

    if(FP2)
    {
        fclose(FP2);
        FP2 = NULL;
    }
    return 0;   /* End of main program */
}
