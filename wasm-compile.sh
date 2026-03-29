#!/bin/bash

set -ex
WASI_PV="32.0"
WASI_DIR="wasi-sdk-${WASI_PV}-x86_64-linux"
WASI_TAR="${WASI_DIR}.tar.gz"

if [[ ! -d "${WASI_DIR}" ]]; then
  wget -c "https://github.com/WebAssembly/wasi-sdk/releases/download/wasi-sdk-${WASI_PV%%.*}/${WASI_TAR}"
  tar xf "${WASI_TAR}"
fi

CC="${WASI_DIR}/bin/clang"
: "${OPT:=-O2}"
: "${CFLAGS:=${OPT} -pipe -std=c17}"

"${CC}" --sysroot="${WASI_DIR}/share/wasi-sysroot" \
  -target wasm32-wasip1 ${CFLAGS} GGGG.c copyfile.c decode.c modify.c -o GGGG.wasm -s
