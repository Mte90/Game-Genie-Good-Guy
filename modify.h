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

#ifndef GGGG_MODIFY_H
#define GGGG_MODIFY_H

#include <stdbool.h>

#include "decode.h"

// Raw offset & value.
bool modifyRaw(int fd, const char *ext, struct codebits *decoded);
// Game Boy, Game Gear, Master System.
bool modifyGbGgMs(int fd, struct codebits *decoded);
// Sega Genesis/Mega Drive.
bool modifyGenesis(int fd, struct codebits *decoded);
// Nintendo.
bool modifyNES(int fd, struct codebits *decoded);
// Super Nintendo.
bool modifySNES(int fd, const struct codebits *decoded);

#endif
