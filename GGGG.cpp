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
#include <wchar.h>      // dos/linux 
#include <ctype.h>      // dos/linux
#include <fcntl.h>      // dos/linux
#include <stdint.h>
#include <stdio.h>      // dos/linux
#include <string.h>     // dos/linux
#include <stddef.h>     // dos/linux
#include <stdlib.h>     // dos/linux
#include <time.h>       // dos/linux
#include <stdarg.h>     // dos/linux
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>    // linux only
#include <unistd.h>     // linux only
#include <glib.h>
#include <gio/gio.h>
#include <glib/gstdio.h>

#define __cdecl
#define __stdcall
// ***************************************************
// Compiler Defines
// ***************************************************
#include "./include/functions.c"

// *************************************************
//        User's GLOBAL ENUM blocks
// *************************************************

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

bool    gCopyFile (const gchar*, const gchar*, gboolean = 0 );
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

// A decoded game genie code.
struct codebits
{
    uint32_t len;
    uint32_t off;
    uint32_t rep;
    uint32_t cmp;
};


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

bool gCopyFile (const gchar*  source, const gchar*  dest, gboolean  overwrite)
{
    GError*  gerr = {0};
    GFile*   fsrc = {0};
    GFile*   fdest = {0};
    GFileCopyFlags owflag = G_FILE_COPY_OVERWRITE;
    if(overwrite )
    {
        owflag = G_FILE_COPY_NONE;
    }
    if(strncmp(source, "http:", 5) == 0 || strncmp(source, "https:", 6) == 0)
    {
        fsrc = g_file_new_for_uri( source);
    }
    else
    {
        fsrc = g_file_new_for_path( source);
    }
    fdest = g_file_new_for_path( dest);
    if(g_file_copy(fsrc, fdest, owflag, NULL, NULL, NULL, &gerr))
    {
        return true;
    }
    fprintf(stderr, "%s\n", gerr->message);
    return false;
}
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
char *trim (const char *S)
{
    if(S[0] == 0) return (char*)S;
    while(*S == 32 || (*S >= 9 && *S <= 13)) S++;
    int i = strlen(S);
    while( i > 0 && (S[i - 1] == 32 || (S[i - 1] >= 9 && S[i - 1] <= 13))) i--;
    char *strtmp = BCX_TmpStr(i, 1, 1);
    return (char*)memcpy(strtmp, S, i);
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
    char *strtmp = BCX_TmpStr( 2048, 1, 1);
    itoa(number, strtmp, 2);
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

static bool decodeGbGgMs(char *code, struct codebits *decoded)
{
    decoded->len = strlen(code);
    if(decoded->len == 6)
    {
        strcpy(code, join(4, hex(Hex2Dec(mid(code, 6, 1)) ^ 15), mid(code, 3, 3), ":", left(code, 2)));
        decoded->off = Hex2Dec(left( code, 4));
        decoded->rep = Hex2Dec(right( code, 2));
        decoded->cmp = 0;
    }
    else if(decoded->len == 9)
    {
        strcpy(code, join(7, hex(Hex2Dec(mid(code, 6, 1)) ^ 15), mid(code, 3, 3), ":", left(code, 2), ":", mid(code, 7, 1), mid(code, 9, 1)));
        strcpy(Dec, lpad(Bin(Hex2Dec(mid(code, 9, 2))), 8, 48));
        strcpy(code, join(2, left(code, 8), hex(Bin2Dec(join(2, mid(Dec, 7, 2), left(Dec, 6))) ^ 186)));
        decoded->off = Hex2Dec(left( code, 4));
        decoded->rep = Hex2Dec(mid( code, 6, 2));
        decoded->cmp = Hex2Dec(right( code, 2));
    }
    else
    {
        fprintf(stderr, "%s: invalid code length\n", code);
        return false;
    }

    return true;
}

static bool decodeGenesis(char *code, struct codebits *decoded)
{
    size_t num;

    for(num = 0; code[num]; num += 1)
    {
        switch (code[num])
        {
            case 'A':
                strcat(Dec, "00000");
                break;
            case 'B':
                strcat(Dec, "00001");
                break;
            case 'C':
                strcat(Dec, "00010");
                break;
            case 'D':
                strcat(Dec, "00011");
                break;
            case 'E':
                strcat(Dec, "00100");
                break;
            case 'F':
                strcat(Dec, "00101");
                break;
            case 'G':
                strcat(Dec, "00110");
                break;
            case 'H':
                strcat(Dec, "00111");
                break;
            case 'J':
                strcat(Dec, "01000");
                break;
            case 'K':
                strcat(Dec, "01001");
                break;
            case 'L':
                strcat(Dec, "01010");
                break;
            case 'M':
                strcat(Dec, "01011");
                break;
            case 'N':
                strcat(Dec, "01100");
                break;
            case 'P':
                strcat(Dec, "01101");
                break;
            case 'R':
                strcat(Dec, "01110");
                break;
            case 'S':
                strcat(Dec, "01111");
                break;
            case 'T':
                strcat(Dec, "10000");
                break;
            case 'V':
                strcat(Dec, "10001");
                break;
            case 'W':
                strcat(Dec, "10010");
                break;
            case 'X':
                strcat(Dec, "10011");
                break;
            case 'Y':
                strcat(Dec, "10100");
                break;
            case 'Z':
                strcat(Dec, "10101");
                break;
            case '0':
                strcat(Dec, "10110");
                break;
            case '1':
                strcat(Dec, "10111");
                break;
            case '2':
                strcat(Dec, "11000");
                break;
            case '3':
                strcat(Dec, "11001");
                break;
            case '4':
                strcat(Dec, "11010");
                break;
            case '5':
                strcat(Dec, "11011");
                break;
            case '6':
                strcat(Dec, "11100");
                break;
            case '7':
                strcat(Dec, "11101");
                break;
            case '8':
                strcat(Dec, "11110");
                break;
            case '9':
                strcat(Dec, "11111");
                break;
            default:
                fprintf(stderr, "%s: invalid code letter '%c'\n", code, code[num]);
                return false;
        }
    }

    decoded->len = strlen(code);
    strcpy(code, join(6, mid(Dec, 17, 8), mid(Dec, 9, 8), right(Dec, 8), mid(Dec, 30, 3), mid(Dec, 25, 5), left(Dec, 8)));
    strcpy(Dec, join(3, lpad(hex(Bin2Dec(left(code, 24))), 6, 48), ":", lpad(hex(Bin2Dec(right(code, 16))), 4, 48)));
    decoded->off = Hex2Dec(left( Dec, 6));
    decoded->cmp = Hex2Dec(mid( Dec, 8, 2));
    decoded->rep = Hex2Dec(right( Dec, 2));

    return true;
}

static bool decodeNES(char *code, struct codebits *decoded)
{
    size_t num;

    for(num = 0; code[num]; num += 1)
    {
        switch (code[num])
        {
            case 'A':
                strcat(Dec, "0000");
                break;
            case 'P':
                strcat(Dec, "0001");
                break;
            case 'Z':
                strcat(Dec, "0010");
                break;
            case 'L':
                strcat(Dec, "0011");
                break;
            case 'G':
                strcat(Dec, "0100");
                break;
            case 'I':
                strcat(Dec, "0101");
                break;
            case 'T':
                strcat(Dec, "0110");
                break;
            case 'Y':
                strcat(Dec, "0111");
                break;
            case 'E':
                strcat(Dec, "1000");
                break;
            case 'O':
                strcat(Dec, "1001");
                break;
            case 'X':
                strcat(Dec, "1010");
                break;
            case 'U':
                strcat(Dec, "1011");
                break;
            case 'K':
                strcat(Dec, "1100");
                break;
            case 'S':
                strcat(Dec, "1101");
                break;
            case 'V':
                strcat(Dec, "1110");
                break;
            case 'N':
                strcat(Dec, "1111");
                break;
            default:
                fprintf(stderr, "%s: invalid code letter '%c'\n", code, code[num]);
                return false;
        }
    }

    decoded->len = strlen(code);
    if(decoded->len == 6)
    {
        strcpy(code, join(10, mid(Dec, 9, 1), mid(Dec, 14, 4), mid(Dec, 22, 3), mid(Dec, 5, 1), mid(Dec, 10, 4), mid(Dec, 18, 3), mid(Dec, 1, 1), mid(Dec, 6, 3), mid(Dec, 21, 1), mid(Dec, 2, 3)));
        strcpy(Dec, join(3, lpad(hex(Bin2Dec(left(code, 16))), 4, 48), ":", lpad(hex(Bin2Dec(right(code, 8))), 2, 48)));
        decoded->off = Hex2Dec(left( Dec, 4));
        decoded->cmp = 0;
        decoded->rep = Hex2Dec(right( Dec, 2));
    }
    else if(decoded->len == 8)
    {
        strcpy(code, join(14, mid(Dec, 9, 1), mid(Dec, 14, 4), mid(Dec, 22, 3), mid(Dec, 5, 1), mid(Dec, 10, 4), mid(Dec, 18, 3), mid(Dec, 1, 1), mid(Dec, 6, 3), mid(Dec, 29, 1), mid(Dec, 2, 3), mid(Dec, 25, 1), mid(Dec, 30, 3), mid(Dec, 21, 1), mid(Dec, 26, 3)));
        strcpy(Dec, join(5, lpad(hex(Bin2Dec(left(code, 16))), 4, 48), ":", lpad(hex(Bin2Dec(mid(code, 17, 8))), 2, 48), ":", lpad(hex(Bin2Dec(right(code, 8))), 2, 48)));
        decoded->off = Hex2Dec(left( Dec, 4)) - 49152;
        decoded->cmp = Hex2Dec(right( Dec, 2));
        decoded->rep = Hex2Dec(mid( Dec, 6, 2));
    }
    else
    {
        fprintf(stderr, "%s: invalid code length\n", code);
        return false;
    }

    return true;
}

static bool decodeSNES(char *code, struct codebits *decoded)
{
    size_t num;

    for(num = 0; code[num]; num += 1)
    {
        switch (code[num])
        {
            case 'D':
                strcat(Dec, "0");
                break;
            case 'F':
                strcat(Dec, "1");
                break;
            case '4':
                strcat(Dec, "2");
                break;
            case '7':
                strcat(Dec, "3");
                break;
            case '0':
                strcat(Dec, "4");
                break;
            case '9':
                strcat(Dec, "5");
                break;
            case '1':
                strcat(Dec, "6");
                break;
            case '5':
                strcat(Dec, "7");
                break;
            case '6':
                strcat(Dec, "8");
                break;
            case 'B':
                strcat(Dec, "9");
                break;
            case 'C':
                strcat(Dec, "A");
                break;
            case '8':
                strcat(Dec, "B");
                break;
            case 'A':
                strcat(Dec, "C");
                break;
            case '2':
                strcat(Dec, "D");
                break;
            case '3':
                strcat(Dec, "E");
                break;
            case 'E':
                strcat(Dec, "F");
                break;
            default:
                fprintf(stderr, "%s: invalid code letter '%c'\n", code, code[num]);
                return false;
        }
    }

    decoded->len = strlen(code);
    decoded->rep = Hex2Dec(left( Dec, 2));
    strcpy(code, join(3, lpad(Bin(Hex2Dec(mid(Dec, 3, 2))), 8, 48), lpad(Bin(Hex2Dec(mid(Dec, 5, 2))), 8, 48), lpad(Bin(Hex2Dec(mid(Dec, 7, 2))), 8, 48)));
    strcpy(Dec, join(7, mid(code, 11, 4), mid(code, 19, 4), left(code, 4), mid(code, 23, 2), mid(code, 9, 2), mid(code, 5, 4), mid(code, 15, 4)));
    strcpy(code, join(5, lpad(hex(Bin2Dec(left(Dec, 8))), 2, 48), lpad(hex(Bin2Dec(mid(Dec, 9, 8))), 2, 48), lpad(hex(Bin2Dec(right(Dec, 8))), 2, 48), ":", hex(Rep)));
    decoded->off = Hex2Dec(left( code, 6));
    decoded->cmp = 0;

    return true;
}

// *************************************************
//                  Main Program
// *************************************************

int main(int argc, char *argv[])
{
    if(argc != 5)
    {
        printf("%s\n", "ERROR: Missing some parameters, check the readme");
        exit(1);
    }
    static char Code[cSizeOfDefaultString];
    strcpy(Code, argv[1]);
    const char* Type = argv[2];
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
        if(strcmp(Type, "1") == 0)
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
        if(strcmp(Type, "2") == 0)
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
                PUT(FP2, chr(Cmp), 1 );
                fseek(FP2, Off + 1, 0);
                PUT(FP2, chr(Rep), 1 );
                strcpy(Out, join(8, Line[Lnum], " - ", trim(hex(Off)), ":", trim(hex(Cmp)), trim(hex(Rep)), CRLF, Out));
            }
        }
        if(strcmp(Type, "3") == 0)
        {
            if (!decodeNES(Code, &decoded))
            {
                continue;
            }
            Off = decoded.off;
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
        if(strcmp(Type, "4") == 0)
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
