#!/bin/sh

gcc -Wall -Os -Wformat -Wunused-variable -D_FORTIFY_SOURCE=2  -ldl GGGG.c  $(pkg-config gtk+-3.0 glib-2.0 --cflags --libs ) -o GGGG -lm -lgmodule-2.0 
g++ -Wall -Os -Wformat -D_FORTIFY_SOURCE=2 -std=c++11 GGGG.cpp -ldl $(pkg-config gtk+-3.0 glib-2.0 --cflags --libs )  -o GGGG-cpp -lm -lgmodule-2.0 -fpermissive
