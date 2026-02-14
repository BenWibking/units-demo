# units_prototype

Small standalone C++23 demo showing how to use [`mp-units`](https://github.com/mpusz/mp-units) with custom CGS-Gaussian units.

## What This Repo Contains

- `mp_units_cgs_demo.cpp`: Demo program defining:
  - `gauss` (`G`) in a CGS-Gaussian context
  - `code_gauss` (`code_G`) as a scaled magnetic-field unit
  - an example derived quantity `u_B = 0.5 * B^2`
- `CMakeLists.txt`: Top-level build config for the demo
- `mp-units/`: vendored dependency as a git submodule

## Requirements

- CMake 3.25+
- C++23 compiler
- LLVM Clang (AppleClang is explicitly rejected by this project)

On Apple Silicon macOS, LLVM Clang is typically at:

```bash
/opt/homebrew/opt/llvm/bin/clang++
```

## Clone

This repo uses a submodule, so clone with:

```bash
git clone --recurse-submodules <repo-url>
cd units_prototype
```

If you already cloned without submodules:

```bash
git submodule update --init --recursive
```

## Build

```bash
cmake -S . -B build-llvm \
  -DCMAKE_CXX_COMPILER=/opt/homebrew/opt/llvm/bin/clang++
cmake --build build-llvm -j
```

## Run

```bash
./build-llvm/mp_units_cgs_demo
```

Example output:

```text
  ASD unit sample  = 3 1/Hz^(1/2)

Electromagnetic quantities:
  magnetic field   = 125 G
  code B field     = 125 code_G
  u_B = 0.5*B^2    = 7812.5 code_G² = 621.699 Ba
```

## Notes

- The top-level build sets `mp-units` options to keep this demo dependency-free in this standalone configuration.
- This is a focused prototype/example, not a full application framework.
