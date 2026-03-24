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

// Game Genie decoder functions.

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "decode.h"

bool decodeRaw(const char *code, struct codebits *decoded)
{
    int addr, value;
    if (sscanf(code, "%x:%x", &addr, &value) != 2)
    {
        fprintf(stderr, "%s: raw codes must use <address>:<value> syntax\n", code);
        return false;
    }

    decoded->len = 0;
    decoded->off = addr;
    decoded->rep = value;
    decoded->cmp = 0;

    return true;
}

bool decodeGbGgMs(const char *code, struct codebits *decoded)
{
    size_t num;
    uint32_t nibbles[9];

    decoded->len = strlen(code);
    if (decoded->len != 6 && decoded->len != 9)
    {
        fprintf(stderr, "%s: invalid code length: must be 6 or 9\n", code);
        return false;
    }

    for(num = 0; code[num]; num += 1)
    {
        switch (code[num])
        {
            case '0' ... '9':
                nibbles[num] = code[num] - '0';
                break;
            case 'A' ... 'F':
                nibbles[num] = code[num] - 'A' + 0xa;
                break;
            default:
                fprintf(stderr, "%s: invalid code letter '%c'\n", code, code[num]);
                return false;
        }
    }

    decoded->rep = nibbles[1] | (nibbles[0] << 4);
    decoded->off =
        (nibbles[2] << 0x8) |
        (nibbles[3] << 0x4) |
        nibbles[4] |
        ((~nibbles[5] & 0xF) << 12);

    if(decoded->len == 9)
    {
        uint32_t temp = nibbles[8] | (nibbles[6] << 4);
        temp = (temp >> 2) | ((temp << 6) & 0xFC);
        decoded->cmp = (temp ^ 0xBA);
    }
    else
    {
        decoded->cmp = 0;
    }

    return true;
}

bool decodeGenesis(const char *code, struct codebits *decoded)
{
    size_t num;
    uint32_t bits[8];

    decoded->len = strlen(code);
    if (decoded->len != 8)
    {
        fprintf(stderr, "%s: invalid code length: must be 8\n", code);
        return false;
    }

    for(num = 0; code[num]; num += 1)
    {
        bits[num] = 0;
        switch (code[num])
        {
            case '0' ... '9':
                bits[num] = 0x16 + (code[num] - '0');
                break;
            case 'Z':
                bits[num]++;
            case 'Y':
                bits[num]++;
            case 'X':
                bits[num]++;
            case 'W':
                bits[num]++;
            case 'V':
                bits[num]++;
            case 'T':
                bits[num]++;
            case 'S':
                bits[num]++;
            case 'R':
                bits[num]++;
            case 'P':
                bits[num]++;
            case 'N':
                bits[num]++;
            case 'M':
                bits[num]++;
            case 'L':
                bits[num]++;
            case 'K':
                bits[num]++;
            case 'J':
                bits[num]++;
            case 'H':
                bits[num]++;
            case 'G':
                bits[num]++;
            case 'F':
                bits[num]++;
            case 'E':
                bits[num]++;
            case 'D':
                bits[num]++;
            case 'C':
                bits[num]++;
            case 'B':
                bits[num]++;
            case 'A':
                break;
            default:
                fprintf(stderr, "%s: invalid code letter '%c'\n", code, code[num]);
                return false;
        }
    }

    decoded->off =
        ((bits[1] & 0x3) << 14) |
        (bits[2] << 9) |
        ((bits[3] & 0x10) << 4) |
        ((bits[3] & 0xF) << 20) |
        ((bits[4] & 0x1E) << 15) |
        ((bits[6] & 0x3) << 5) |
        bits[7];
    decoded->rep =
        (bits[0] << 3) |
        ((bits[1] & 0x1C) >> 2) |
        ((bits[4] & 0x1) << 12) |
        ((bits[5] & 0x1E) << 7) |
        ((bits[5] & 0x1) << 15) |
        ((bits[6] & 0x18) << 10);
    decoded->cmp = 0;

    return true;
}

bool decodeNES(const char *code, struct codebits *decoded)
{
    size_t num;
    uint32_t nibbles[8];

    decoded->len = strlen(code);
    if (decoded->len != 6 && decoded->len != 8)
    {
        fprintf(stderr, "%s: invalid code length: must be 6 or 8\n", code);
        return false;
    }

    for(num = 0; code[num]; num += 1)
    {
        nibbles[num] = 0;
        switch (code[num])
        {
            case 'N':
                nibbles[num]++;
            case 'V':
                nibbles[num]++;
            case 'S':
                nibbles[num]++;
            case 'K':
                nibbles[num]++;
            case 'U':
                nibbles[num]++;
            case 'X':
                nibbles[num]++;
            case 'O':
                nibbles[num]++;
            case 'E':
                nibbles[num]++;
            case 'Y':
                nibbles[num]++;
            case 'T':
                nibbles[num]++;
            case 'I':
                nibbles[num]++;
            case 'G':
                nibbles[num]++;
            case 'L':
                nibbles[num]++;
            case 'Z':
                nibbles[num]++;
            case 'P':
                nibbles[num]++;
            case 'A':
                break;
            default:
                fprintf(stderr, "%s: invalid code letter '%c'\n", code, code[num]);
                return false;
        }
    }

    decoded->off =
        ((nibbles[3] & 7) << 12) |
        ((nibbles[5] & 7) << 8) |
        ((nibbles[4] & 8) << 8) |
        ((nibbles[2] & 7) << 4) |
        ((nibbles[1] & 8) << 4) |
        (nibbles[4] & 7) |
        (nibbles[3] & 8);

    if(decoded->len == 6)
    {
        decoded->cmp = 0;
        decoded->rep =
            ((nibbles[1] & 7) << 4) |
            ((nibbles[0] & 8) << 4) |
            (nibbles[0] & 7) |
            (nibbles[5] & 8);
    }
    else if(decoded->len == 8)
    {
        decoded->cmp =
            ((nibbles[7] & 7) << 4) |
            ((nibbles[6] & 8) << 4) |
            (nibbles[6] & 7) |
            (nibbles[5] & 8);
        decoded->rep =
            ((nibbles[1] & 7) << 4) |
            ((nibbles[0] & 8) << 4) |
            (nibbles[0] & 7) |
            (nibbles[7] & 8);
    }

    return true;
}

bool decodeSNES(const char *code, struct codebits *decoded)
{
    size_t num;
    uint32_t nibbles[8];

    decoded->len = strlen(code);
    if (decoded->len != 8)
    {
        fprintf(stderr, "%s: invalid code length: must be 8\n", code);
        return false;
    }

    for(num = 0; code[num]; num += 1)
    {
        nibbles[num] = 0;
        switch (code[num])
        {
            case 'E':
                nibbles[num]++;
            case '3':
                nibbles[num]++;
            case '2':
                nibbles[num]++;
            case 'A':
                nibbles[num]++;
            case '8':
                nibbles[num]++;
            case 'C':
                nibbles[num]++;
            case 'B':
                nibbles[num]++;
            case '6':
                nibbles[num]++;
            case '5':
                nibbles[num]++;
            case '1':
                nibbles[num]++;
            case '9':
                nibbles[num]++;
            case '0':
                nibbles[num]++;
            case '7':
                nibbles[num]++;
            case '4':
                nibbles[num]++;
            case 'F':
                nibbles[num]++;
            case 'D':
                break;
            default:
                fprintf(stderr, "%s: invalid code letter '%c'\n", code, code[num]);
                return false;
        }
    }

    decoded->off =
        (nibbles[4] & 0x3) << 22 |
        (nibbles[5] & 0xC) << 18 |
        (nibbles[6] & 0x3) << 18 |
        (nibbles[7] & 0xC) << 14 |
        (nibbles[2] << 12) |
        (nibbles[7] & 0x3) << 10 |
        (nibbles[4] & 0xC) << 6 |
        (nibbles[3] << 4) |
        (nibbles[5] & 0x3) << 2 |
        (nibbles[6] & 0xC) >> 2;
    decoded->rep = (nibbles[0] << 4) | nibbles[1];
    decoded->cmp = 0;

    return true;
}
