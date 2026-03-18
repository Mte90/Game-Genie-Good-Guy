#!/bin/sh
set -ex
: "${CC:=gcc}"
: "${CXX:=g++}"
: "${WFLAGS:=-Wall -Wformat -Wunused-variable}"
: "${OPT:=-Os}"
: "${CFLAGS:=${OPT} -pipe -std=c17}"
: "${CXXFLAGS:=${OPT} -pipe -std=c++17}"
: "${CPPFLAGS:=-D_FORTIFY_SOURCE=2}"
: "${PKG_CONFIG:=pkg-config}"
: "${GLIB_LIBS:=$(${PKG_CONFIG} glib-2.0 gio-2.0 --cflags --libs)}"
${CC} ${CFLAGS} ${WFLAGS} ${CPPFLAGS} GGGG.c copyfile.c ${GLIB_LIBS} -o GGGG
${CXX} ${CXXFLAGS} ${WFLAGS} ${CPPFLAGS} GGGG.cpp copyfile.c ${GLIB_LIBS} -o GGGG-cpp
if command -v i686-w64-mingw32-gcc >/dev/null; then
  i686-w64-mingw32-gcc ${CFLAGS} ${WFLAGS} ${CPPFLAGS} -U_FORTIFY_SOURCE GGGG.c copyfile.c -o GGGG.exe
  i686-w64-mingw32-g++ ${CXXFLAGS} ${WFLAGS} ${CPPFLAGS} -U_FORTIFY_SOURCE GGGG.cpp copyfile.c -o GGGG-cpp.exe
fi
