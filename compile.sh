#!/bin/sh
set -ex
gcc -pipe -Wall -Os -Wformat -Wunused-variable -D_FORTIFY_SOURCE=2 -std=c17 GGGG.c copyfile.c $(pkg-config glib-2.0 gio-2.0 --cflags --libs) -o GGGG
g++ -pipe -Wall -Os -Wformat -D_FORTIFY_SOURCE=2 -std=c++17 GGGG.cpp copyfile.c $(pkg-config glib-2.0 gio-2.0 --cflags --libs) -o GGGG-cpp
