# Game Genie Good Guy

Game Genie Good Guy is based on Game Genie Guy:

    This is a small Windows utility for applying Game Genie codes to roms. This saves you the trouble of having to enter them each time the game is played.

That tool is written in BCX-BASIC and the source code is [released with the Windows executable](https://www.romhacking.net/utilities/1054/) compatible with Game Boy/Game Gear/Genesis/Mega Drive/NES/SNES roms and generate rom patched ready to be shared.

The idea of the new project is to get that tool (or the patching engine) running on Linux with 0 experience on BASIC and C/C++ code, with a bit of knowledge with code compilation.

## Notes from original version

> Master System and PC Engine support added. Only use the codes from the supplied text files. Pro Action Replay codes are not supported.

> Not all codes like being applied in this fashion. Ex: Contra Hard Corps 99 lives work fine while infinite lives does not. If you do not get the desired result try another code.

> 8 digit NES codes are preferrable to 6. 8 digit codes contain validation that ensures the game is being patched in the right spot. 6 digit codes just go for it. Applying too many 6 digit codes can make a game crash. Try fewer codes if this occurs.

## Steps

* [UbxBasic for Linux](https://sourceforge.net/projects/ubxbasic/files/) to compile BASIC in C
* Understand how that [BCX-BASIC language](https://www.bcxbasiccoders.com/webhelp/BCXHelp.htm) works to patch [the original code](https://github.com/Mte90/Game-Genie-Good-Guy/blob/master/original/GGGuy.bas)
* Change that code to get cli support instead of GUI
* Some code optimizations
* Patch manually C code for compilers issues

# Parameters

    ./GGGG "[Codes one per line or combine with +]" [1-4] [originalrom] [newrom]

## ROM modes

Use that numbers to define the rom type

* *1*: Game Boy/Gear/Master System
* *2*: Genesis/Mega Drive (no SMD roms)
* *3*: Nintendo
* *4*: Super Nintendo

# Instructions

    ./GGGG "AJDV-4A4L+963B-4JAC" 2 ./rom.md ./rom-new.md

Multiple cheat code can be concatenated with `+` or new lines.

## Compile both versions

    ./compile.sh

This script will patch the C code for the various errors on converting it.

### Convert new BASIC version to C/C++

    ./generate.sh

### Check if the roms are different

    xxd rom.md > 1.hex
    xxd rom-new.md > 2.hex
    diff 1.hex 2.hex