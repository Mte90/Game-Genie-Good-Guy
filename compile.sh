#!/bin/sh

sed -i 's/gCopyFile File1, File2\;/gCopyFile \(File1, File2,true\)\;/g' GGGG.c
sed -i 's/goto L0/exit\(1\)/g' GGGG.c
gcc -Wall -Os -Wformat -Wunused-variable -D_FORTIFY_SOURCE=2  -ldl GGGG.c  $(pkg-config gtk+-3.0 glib-2.0 --cflags --libs ) -o GGGG -lm -lgmodule-2.0 
