// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// Apply decoded Game Genie codes to the ROM.

#define _POSIX_C_SOURCE 200809L

#include <fcntl.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "decode.h"

#define WUR(x) do { if (x); } while (0)

#ifdef _WIN32

// These should save/restore offset, but the way these are used in this program,
// it doesn't matter.

static ssize_t pread(int fd, void *buf, size_t count, off_t offset)
{
    lseek(fd, offset, 0);
    return read(fd, buf, count);
}

static ssize_t pwrite(int fd, const void *buf, size_t count, off_t offset)
{
    lseek(fd, offset, 0);
    return write(fd, buf, count);
}

#endif

static off_t lof(int fd)
{
    struct stat sb;
    return fstat(fd, &sb) == 0 ? sb.st_size : 0;
}

bool modifyRaw(int fd, const char *ext, struct codebits *decoded)
{
    bool ret = false;
    int Off, Rep;
    off_t filelen;
    unsigned char c;

    filelen = lof(fd);

    Off = decoded->off;
    Rep = decoded->rep;

    if (ext && (strcasecmp(ext, "pce") == 0 || (strcasecmp(ext, "sms") == 0 && filelen % 1024)))
    {
        Off += 512;
    }

    if (Off < filelen)
    {
        c = Rep;
        WUR(pwrite(fd, &c, 1, Off));
        printf("Wrote %#X to ROM offset %X\n", c, Off);
        ret = true;
    }

    return ret;
}

bool modifyGbGgMs(int fd, struct codebits *decoded)
{
    bool ret = false;
    int Num;
    int Off, Cmp, Rep;
    off_t filelen;
    unsigned char c;

    filelen = lof(fd);

    Off = decoded->off;
    Cmp = decoded->cmp;
    Rep = decoded->rep;

    if (decoded->len == 6)
    {
        for (Num = 0; Num <= filelen / 8192; Num += 1)
        {
            if (Off < filelen)
            {
                c = Rep;
                WUR(pwrite(fd, &c, 1, Off));
                printf("Wrote %#X to ROM offset %X\n", c, Off);
                ret = true;
            }
            Off += 8192;
        }
    }

    if (decoded->len == 9)
    {
        for (Num = 0; Num <= filelen / 8192; Num += 1)
        {
            if (Off < filelen)
            {
                WUR(pread(fd, &c, 1, Off));
                if (c == Cmp)
                {
                    c = Rep;
                    WUR(pwrite(fd, &c, 1, Off));
                    printf("Wrote %#X to ROM offset %X\n", c, Off);
                }
                else
                {
                    printf("Skip writing to ROM offset %X: %X != %X\n", Off, c, Cmp);
                }
            }
            Off += 8192;
        }
    }

    return ret;
}

bool modifyGenesis(int fd, struct codebits *decoded)
{
    bool ret = false;
    int Off, Rep;
    off_t filelen;
    unsigned char c;

    filelen = lof(fd);

    Off = decoded->off;
    Rep = decoded->rep;

    if (Off < filelen)
    {
        c = Rep >> 8;
        WUR(pwrite(fd, &c, 1, Off));
        printf("Wrote %#X to ROM offset %X\n", c, Off);
        c = Rep & 0xff;
        WUR(pwrite(fd, &c, 1, Off));
        printf("Wrote %#X to ROM offset %X\n", c, Off);
        ret = true;
    }

    return ret;
}

bool modifyNES(int fd, struct codebits *decoded)
{
    bool ret = false;
    int Num;
    int Off, Cmp, Rep;
    off_t filelen;
    unsigned char c;

    filelen = lof(fd);

    Off = decoded->off + 0x8000 - 0xc000;
    Cmp = decoded->cmp;
    Rep = decoded->rep;

    if (decoded->len == 6)
    {
        if (filelen % 1024 != 0)
        {
            Off += 16;
        }
        if (filelen >= 49169)
        {
            for (Num = 0; Num <= filelen / 8192; Num += 1)
            {
                if (Off < filelen)
                {
                    c = Rep;
                    WUR(pwrite(fd, &c, 1, Off));
                    printf("Wrote %#X to ROM offset %X\n", c, Off);
                    ret = true;
                }
                Off += 8192;
            }
        }
        else
        {
            c = Rep;
            WUR(pwrite(fd, &c, 1, Off));
            printf("Wrote %#X to ROM offset %X\n", c, Off);
            ret = true;
        }
    }

    if (decoded->len == 8)
    {
        if (filelen % 1024 != 0)
        {
            Off += 16;
        }
        for (Num = 0; Num <= filelen / 8192; Num += 1)
        {
            if (Off < filelen)
            {
                WUR(pread(fd, &c, 1, Off));
                if (c == Cmp)
                {
                    c = Rep;
                    WUR(pwrite(fd, &c, 1, Off));
                    printf("Wrote %#X to ROM offset %X\n", c, Off);
                    ret = true;
                }
                else
                {
                    printf("Skip writing to ROM offset %X: %X != %X\n", Off, c, Cmp);
                }
            }
            Off += 8192;
        }
    }

    return ret;
}

bool modifySNES(int fd, const struct codebits *decoded)
{
    bool ret = false;
    int Off, Rep;
    off_t filelen;
    unsigned char c;

    filelen = lof(fd);

    Off = decoded->off;
    Rep = decoded->rep;

    // Whether this ROM has a copier header on it.
    int romoffset = filelen % 1024 == 0 ? 0 : 512;

    // Detect ROM type.
    // https://snes.nesdev.org/wiki/ROM_header
    //   7FD5:   LoROM: 0x20 or 0x30
    //   FFD5:   HiROM: 0x21 or 0x31
    // 40FFD5: ExHiROM: 0x25 or 0x35
    WUR(pread(fd, &c, 1, 0x7FD5 + romoffset));
    if ((c & 0xef) == 0x20)
    {
        // LoROM.  Keep the low 15 address bits (A0-A14),
        // drop the 16th (A15), and shift the rest down by one.
        // https://snes.nesdev.org/wiki/Memory_map#LoROM
        printf("SNES LoROM detected\n");
        Off = (Off & 0x7fff) | ((Off & ~0xffff) >> 1);
    }
    else
    {
        WUR(pread(fd, &c, 1, 0xFFD5 + romoffset));
        if ((c & 0xef) == 0x21)
        {
            // https://snes.nesdev.org/wiki/Memory_map#HiROM
            printf("SNES HiROM detected\n");
        }
        else
        {
            WUR(pread(fd, &c, 1, 0x40FFD5 + romoffset));
            if ((c & 0xef) == 0x25)
            {
                // https://snes.nesdev.org/wiki/Memory_map#ExHiROM
                printf("SNES ExHiROM detected\n");
            }
            else
            {
                printf("Unable to detect SNES ROM type\n");
            }
        }
    }

    Off += romoffset;
    if (Off >= 4194304 && Off <= 8388607)
    {
        Off -= 4194304;
    }
    if (Off >= 8388608 && Off <= 12582911)
    {
        Off -= 8388608;
    }
    if (Off >= 12582912 && Off <= 16777215)
    {
        Off -= 12582912;
    }
    if (Off < filelen)
    {
        c = Rep;
        WUR(pwrite(fd, &c, 1, Off));
        printf("Wrote %#X to ROM offset %X\n", c, Off);
        ret = true;
    }

    return ret;
}
