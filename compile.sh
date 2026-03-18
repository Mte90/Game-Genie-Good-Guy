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
