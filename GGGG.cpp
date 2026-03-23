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
typedef std::string::value_type charT;
typedef std::string stdstr;
using namespace std;
#include <ctype.h>      // dos/linux
#include <fcntl.h>      // dos/linux
#include <stdint.h>
#include <stdio.h>      // dos/linux
#include <string.h>     // dos/linux
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
char*   lcase (const char*);
stdstr lcase(stdstr &, int = 0);
charT lower(charT arg)
{
    return std::use_facet<std::ctype<charT> >(std::locale()).tolower(arg);
}
char*   ucase (const char*);
stdstr ucase(stdstr &, int = 0);
charT upper(charT arg)
{
    return std::use_facet<std::ctype<charT> >(std::locale()).toupper(arg);
}
std::string   mid (std::string, size_t, int = -1);
char*   mid (const char*, int, int = -1);
char*   _strupr_(char *);
char*   _strlwr_(char *);
std::string   trim (std::string);
char*   trim (const char*);
std::string   left (std::string, int);
char*   left (const char*, int);
std::string   right (std::string, int);
char*   right (const char*, int);
char*   lpad (const char*, int, int = 32);
char*   replace (const char*, const char*, char);
char*   hex (int);
char*   Bin (int);
char*   join (int, ... );
char*   chr(int);
int     Bin2Dec (const char*);
int     Hex2Dec (const char*);
off_t   lof (const char*);
int     Split (char [][cSizeOfDefaultString], char*, const char*);
static char    CRLF[3] = {13, 10, 0}; // Carr Rtn & Line Feed

// *************************************************
//                System Variables
// *************************************************

// *************************************************
//          User Defined Types And Unions
// *************************************************

// *************************************************
//            User Global Variables
// *************************************************

static int     Cmp;
static int     Lnum;
static int     Num;
static int     Off;
static int     Rep;
static int     Codes;
static FILE   *FP2;
static char    Line[200][cSizeOfDefaultString];
static char    Bit[cSizeOfDefaultString];
static char    Dec[cSizeOfDefaultString];
static char    Out[cSizeOfDefaultString];


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


std::string mid (std::string s, size_t start, int length)
{
    if (start > s.length() || start < 1)  return "" ;
    if (length < 0) length = s.length();
    return s.substr(start - 1, length);
}
char *mid (const char *S, int start, int length)
{
    char *strtmp;
    int tmplen = strlen(S);
    if(start > tmplen || start < 1) return BCX_TmpStr(1, 1, 1);
    if (length < 0 || length > (tmplen - start) + 1)
        length = (tmplen - start) + 1;
    strtmp = BCX_TmpStr(length, 1, 1);
    return (char*)memcpy(strtmp, &S[start - 1], length);
}


std::string trim (std::string str)
{
    str.erase(0, str.find_first_not_of(" \t\n\v\r\f"));       //prefixing whitespaces
    str.erase(str.find_last_not_of(" \t\n\v\r\f") + 1);       //surfixing whitespaces
    return str;
}
char *trim (const char *s)
{
    while (isspace(*s)) ++s;
    size_t i = strlen(s);
    while (i > 0 && isspace(s[i - 1])) --i;
    char *ret = (char*)malloc(i + 1);
    memcpy(ret, s, i);
    ret[i + 1] = '\0';
    return ret;
}


char *replace (const char *src, const char *pat, char rep)
{
    size_t len = strlen(src);
    char *ret = (char*)malloc(len + 1);
    size_t i, r;
    for (i = r = 0; i < len; ++i)
    {
        if (strchr(pat, src[i]))
        {
            if (rep)
            {
                ret[r++] = rep;
            }
        }
        else
        {
            ret[r++] = src[i];
        }
    }
    ret[r] = '\0';
    return ret;
}


stdstr ucase(stdstr & m, int f)
{
    stdstr s;
    if(f)
    {
        std::transform(m.begin(), m.end(), m.begin(), upper);
        return s;
    }
    s = m;
    std::transform(s.begin(), s.end(), s.begin(), upper);
    return s;
}
char *ucase (const char *S)
{
    char *strtmp = BCX_TmpStr(strlen(S), 1, 1);
    return _strupr_(strcpy(strtmp, (char*)S));
}


stdstr lcase(stdstr & m, int f)
{
    stdstr s;
    s = m;
    std::transform(s.begin(), s.end(), s.begin(), lower);
    if(f) m = s;
    return s;
}
char *lcase (const char *S)
{
    char *strtmp = BCX_TmpStr(strlen(S), 1, 1);
    return _strlwr_(strcpy(strtmp, (char*)S));
}


char *hex (int a)
{
    char *strtmp = BCX_TmpStr(16, 1, 1);
    sprintf(strtmp, "%X", a);
    return strtmp;
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
int Split (char Buf[][cSizeOfDefaultString], char *T, const char *Delim)
{
    int count = 0;
    char *token;
    token = strtok(T, Delim);
    do
    {
        strcpy(Buf[count++], token);
    } while((token = strtok(NULL, Delim)) != NULL);
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


char *_strupr_(char *string)
{
    char *s;

    if (string)
    {
        for(s = string; *s; ++s)
            *s = toupper(*s);
    }
    return string;
}

char *_strlwr_(char *string)
{
    char *s;

    if (string)
    {
        for (s = string; *s; ++s)
            *s = tolower(*s);
    }
    return string;
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
    strcpy(Code, argv[1]);

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
        printf("%s\n", "ERROR: ROM doesn't exists");
        exit(1);
    }
    strcpy(Code, replace(Code, "-", 0));
    strcpy(Code, replace(Code, "+", '\n'));
    Codes = Split( Line, Code, "\n");
    printf("%s%i\n", "Codes to inject: ", Codes);
    const char* ext = strrchr(File1, '.');
    if (ext)
    {
        strcpy(Bit, lcase(ext + 1));
    }
    else
    {
        Bit[0] = 0;
    }
    printf("%s%s\n", "Rom to patch: ", File1);
    printf("%s%s\n", "Patch at: ", File2);
    if((FP2 = fopen(File2, "rb+")) == 0)
    {
        fprintf(stderr, "Can't open file %s\n", File2);
        exit(1);
    }
    printf("%s%s\n", CRLF, "Log:");
    for(Lnum = 0; Lnum < Codes; Lnum += 1)
    {
        struct codebits decoded;

        strcpy(Line[Lnum], trim(ucase(Line[Lnum])));
        strcpy(Code, Line[Lnum]);
        printf("%s%s\n", "Parsing code: ", Code);
        *Dec = 0;
        if(strchr(Code, ':'))
        {
            if(strcmp(Bit, "pce") == 0 || ( strcmp(Bit, "sms") == 0 && lof(File1) % 1024))
            {
                Off +=   512;
            }
            Off = Hex2Dec(left( Code, strlen( Code) - 3));
            Rep = Hex2Dec(right( Code, 2));
            if(Off < lof(File1))
            {
                fseek(FP2, Off, 0);
                PUT(FP2, chr(Rep), 1 );
                strcpy(Out, join(3, Line[Lnum], CRLF, Out));
                printf("%s\n", Out);
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
                        strcpy(Out, join(9, Line[Lnum], " - ", trim(hex(Off)), ":", trim(hex(Cmp)), ":", trim(hex(Rep)), CRLF, Out));
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
                            strcpy(Out, join(9, Line[Lnum], " - ", trim(hex(Off)), ":", trim(hex(Cmp)), ":", trim(hex(Rep)), CRLF, Out));
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
                strcpy(Out, join(8, Line[Lnum], " - ", trim(hex(Off)), ":", trim(hex(Rep)), CRLF, Out));
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
                            strcpy(Out, join(9, Line[Lnum], " - ", trim(hex(Off)), ":", trim(hex(Cmp)), ":", trim(hex(Rep)), CRLF, Out));
                        }
                        Off +=   8192;
                    }

                }
                else
                {
                    fseek(FP2, Off, 0);
                    PUT(FP2, chr(Rep), 1 );
                    strcpy(Out, join(9, Line[Lnum], " - ", trim(hex(Off)), ":", trim(hex(Cmp)), ":", trim(hex(Rep)), CRLF, Out));
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
                            strcpy(Out, join(9, Line[Lnum], " - ", trim(hex(Off)), ":", trim(hex(Cmp)), ":", trim(hex(Rep)), CRLF, Out));
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
            strcpy(Dec, hex(Off));
            Num = 65493;
            if(lof(File1) % 1024 != 0 )
            {
                Num +=   512;
            }
            fseek(FP2, Num, 0);
            GET(FP2, Bit, 1 );
            if((UCHAR) * (Bit) != 33 && (UCHAR) * (Bit) != 49 )
            {
                Off = Bin2Dec(join( 3, "0", left(lpad(Bin( Hex2Dec( Dec)), 24, 48), 8), right(lpad(Bin( Hex2Dec( Dec)), 24, 48), 15)));
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
                strcpy(Out, join(7, Line[Lnum], " - ", trim(hex(Off)), ":", trim(hex(Rep)), CRLF, Out));
            }
        }
    }

    if(FP2)
    {
        fclose(FP2);
        FP2 = NULL;
    }
    printf("%s\n", "Final Changes:");
    printf("%s\n", Out);
    return 0;   /* End of main program */
}
