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
//
// NB: The code must be uppercase already, and have - removed.

#ifndef GGGG_DECODE_H
#define GGGG_DECODE_H

#include <stdbool.h>
#include <stdint.h>

// A decoded game genie code.
struct codebits
{
    // Code length.
    uint32_t len;
    // Address.
    uint32_t off;
    // Data field.
    uint32_t rep;
    // Compare field.
    uint32_t cmp;
};

// Game Boy, Game Gear, Master System.
bool decodeGbGgMs(const char *code, struct codebits *decoded);
// Sega Genesis/Mega Drive.
bool decodeGenesis(const char *code, struct codebits *decoded);
// Nintendo.
bool decodeNES(const char *code, struct codebits *decoded);
// Super Nintendo.
bool decodeSNES(const char *code, struct codebits *decoded);

#endif
