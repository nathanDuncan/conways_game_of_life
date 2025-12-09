# Conway’s Game of Life

A minimal C++ implementation of **Conway’s Game of Life**, a classic zero-player cellular automaton where simple rules generate complex emergent behavior.  
I originally started this project as a C++ refresher and now use the executable as an aesthetic background when my laptop is not in idle.

---

## Demo

<p align="center">
  <img src="./gol_demo.gif" alt="Conway's Game of Life demo" width="800">
</p>

---

## Rules

Conway’s Game of Life is played on a 2D grid of cells that are either **alive** or **dead**.  
Each step (“generation”), the grid updates according to these rules:

1. **Stasis** — Any *live* cell with **2 or 3** live neighbors survives.  
2. **Reproduction** — Any *dead* cell with **exactly 3** live neighbors becomes alive.  
3. **Under/Overpopulation** — Any *live* cell with **fewer than 2** or **more than 3** live neighbors dies.

---

## Build & Run

```bash
g++ -std=c++17 -O2 main.cpp -o game_of_life
./game_of_life
