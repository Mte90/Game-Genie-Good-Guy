# Game Genie Good Guy Web

TL;DR: Visit https://mte90.github.io/Game-Genie-Good-Guy/

This is GGGG for the web! Any recent browser should work with it, although only
Chrome has been tested so far.

## How Does It Work!?

The GGGG source is simple enough that it can be easily compiled using the
[WASI SDK]. This produces a [WASM] (WebAssembly) program using [WASI] (the
WebAssembly System Interface).

The [WASI JavaScript Bindings] project is used to run that WASM program in
your browser. See [GGGG.js](./GGGG.js) for details.

A simple web UI brings it altogether.

[WASI]: https://wasi.dev/
[WASI SDK]: https://github.com/webassembly/wasi-sdk
[WASI JavaScript Bindings]: https://chromium.googlesource.com/apps/libapps/+/HEAD/wasi-js-bindings/
[WASM]: https://webassembly.org/
