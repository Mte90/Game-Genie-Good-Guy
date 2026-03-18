#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _WIN32
#include <glib.h>
#include <gio/gio.h>
#include <glib/gstdio.h>
#endif

#include "copyfile.h"

bool gCopyFile(const char* source, const char* dest, bool overwrite)
{
#ifdef _WIN32
    FILE *fpsrc, *fpdst;
    char *buf = (char*)malloc(1024 * 1024);
    size_t nread, nwrite;

    fpsrc = fopen(source, "rb");
    fpdst = fopen(dest, "wb");
    if (buf == NULL || fpsrc == NULL || fpdst == NULL)
        return false;

    while (1)
    {
        nread = fread(buf, 1, sizeof(buf), fpsrc);
        if (nread == 0)
            break;
        nwrite = fwrite(buf, 1, nread, fpdst);
        if (nwrite != nread)
            return false;
    }
    fclose(fpsrc);
    fclose(fpdst);
    free(buf);
    return true;
#else
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
#endif
}
