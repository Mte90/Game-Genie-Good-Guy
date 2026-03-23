// *********************************************************************
//  Created with UbxBasic - BASIC To C++ Translator (V) 1.0.4.7 (2016/05/01)
// ----------------------------------------------------------------------
//                 BCX (c) 1999 - 2009 by Kevin Diggins
// *********************************************************************
//              Translated for compiling with a C++ Compiler
//                            On a nix OS
// *********************************************************************
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <locale>
#include <algorithm>
#include <vector>
using namespace std;
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
    GG_TYPE_UNKNOWN = 0,
    GG_TYPE_GBGGMS,
    GG_TYPE_GENESIS,
    GG_TYPE_NES,
    GG_TYPE_SNES,
} gg_type;

// *************************************************
//            System Defined Constants
// *************************************************

typedef unsigned char UCHAR;
size_t  g_dum1_;  // dummy var for not used returns
#define cSizeOfDefaultString 2048

// *************************************************
//            User Defined Constants
// *************************************************


// *************************************************
//               Standard Prototypes
// *************************************************

char*   BCX_TmpStr(size_t, size_t = 0, int = 1);
std::string   left (std::string, int);
char*   left (const char*, int);
std::string   right (std::string, int);
char*   right (const char*, int);
char*   lpad (const char*, int, int = 32);
char*   Bin (int);
char*   join (int, ... );
char*   chr(int);
int     Bin2Dec (const char*);
int     Hex2Dec (const char*);
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


std::string left (std::string s, int length)
{
    return s.substr(0, length);
}
char *left (const char *S, int length)
{
    int tmplen = strlen(S);
    if(length < 1) return BCX_TmpStr(1, 0, 1);
    if(length < tmplen) tmplen = length;
    char *strtmp = BCX_TmpStr(tmplen, 1, 1);
    return (char*)memcpy(strtmp, S, tmplen);
}


std::string right (std::string s, int length)
{
    return s.substr(s.length() - length, length);
}
char *right (const char *S, int length)
{
    int tmplen = strlen(S);
    char *BCX_RetStr = BCX_TmpStr(tmplen, 1, 1);
    tmplen -= length;
    if (tmplen < 0) tmplen = 0;
    return strcpy(BCX_RetStr, &S[tmplen]);
}


char *lpad (const char *a, int L, int c)
{
    char *strtmp;
    L = L - strlen(a);
    if(L < 1) return (char*)a;
    strtmp = BCX_TmpStr(L, 1, 1);
    memset(strtmp, c, L);
    return strcat(strtmp, a);
}


char *chr (int a)
{
    char *strtmp = BCX_TmpStr(2, 1, 1);
    strtmp[0]  = a;
    return strtmp;
}


char * join(int n, ...)
{
    int i = n, tmplen = 0;
    char *s_;
    char *strtmp;
    va_list marker;
    va_start(marker, n); // Initialize variable arguments
    while(i-- > 0)
    {
        s_ = va_arg(marker, char *);
        if(s_) tmplen += strlen(s_);
    }
    strtmp = BCX_TmpStr(tmplen, 1, 1);
    va_end(marker); // Reset variable arguments
    i = n;
    va_start(marker, n); // Initialize variable arguments
    while(i-- > 0)
    {
        s_ = va_arg(marker, char *);
        if(s_) strcat(strtmp, s_);
    }
    va_end(marker); // Reset variable arguments
    return strtmp;
}


char* Bin(int number)
{
    char *strtmp = BCX_TmpStr( 32, 1, 1);
    int i;
    for (i = 0; i < 32; ++i)
    {
        strtmp[i] = (number & (1 << (31 - i))) ? '1' : '0';
    }
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


int Bin2Dec (const char *cptr)
{
    int i, j = 0;
    while(cptr && *cptr && strchr("01", *cptr))
    {
        i = *cptr++ - '0';
        j <<= 1;
        j |= (i & 0x01);
    }
    return(j);
}


int Hex2Dec (const char *szInput)
{
    int ret = 0;
    sscanf(szInput, "%x", &ret);
    return ret;
}


// ************************************
//       User Subs and Functions
// ************************************

static gg_type parse_gg_type(const char *type)
{
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
    static char Bit[cSizeOfDefaultString];
    static char Line[200][cSizeOfDefaultString];

    if(argc != 5)
    {
        fprintf(
            stderr,
            "Usage: GGGG <code> <type> <input> <output>\n"
            "\n"
            "Game Genie Code:\n"
            "  1: XXX-XXX or XXX-XXX-XXX\n"
            "  2: XXXX-XXXX\n"
            "  3: XXXXXX or XXXXXXXX\n"
            "  4: XXXX-XXXX\n"
            "\n"
            "System Type:\n"
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
    static char Code[cSizeOfDefaultString];

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

        strcpy(Code, Line[Lnum]);
        printf("Parsing code: %s\n", Code);
        if(strchr(Code, ':'))
        {
            if(ext && (strcasecmp(ext, "pce") == 0 || (strcasecmp(ext, "sms") == 0 && lof(File1) % 1024)))
            {
                Off +=   512;
            }
            Off = Hex2Dec(left( Code, strlen( Code) - 3));
            Rep = Hex2Dec(right( Code, 2));
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
                        GET(FP2, Code, 1 );
                        if((UCHAR) * (Code) == Cmp )
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
                        GET(FP2, Code, 1 );
                        if((UCHAR) * (Code) == Cmp )
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
            GET(FP2, Bit, 1 );
            if((UCHAR) * (Bit) != 33 && (UCHAR) * (Bit) != 49 )
            {
                Off = Bin2Dec(join( 3, "0", left(lpad(Bin(Off), 24, 48), 8), right(lpad(Bin(Off), 24, 48), 15)));
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
