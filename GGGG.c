// *********************************************************************
//  Created with UbxBasic - BASIC To C++ Translator (V) 1.0.4.7 (2016/05/01)
// ----------------------------------------------------------------------
//                 BCX (c) 1999 - 2009 by Kevin Diggins
// *********************************************************************
//              Translated for compiling with a C Compiler
//                            On a nix OS
// *********************************************************************
#include <wchar.h>      // dos/linux 
#include <ctype.h>      // dos/linux
#include <fcntl.h>      // dos/linux
#include <math.h>       // dos/linux
#include <stdio.h>      // dos/linux
#include <string.h>     // dos/linux
#include <stddef.h>     // dos/linux
#include <stdlib.h>     // dos/linux
#include <setjmp.h>     // dos/linux
#include <time.h>       // dos/linux
#include <stdarg.h>     // dos/linux
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>    // linux only
#include <dirent.h>     // linux only
#include <sys/wait.h>   // linux only
#include <unistd.h>     // linux only
#include <dlfcn.h>      // linux only
#include <termios.h>    // linux only
#include <gtk/gtk.h>
#include <glib.h>
#include <gmodule.h>
#include <glib/gstdio.h>

typedef char *PCHAR, *LPCH, *PCH, *NPSTR, *LPSTR, *PSTR;
typedef unsigned long DWORD, ULONG, *PDWORD, *LPDWORD, *PULONG;
#ifndef bool
#define bool gboolean
#endif
#define __cdecl
#define __stdcall
// ***************************************************
// Compiler Defines
// ***************************************************
#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef MAX_PATH
#define MAX_PATH 2048
#endif


#define stricmp strcasecmp
#include "./include/functions.c"

// *************************************************
//        User's GLOBAL ENUM blocks
// *************************************************

// *************************************************
//            System Defined Constants
// *************************************************

typedef const char* ccptr;
#define CCPTR const char*
#define NOT_USED(x) if(x);
#define cfree free
typedef unsigned short WORD;
typedef WORD *LPWORD;
typedef int BOOL;
typedef unsigned long DWORD;
typedef char CHAR;
typedef int *PINT;
typedef unsigned int UINT;
typedef void *LPVOID;
typedef unsigned char byte;
typedef unsigned char BYTE;
typedef unsigned char UCHAR, *PUCHAR;
char   *g_cptr_;  // dummy var for not used returns
size_t  g_dum1_;  // dummy var for not used returns
int g_dum_int;		// dummy int var for not used returns
#ifdef __G_LIB_H__
gchar g_gerr[2048];  // global for glib errors
#endif
#define cSizeOfDefaultString 2048

// *************************************************
//            User Defined Constants
// *************************************************


// *************************************************
//               Standard Prototypes
// *************************************************

gboolean gCopyFile (const gchar*, const gchar*, gboolean );
int     iMatch (const char*, const char*, int);
#define iMatchLft(A,B) iMatch(A,B, 0)
#define iMatchWrd(A,B) iMatch(A,B, 1)
#define iMatchRgt(A,B) iMatch(A,B, 2)
int     str_cmp(const char*, const char*);
char* BCX_TmpStr(size_t, size_t , int );
char*   lcase (const char*);
char*   ucase (const char*);
char* mid (const char*, int, int );
char*   _strupr_(char *);
char*   _strlwr_(char *);
char*   trim (const char*);
char*   left (const char*, int);
char*   right (const char*, int);
char* lpad (const char*, int, int );
char*   replace (const char*, const char*, const char*);
char*   hex (int);
char*   Bin (int);
char*   RemoveStr (const char*, const char*);
char*   join (int, ... );
char*   chr(int);
int InstrRev (const char*, const char*, int , int );
int instr(const char*, const char*, int , int );
char    *MakeLCaseTbl(void);
char    *_stristr_(char*, char*);
char    *_strstr_(char*, char*);
int     Bin2Dec (const char*);
int     Hex2Dec (const char*);
gboolean Exist(const char*);
DWORD   lof (const char*);
int Split (char [][cSizeOfDefaultString], const char*, const char*, int );
char *LowCase;
static char    LF  [2] = {10, 0}; // Line Feed
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

static PCHAR   *g_argv;
static int     g_argc;
static int     Cmp;
static int     Lnum;
static int     Num;
static int     Off;
static int     Rep;
static FILE   *FP2;
static char    Line[200][cSizeOfDefaultString];
static char    Bit[cSizeOfDefaultString];
static char    Code[cSizeOfDefaultString];
static char    Dec[cSizeOfDefaultString];
static char    File1[cSizeOfDefaultString];
static char    File2[cSizeOfDefaultString];
static char    Out[cSizeOfDefaultString];
static char    Type[cSizeOfDefaultString];


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

gboolean gCopyFile (const gchar*  source, const gchar*  dest, gboolean  overwrite)
{
    GError*  gerr = {0};
    GFile*   fsrc = {0};
    GFile*   fdest = {0};
    int      owflag = G_FILE_COPY_OVERWRITE;
    if(overwrite )
    {
        owflag = G_FILE_COPY_NONE;
    }
    if(iMatchLft(source, "http:") || iMatchLft(source, "https:"))
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
        return 1;
    }
    strcpy(g_gerr, gerr->message);
    return 0;
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


int str_cmp (const char *a, const char *b)
{
    register int counter = 0;
    for(;;)
    {
        if((a[counter]^b[counter]))
        {
            if((UINT) a[counter] >= (UINT) b[counter])
                return  1;
            return -1;
        }
        if(!a[counter]) return 0;
        counter++;
    }
}


char *left (const char *S, int length)
{
    register int tmplen = strlen(S);
    if(length < 1) return BCX_TmpStr(1, 0, 1);
    if(length < tmplen) tmplen = length;
    char *strtmp = BCX_TmpStr(tmplen, 1, 1);
    return (char*)memcpy(strtmp, S, tmplen);
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


char *mid (const char *S, int start, int length)
{
    char *strtmp;
    register int tmplen = strlen(S);
    if(start > tmplen || start < 1) return BCX_TmpStr(1, 1, 1);
    if (length < 0 || length > (tmplen - start) + 1)
        length = (tmplen - start) + 1;
    strtmp = BCX_TmpStr(length, 1, 1);
    return (char*)memcpy(strtmp, &S[start - 1], length);
}


char *trim (const char *S)
{
    if(S[0] == 0) return (char*)S;
    while(*S == 32 || (*S >= 9 && *S <= 13)) S++;
    register int i = strlen(S);
    while( i > 0 && (S[i - 1] == 32 || (S[i - 1] >= 9 && S[i - 1] <= 13))) i--;
    char *strtmp = BCX_TmpStr(i, 1, 1);
    return (char*)memcpy(strtmp, S, i);
}


char *replace (const char *src, const char *pat, const char *rep)
{
    register size_t patsz, repsz, tmpsz, delta;
    register char *strtmp, *p, *q, *r;
    if (!pat || !*pat)
    {
        strtmp = BCX_TmpStr(strlen(src), 1, 1);
        if (!strtmp) return NULL;
        return strcpy(strtmp, src);
    }
    repsz = strlen(rep);
    patsz = strlen(pat);
    for (tmpsz = 0, p = (char*)src; (q = _strstr_(p, (char*)pat)) != 0; p = q + patsz)
        tmpsz += (size_t) (q - p) + repsz;
    tmpsz += strlen(p);
    strtmp = BCX_TmpStr(tmpsz, 1, 1);
    if (!strtmp) return NULL;
    for (r = strtmp, p = (char*)src; (q = _strstr_(p, (char*)pat)) != 0; p = q + patsz)
    {
        delta = (size_t) (q - p);
        memcpy(r, p, delta);
        r += delta;
        strcpy(r, rep);
        r += repsz;
    }
    strcpy(r, p);
    return strtmp;
}


int iMatch (const char*  Arg, const char*  MatchStr, int mt)
{
    if(mt == 2 )
    {
        int     L1;
        int     L2;
        L1 = strlen( Arg);
        L2 = strlen( MatchStr);
        if(L1 < L2 )
        {
            return FALSE;
        }
        Arg = ( Arg + L1) - L2;
    }
    while(*MatchStr)
    {
        if(*Arg == 0 )
        {
            return FALSE;
        }
        if((*Arg | 32) != (*MatchStr | 32))
        {
            return FALSE;
        }
        Arg++;
        MatchStr++;
    }
    if(mt && *Arg != 0 )
    {
        return FALSE;
    }
    return TRUE;
}
char *ucase (const char *S)
{
    register char *strtmp = BCX_TmpStr(strlen(S), 1, 1);
    return _strupr_(strcpy(strtmp, (char*)S));
}


char *lcase (const char *S)
{
    register char *strtmp = BCX_TmpStr(strlen(S), 1, 1);
    return _strlwr_(strcpy(strtmp, (char*)S));
}


char *RemoveStr (const char *a, const char *b)
{
    char *strtmp, *p, *d;
    int  tmplen;
    strtmp = d = BCX_TmpStr(strlen(a), 1, 1);
    if(!b || !*b) return strcpy(strtmp, a);
    p = _strstr_((char*)a, (char*)b);
    tmplen = strlen(b);
    while(p)
    {
        memcpy(d, a, p - a);
        d += (p - a);
        a = p + tmplen;
        p = _strstr_((char*)a, (char*)b);
    }
    strcpy(d, a);
    return strtmp;
}


char *hex (int a)
{
    register char *strtmp = BCX_TmpStr(16, 1, 1);
    sprintf(strtmp, "%X", a);
    return strtmp;
}


char *chr (int a)
{
    register char *strtmp = BCX_TmpStr(2, 1, 1);
    strtmp[0]  = a;
    return strtmp;
}


char * join(int n, ...)
{
    register int i = n, tmplen = 0;
    register char *s_;
    register char *strtmp;
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


int InstrRev (const char *s, const char *p, int os, int sens)
{
    int sl, pl, ox;
    int (*cmp)(const char *, const char *, size_t );

    if (!s || !p)  return 0;
    sl  = strlen(s);
    pl  = strlen(p);
    if (os > sl || sl == 0 || pl == 0 || (ox = sl - pl) < 0)
        return 0;

    if (os <= 0)
        os = ox ;
    else if(os >= pl)
        os = os - pl ;
    else
        return 0;

    cmp = (sens ? strncasecmp : strncmp);
    do {
        if (cmp(s + os, p, pl) == 0)
            return os + 1;
    } while (os--);
    return 0;
}


int instr(const char* mane, const char* match, int offset, int sensflag)
{
    register char *s;
    if (!mane || !match || ! *match || offset > (int)strlen(mane)) return 0;
    if (sensflag)
        s = _stristr_(offset > 0 ? (char*)mane + offset - 1 : (char*)mane, (char*)match);
    else
        s = _strstr_(offset > 0 ? (char*)mane + offset - 1 : (char*)mane, (char*)match);
    return s ? (int)(s - mane) + 1 : 0;
}


char  *MakeLCaseTbl (void)
{
    static char tbl[256];
    if(!tbl['a'])
    {
        int i;
        for (i = 0; i < 256; i++)
            tbl[i] = (char)(int)tolower(i);
    }
    return tbl;
}


char *_stristr_(char *String, char *Pattern)
{
    int   mi = -1;
    while(Pattern[++mi])
    {
        if(String[mi] == 0) return 0;
        if(LowCase[(unsigned char)String[mi]] != LowCase[(unsigned char)Pattern[mi]])
        {
            String++;
            mi = -1;
        }
    }
    return String;
}


char *_strstr_(char *String, char *Pattern)
{
    int   mi = -1;
    while(Pattern[++mi])
    {
        if(String[mi] == 0) return 0;
        if(String[mi] != Pattern[mi])
        {
            String++;
            mi = -1;
        }
    }
    return String;
}


gboolean Exist (const char*  sfn)
{
    return g_file_test(sfn, (GFileTest)(G_FILE_TEST_EXISTS | G_FILE_TEST_IS_DIR));
}
DWORD lof (const char * FileName)
{
    int retstat;
    GStatBuf sb;
    retstat = g_stat(FileName, &sb);
    if(retstat != -1)
        return sb.st_size;
    return 0;
}
int Split (char Buf[][cSizeOfDefaultString], const char *T, const char *Delim, int Flg)
{
    int  Begin = 0;
    int  Count = 0;
    int  Quote = 0;
    int  Index, i;
    int  lenT  = strlen(T);
    char Chr34[2] = {34, 0};
    for(Index = 1; Index <= lenT; Index++)
    {
        if(instr(Delim, mid(T, Index, 1), 0, 0) && !Quote)
        {
            strcpy(Buf[Count], (char*)mid(T, Begin, Index - Begin));
            if ((Flg & 2) == 0)  // 0 if old version
                Count++;
            else if (Buf[Count][0] != 0) Count++;
            Begin = 0;
            if((Flg & 1) == 1)   // 1 if true
                strcpy(Buf[Count++], (char*)mid(T, Index, 1));
        }
        else
        {
            if(strcmp(mid(T, Index, 1), Chr34) == 0) Quote = !Quote;
            if(Begin == 0) Begin = Index;
        }
    }
    if(Begin)
        strcpy(Buf[Count++], (char*)mid(T, Begin, Index - Begin));
    if((Flg & 1) == 0)   // 0 if false
        for(i = 0; i < Count; i++) strcpy(Buf[i], (char*)RemoveStr(Buf[i], Chr34));
    return Count;
}


int Bin2Dec (const char *cptr)
{
    register int i, j = 0;
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
    char   ch;
    char  *dwLen   = (char*)szInput + strlen(szInput);
    DWORD  dwOut   = 0;
    while(*szInput)
    {
        ch = LowCase[(unsigned char) * szInput++];
        if((ch >= 'a' && ch <= 'f')  || (ch >= '0' && ch <= '9'))
            dwOut |= ((int)ch - (ch > '9' ? 'a' - 10 : '0')) << ((dwLen - szInput) << 2);
    }
    return dwOut;
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

// *************************************************
//                  Main Program
// *************************************************

int main(int argc, char *argv[])
{
    g_argc = argc;
    g_argv = argv;
    LowCase = (char*)calloc(257, 1);
    LowCase = MakeLCaseTbl();
    for(Num = 0; Num <= 200; Num += 1)
    {
        *Line[Num] = 0;
    }

    strcpy(Code, argv[1]);
    strcpy(Type, argv[2]);
    strcpy(Code, replace(Code, "-", ""));
    strcpy(Code, replace(Code, "+", LF));
    Split(Line, Code, LF,  0);
    for(Num = 0; Num <= 200; Num += 1)
    {
        strcpy(Line[Num], trim(ucase(Line[Num])));
    }

    printf("%s\n", "Initialization DONE");
    printf("%s\n", "");
    if(Line[0][0] != 0 )
    {
        printf("%s\n", "Codes to inject:");
        printf("%s\n", Code);
        printf("%s\n", "");
        strcpy(File1, argv[3]);
        strcpy(File2, argv[4]);
        strcpy(Bit, lcase(right(File1, strlen(File1) - InstrRev(File1, ".",  0,  0))));
        printf("%s\n", "Rom to patch:");
        printf("%s\n", File1);
        printf("%s\n", "Patch at:");
        printf("%s\n", File2);
        if(Exist(File2))
        {
            remove (File2 );
        }
        if(Exist(File1))
        {
            gCopyFile (File1, File2,true);
        }
        else
        {
            printf("%s\n", "ROM doesn't exists");
            exit(1);
        }
        if(Exist(File2))
        {
            if((FP2 = fopen(File2, "rb+")) == 0)
            {
                fprintf(stderr, (char*)"Can't open file %s\n", File2);
                exit(1);
            }
        }
        printf("%s\n", "");
        printf("%s\n", "Log:");
        printf("%s\n", "");
        for(Lnum = 0; Lnum <= 200; Lnum += 1)
        {
            if(Line[Lnum][0] != 0 )
            {
                strcpy(Code, Line[Lnum]);
                *Dec = 0;
                if(instr(Code, ":",  0,  0))
                {
                    if(str_cmp(Bit, "pce") == 0 ||  str_cmp(Bit, "sms") == 0 && lof(File1) % 1024 )
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
                if(str_cmp(Type, "1") == 0)
                {
                    if(strlen(Code) == 6 )
                    {
                        strcpy(Code, join(4, hex(Hex2Dec(mid(Code, 6, 1)) ^ 15), mid(Code, 3, 3), ":", left(Code, 2)));
                        Off = Hex2Dec(left( Code, 4));
                        Rep = Hex2Dec(right( Code, 2));
                        for(Num = 0; Num <= lof(File1) / 8192; Num += 1)
                        {
                            if(Off < lof(File1))
                            {
                                fseek(FP2, Off, 0);
                                PUT(FP2, chr(Rep), 1 );
                                strcpy(Out, join(9, Line[Lnum], " - ", trim(hex(Off)), ":", trim(hex(Cmp)), ":", trim(hex(Rep)), CRLF, Out));
                                printf("%s\n", Out);
                            }
                            Off +=   8192;
                        }

                    }
                    if(strlen(Code) == 9 )
                    {
                        strcpy(Code, join(7, hex(Hex2Dec(mid(Code, 6, 1)) ^ 15), mid(Code, 3, 3), ":", left(Code, 2), ":", mid(Code, 7, 1), mid(Code, 9, 1)));
                        strcpy(Dec, lpad(Bin(Hex2Dec(mid(Code, 9, 2))), 8, 48));
                        strcpy(Code, join(2, left(Code, 8), hex(Bin2Dec(join(2, mid(Dec, 7, 2), left(Dec, 6))) ^ 186)));
                        Off = Hex2Dec(left( Code, 4));
                        Cmp = Hex2Dec(right( Code, 2));
                        Rep = Hex2Dec(mid( Code, 6, 2));
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
                                    printf("%s\n", Out);
                                }
                            }
                            Off +=   8192;
                        }

                    }
                }
                if(str_cmp(Type, "2") == 0)
                {
                    for(Num = 0; Num <= strlen(Code); Num += 1)
                    {
                        if(str_cmp(mid(Code, Num, 1), "A") == 0)
                        {
                            strcat(Dec, "00000");
                        }
                        if(str_cmp(mid(Code, Num, 1), "B") == 0)
                        {
                            strcat(Dec, "00001");
                        }
                        if(str_cmp(mid(Code, Num, 1), "C") == 0)
                        {
                            strcat(Dec, "00010");
                        }
                        if(str_cmp(mid(Code, Num, 1), "D") == 0)
                        {
                            strcat(Dec, "00011");
                        }
                        if(str_cmp(mid(Code, Num, 1), "E") == 0)
                        {
                            strcat(Dec, "00100");
                        }
                        if(str_cmp(mid(Code, Num, 1), "F") == 0)
                        {
                            strcat(Dec, "00101");
                        }
                        if(str_cmp(mid(Code, Num, 1), "G") == 0)
                        {
                            strcat(Dec, "00110");
                        }
                        if(str_cmp(mid(Code, Num, 1), "H") == 0)
                        {
                            strcat(Dec, "00111");
                        }
                        if(str_cmp(mid(Code, Num, 1), "J") == 0)
                        {
                            strcat(Dec, "01000");
                        }
                        if(str_cmp(mid(Code, Num, 1), "K") == 0)
                        {
                            strcat(Dec, "01001");
                        }
                        if(str_cmp(mid(Code, Num, 1), "L") == 0)
                        {
                            strcat(Dec, "01010");
                        }
                        if(str_cmp(mid(Code, Num, 1), "M") == 0)
                        {
                            strcat(Dec, "01011");
                        }
                        if(str_cmp(mid(Code, Num, 1), "N") == 0)
                        {
                            strcat(Dec, "01100");
                        }
                        if(str_cmp(mid(Code, Num, 1), "P") == 0)
                        {
                            strcat(Dec, "01101");
                        }
                        if(str_cmp(mid(Code, Num, 1), "R") == 0)
                        {
                            strcat(Dec, "01110");
                        }
                        if(str_cmp(mid(Code, Num, 1), "S") == 0)
                        {
                            strcat(Dec, "01111");
                        }
                        if(str_cmp(mid(Code, Num, 1), "T") == 0)
                        {
                            strcat(Dec, "10000");
                        }
                        if(str_cmp(mid(Code, Num, 1), "V") == 0)
                        {
                            strcat(Dec, "10001");
                        }
                        if(str_cmp(mid(Code, Num, 1), "W") == 0)
                        {
                            strcat(Dec, "10010");
                        }
                        if(str_cmp(mid(Code, Num, 1), "X") == 0)
                        {
                            strcat(Dec, "10011");
                        }
                        if(str_cmp(mid(Code, Num, 1), "Y") == 0)
                        {
                            strcat(Dec, "10100");
                        }
                        if(str_cmp(mid(Code, Num, 1), "Z") == 0)
                        {
                            strcat(Dec, "10101");
                        }
                        if(str_cmp(mid(Code, Num, 1), "0") == 0)
                        {
                            strcat(Dec, "10110");
                        }
                        if(str_cmp(mid(Code, Num, 1), "1") == 0)
                        {
                            strcat(Dec, "10111");
                        }
                        if(str_cmp(mid(Code, Num, 1), "2") == 0)
                        {
                            strcat(Dec, "11000");
                        }
                        if(str_cmp(mid(Code, Num, 1), "3") == 0)
                        {
                            strcat(Dec, "11001");
                        }
                        if(str_cmp(mid(Code, Num, 1), "4") == 0)
                        {
                            strcat(Dec, "11010");
                        }
                        if(str_cmp(mid(Code, Num, 1), "5") == 0)
                        {
                            strcat(Dec, "11011");
                        }
                        if(str_cmp(mid(Code, Num, 1), "6") == 0)
                        {
                            strcat(Dec, "11100");
                        }
                        if(str_cmp(mid(Code, Num, 1), "7") == 0)
                        {
                            strcat(Dec, "11101");
                        }
                        if(str_cmp(mid(Code, Num, 1), "8") == 0)
                        {
                            strcat(Dec, "11110");
                        }
                        if(str_cmp(mid(Code, Num, 1), "9") == 0)
                        {
                            strcat(Dec, "11111");
                        }
                    }

                    strcpy(Code, join(6, mid(Dec, 17, 8), mid(Dec, 9, 8), right(Dec, 8), mid(Dec, 30, 3), mid(Dec, 25, 5), left(Dec, 8)));
                    strcpy(Dec, join(3, lpad(hex(Bin2Dec(left(Code, 24))), 6, 48), ":", lpad(hex(Bin2Dec(right(Code, 16))), 4, 48)));
                    Off = Hex2Dec(left( Dec, 6));
                    Cmp = Hex2Dec(mid( Dec, 8, 2));
                    Rep = Hex2Dec(right( Dec, 2));
                    if(Off < lof(File1))
                    {
                        fseek(FP2, Off, 0);
                        PUT(FP2, chr(Cmp), 1 );
                        fseek(FP2, Off + 1, 0);
                        PUT(FP2, chr(Rep), 1 );
                        strcpy(Out, join(8, Line[Lnum], " - ", trim(hex(Off)), ":", trim(hex(Cmp)), trim(hex(Rep)), CRLF, Out));
                        printf("%s\n", Out);
                    }
                }
                if(str_cmp(Type, "3") == 0)
                {
                    for(Num = 0; Num <= strlen(Code); Num += 1)
                    {
                        if(str_cmp(mid(Code, Num, 1), "A") == 0)
                        {
                            strcat(Dec, "0000");
                        }
                        if(str_cmp(mid(Code, Num, 1), "P") == 0)
                        {
                            strcat(Dec, "0001");
                        }
                        if(str_cmp(mid(Code, Num, 1), "Z") == 0)
                        {
                            strcat(Dec, "0010");
                        }
                        if(str_cmp(mid(Code, Num, 1), "L") == 0)
                        {
                            strcat(Dec, "0011");
                        }
                        if(str_cmp(mid(Code, Num, 1), "G") == 0)
                        {
                            strcat(Dec, "0100");
                        }
                        if(str_cmp(mid(Code, Num, 1), "I") == 0)
                        {
                            strcat(Dec, "0101");
                        }
                        if(str_cmp(mid(Code, Num, 1), "T") == 0)
                        {
                            strcat(Dec, "0110");
                        }
                        if(str_cmp(mid(Code, Num, 1), "Y") == 0)
                        {
                            strcat(Dec, "0111");
                        }
                        if(str_cmp(mid(Code, Num, 1), "E") == 0)
                        {
                            strcat(Dec, "1000");
                        }
                        if(str_cmp(mid(Code, Num, 1), "O") == 0)
                        {
                            strcat(Dec, "1001");
                        }
                        if(str_cmp(mid(Code, Num, 1), "X") == 0)
                        {
                            strcat(Dec, "1010");
                        }
                        if(str_cmp(mid(Code, Num, 1), "U") == 0)
                        {
                            strcat(Dec, "1011");
                        }
                        if(str_cmp(mid(Code, Num, 1), "K") == 0)
                        {
                            strcat(Dec, "1100");
                        }
                        if(str_cmp(mid(Code, Num, 1), "S") == 0)
                        {
                            strcat(Dec, "1101");
                        }
                        if(str_cmp(mid(Code, Num, 1), "V") == 0)
                        {
                            strcat(Dec, "1110");
                        }
                        if(str_cmp(mid(Code, Num, 1), "N") == 0)
                        {
                            strcat(Dec, "1111");
                        }
                    }

                    if(strlen(Code) == 6 )
                    {
                        strcpy(Code, join(10, mid(Dec, 9, 1), mid(Dec, 14, 4), mid(Dec, 22, 3), mid(Dec, 5, 1), mid(Dec, 10, 4), mid(Dec, 18, 3), mid(Dec, 1, 1), mid(Dec, 6, 3), mid(Dec, 21, 1), mid(Dec, 2, 3)));
                        strcpy(Dec, join(3, lpad(hex(Bin2Dec(left(Code, 16))), 4, 48), ":", lpad(hex(Bin2Dec(right(Code, 8))), 2, 48)));
                        Off = Hex2Dec(left( Dec, 4));
                        Rep = Hex2Dec(right( Dec, 2));
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
                                    printf("%s\n", Out);
                                }
                                Off +=   8192;
                            }

                        }
                        else
                        {
                            fseek(FP2, Off, 0);
                            PUT(FP2, chr(Rep), 1 );
                            strcpy(Out, join(9, Line[Lnum], " - ", trim(hex(Off)), ":", trim(hex(Cmp)), ":", trim(hex(Rep)), CRLF, Out));
                            printf("%s\n", Out);
                        }
                    }
                    if(strlen(Code) == 8 )
                    {
                        strcpy(Code, join(14, mid(Dec, 9, 1), mid(Dec, 14, 4), mid(Dec, 22, 3), mid(Dec, 5, 1), mid(Dec, 10, 4), mid(Dec, 18, 3), mid(Dec, 1, 1), mid(Dec, 6, 3), mid(Dec, 29, 1), mid(Dec, 2, 3), mid(Dec, 25, 1), mid(Dec, 30, 3), mid(Dec, 21, 1), mid(Dec, 26, 3)));
                        strcpy(Dec, join(5, lpad(hex(Bin2Dec(left(Code, 16))), 4, 48), ":", lpad(hex(Bin2Dec(mid(Code, 17, 8))), 2, 48), ":", lpad(hex(Bin2Dec(right(Code, 8))), 2, 48)));
                        Off = Hex2Dec(left( Dec, 4)) - 49152;
                        Cmp = Hex2Dec(right( Dec, 2));
                        Rep = Hex2Dec(mid( Dec, 6, 2));
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
                                    printf("%s\n", Out);
                                }
                            }
                            Off +=   8192;
                        }

                    }
                }
                if(str_cmp(Type, "4") == 0)
                {
                    for(Num = 0; Num <= strlen(Code); Num += 1)
                    {
                        if(str_cmp(mid(Code, Num, 1), "D") == 0)
                        {
                            strcat(Dec, "0");
                        }
                        if(str_cmp(mid(Code, Num, 1), "F") == 0)
                        {
                            strcat(Dec, "1");
                        }
                        if(str_cmp(mid(Code, Num, 1), "4") == 0)
                        {
                            strcat(Dec, "2");
                        }
                        if(str_cmp(mid(Code, Num, 1), "7") == 0)
                        {
                            strcat(Dec, "3");
                        }
                        if(str_cmp(mid(Code, Num, 1), "0") == 0)
                        {
                            strcat(Dec, "4");
                        }
                        if(str_cmp(mid(Code, Num, 1), "9") == 0)
                        {
                            strcat(Dec, "5");
                        }
                        if(str_cmp(mid(Code, Num, 1), "1") == 0)
                        {
                            strcat(Dec, "6");
                        }
                        if(str_cmp(mid(Code, Num, 1), "5") == 0)
                        {
                            strcat(Dec, "7");
                        }
                        if(str_cmp(mid(Code, Num, 1), "6") == 0)
                        {
                            strcat(Dec, "8");
                        }
                        if(str_cmp(mid(Code, Num, 1), "B") == 0)
                        {
                            strcat(Dec, "9");
                        }
                        if(str_cmp(mid(Code, Num, 1), "C") == 0)
                        {
                            strcat(Dec, "A");
                        }
                        if(str_cmp(mid(Code, Num, 1), "8") == 0)
                        {
                            strcat(Dec, "B");
                        }
                        if(str_cmp(mid(Code, Num, 1), "A") == 0)
                        {
                            strcat(Dec, "C");
                        }
                        if(str_cmp(mid(Code, Num, 1), "2") == 0)
                        {
                            strcat(Dec, "D");
                        }
                        if(str_cmp(mid(Code, Num, 1), "3") == 0)
                        {
                            strcat(Dec, "E");
                        }
                        if(str_cmp(mid(Code, Num, 1), "E") == 0)
                        {
                            strcat(Dec, "F");
                        }
                    }

                    Rep = Hex2Dec(left( Dec, 2));
                    strcpy(Code, join(3, lpad(Bin(Hex2Dec(mid(Dec, 3, 2))), 8, 48), lpad(Bin(Hex2Dec(mid(Dec, 5, 2))), 8, 48), lpad(Bin(Hex2Dec(mid(Dec, 7, 2))), 8, 48)));
                    strcpy(Dec, join(7, mid(Code, 11, 4), mid(Code, 19, 4), left(Code, 4), mid(Code, 23, 2), mid(Code, 9, 2), mid(Code, 5, 4), mid(Code, 15, 4)));
                    strcpy(Code, join(5, lpad(hex(Bin2Dec(left(Dec, 8))), 2, 48), lpad(hex(Bin2Dec(mid(Dec, 9, 8))), 2, 48), lpad(hex(Bin2Dec(right(Dec, 8))), 2, 48), ":", hex(Rep)));
                    Off = Hex2Dec(left( Code, 6));
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
                        printf("%s\n", Out);
                    }
                }
            }
        }

        if(FP2)
        {
            fclose(FP2);
            FP2 = NULL;
        }
    }
    return 0;   /* End of main program */
}

