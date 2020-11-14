# Overview

Example single page app (SPA) web project written in C++ using [asm-dom](https://github.com/mbasso/asm-dom) via
[cmake-asm-dom](https://github.com/jimmyorourke/cmake-asm-dom-wrapper) for virtual DOM
manipulation. 

Based on http://www.sheshbabu.com/posts/rust-wasm-yew-single-page-application/
but with C++ instead of Rust and without any frameworks.

[Live demo](https://jimmyorourke.github.io/cppmart-asmdom)

## Build

```
mkdir build && cd build
emcmake cmake -G Ninja ..
ninja
```
Then server with `python3 -m http.server`



