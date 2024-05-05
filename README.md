# Genie

Patch your rom with Game Genie codes

- Author: [Tuncay D.](https://github.com/thingsiplay)
- Source: [Github](https://github.com/thingsiplay/genie)
- License: [GPL-3.0 license](LICENSE)

## What is this?

A simple command line application to patch game ROMs with Game Genie codes to
play them with an emulator. With the optional script a dialog based GUI can
be invoked to automate a few steps, creating the patched ROM, a BPS patch file
and an additional log file.

### Origin

I did not write the C program; this is a fork, of a fork. This project is based
on Game Genie Good Guy, which is based on Game Genie Guy. **GGGG** is the short
name for "**G**ame **G**enie **G**ood **G**uy".

1. [Game Genie Guy](https://www.romhacking.net/utilities/1054/), 2015: The
   original tool is written by Kyle in BCX-BASIC and is released for Windows.
2. [Game Genie Good Guy](https://github.com/Mte90/Game-Genie-Good-Guy), 2020:
   Mte90 took the source code and converted it into C language, made it run on
   Linux and added a GUI written in Python with QT on top of it.
3. [This](https://github.com/thingsiplay/genie), 2024: I forked
   this new "enhanced" version and removed most (to me) unnecessary stuff from
   the repository and added my own dialog based GUI.

## Installation

This project comes with `GGGG`, the main standalone command line program
written in C. An additional custom script `genie` is provided as well, to
automate a few steps with a graphical dialog system.

- build `GGGG` using a C compiler
- install `kdialog` and `flips` as a dependency for `genie`
- copy `GGGG` and `genie` into a folder that is in the $PATH

### Get the code

```bash
git clone "https://github.com/thingsiplay/genie"
cd "genie"
```

### Build GGGG

The main application **GGGG** is written in C and needs must be compiled with a
C compiler. Compile with the command, which will invoke `gcc`:

```bash
make
```

On success, an executable file named `GGGG` should be available now.
Unfortunately at this stage I am not able to give a full list of required
libraries and programs to build it.

## Usage

```bash
GGGG [CODES] [ROM_TYPE] [INPUT_FILE] [OUTPUT_FILE]
```

All arguments are required.

- `CODES`: Game Genie codes to inject into the ROM. Multiple codes can be
  combined with `+` or newline character.
- `ROM_TYPE`: The game system of the input ROM as a number:
  - **1**=Game Boy/Game Gear/Master System,
  - **2**=Genesis/Mega Drive (no SMD roms),
  - **3**=NES,
  - **4**=Super Nintendo
- `INPUT_FILE`: Path to the unaltered original game ROM file to patch on.
- `OUTPUT_FILE`: Path to the patched game ROM file to save as.

### Example

```bash
GGGG "AJDV-4A4L+963B-4JAC" 2 ./rom.md ./rom-new.md
```

### Genie dialog script

The programs `GGGG`, `kdialog` and `flips` need to be in a directory that is in
the $PATH.

```bash
genie [INPUT_FILE]
```

Argument is optional. Without `INPUT_FILE` the script will ask to select a
file.

- `INPUT_FILE`: Path to the unaltered game ROM file or a directory. If this is
  a directory, then script will ask to select a file in that specified folder.

The other parameters are determined by follow up graphical dialogs. Output file
names and formats are determined automatically, based on user input and
original file name. The script will also create a little log file as well.

## See also

### Tools

- [Game Genie Guy](https://www.romhacking.net/utilities/1054/)
- [Game Genie Good Guy](https://www.romhacking.net/utilities/1484/) / [Source](https://github.com/Mte90/Game-Genie-Good-Guy)
- [Flips](https://www.romhacking.net/utilities/1040/) / [Source](https://github.com/Alcaro/Flips)

### Websites with Codes

- [GameHacking](https://gamehacking.org/)
- [GameGenie](https://www.gamegenie.com/)
