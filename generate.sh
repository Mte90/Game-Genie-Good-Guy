#!/bin/sh

sed -i "s/\$CPP/\'\$CPP/g" GGGG.bas
./UbxBasic/UbxBasic GGGG && ./UbxBasic/InsertOptArg GGGG.c && echo "\n"
sed -i 's/gCopyFile File1, File2\;/gCopyFile \(File1, File2,true\)\;/g' GGGG.c
sed -i 's/goto L0/exit\(1\)/g' GGGG.c

sed -i "s/'\$CPP/\$CPP/g" GGGG.bas
./UbxBasic/UbxBasic GGGG
sed -i 's/gCopyFile File1, File2\;/gCopyFile \(File1, File2,true\)\;/g' GGGG.cpp
sed -i 's/goto L0/exit\(1\)/g' GGGG.cpp
