#!/bin/sh

gcc -Wall -Os -Wformat -Wunused-variable -D_FORTIFY_SOURCE=2 GGGG.c $(pkg-config glib-2.0 gio-2.0 --cflags --libs) -o GGGG -lm
g++ -Wall -Os -Wformat -D_FORTIFY_SOURCE=2 -std=c++11 GGGG.cpp $(pkg-config glib-2.0 gio-2.0 --cflags --libs) -o GGGG-cpp -lm -fpermissive
