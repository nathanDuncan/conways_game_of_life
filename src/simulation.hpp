#pragma once
#include "grid.hpp"

class Simulation
{
    public:
        Simulation(int width, int height, int cellSize)
        : grid(width, height, cellSize), tempGrid(width, height, cellSize) {grid.FillRandom();};
        void Draw(long t);
        void SetCellValue(int row, int column, int value);
        int CountLiveNeighbours(int row, int column);
        void Update();
        void MouseCells(int row, int column);
    private: 
        Grid grid;
        Grid tempGrid;
};