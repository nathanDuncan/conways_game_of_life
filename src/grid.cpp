#include <raylib.h>
#include <iostream>
#include <cmath>
#include "grid.hpp"

void Grid::Draw(long t)
{
    for(int row =0 ; row < rows; row++)
    {
        for(int column = 0; column < columns; column++)
        {
            Color color = cells[row][column] ? Color{255, 0, double(((sin((double(t)/255.)*(2*M_PI))+1)/2.)*255.), 255} : Color{0, 0, 0, 255};
            DrawRectangle(column * cellSize, row * cellSize, cellSize - 1, cellSize - 1, color);
        }
    }
}

void Grid::SetValue(int row, int column, int value)
{
    if(IsWithinBounds(row, column))
    {
        cells[row][column] = value;
    }
    else
    {
        std::cout << "[INFO] Failure to set cell " << row << ", " << column << std::endl;
    }
}

int Grid::GetValue(int row, int column)
{
    if(IsWithinBounds(row, column))
    {
        return cells[row][column];
    }
    return 0;
}

void Grid::FillRandom()
{
    for(int row = 0; row < rows; row++)
    {
        for(int column = 0; column < columns; column++)
        {
            int randomValue = GetRandomValue(0, 4);
            cells[row][column] = (randomValue == 4) ? 1 : 0;
        }
    }
}

bool Grid::IsWithinBounds(int row, int column)
{
    if(row >= 0 && row < rows && column >=0 && column < columns)
    {
        return true;
    }
    return false;
}
