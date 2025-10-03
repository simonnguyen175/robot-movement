# Robot Movement — Bresenham Line Drawer

> A small C++ console app that reads commands (DIMENSION / MOVE_TO / LINE_TO),
> draws **Bresenham lines** on an `N×N` grid, and prints the final board.

---
## Problem & Rules

- Grid: `N×N`, coordinates `(0,0)` at **top-left**, `(N-1,N-1)` bottom-right.
- Robot starts at `(0,0)` and is considered at **cell centers** (integer grid).
- Commands:
  - `DIMENSION N` — initialize grid (N>0).
  - `MOVE_TO x,y` — move without drawing (0 ≤ x,y < N).
  - `LINE_TO x,y` — draw with **Bresenham**, mark all traversed cells with `"+"`.

## Installation (Compiler + Build Tools)

You need three tools to build this project:

1. **GCC / G++ (compiler)**  
   Provided by MSYS2 (UCRT64 toolchain).
2. **CMake (build system generator)**  
3. **Ninja (build tool)**  

### On Windows (MSYS2 UCRT64 recommended)
1. Install [MSYS2](https://www.msys2.org/).  
2. Open **MSYS2 UCRT64 terminal**.  
3. Install all required packages in one command:
   ```
   pacman -S mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-cmake ninja
   ```

### Quick start 
```
# build (CMake + Ninja)
mkdir build && cd build
cmake -G Ninja ..
cmake --build .

# run with a file
.\robot.exe ..\input.txt
```
