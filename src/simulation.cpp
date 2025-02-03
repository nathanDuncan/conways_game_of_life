#include <vector>
#include <utility>
#include <iostream>
#include "simulation.hpp"

void Simulation::Draw(long t)
{
    grid.Draw(t);
}

void Simulation::SetCellValue(int row, int column, int value)
{
    grid.SetValue(row, column, value);
}

int Simulation::CountLiveNeighbours(int row, int column)
{
    int liveNeighbours = 0;

    std::vector<std::pair<int, int>> neighgourOffsets = 
    {
        {-1,  0}, // Directly Above
        { 1,  0}, // Directly Below
        { 0, -1}, // To the left
        { 0,  1}, // To the right
        {-1, -1}, // Diagonal upper left
        {-1,  1}, // Diagonal upper right
        { 1, -1}, // Diagonal lower left
        { 1,  1}  // Diagonal lower right

    };

    for (const auto& offset : neighgourOffsets)
    {
        // Toroidal Grid: wrap around on edges
        int neighbourRow = (row + offset.first + grid.GetRows()) % grid.GetRows();
        int neighbourCol = (column + offset.second + grid.GetColumns()) % grid.GetColumns();
        liveNeighbours += grid.GetValue(neighbourRow, neighbourCol);
    }
    return liveNeighbours;
}

void Simulation::Update()
{
    for(int row = 0; row < grid.GetRows(); row++)
    {
        for(int column = 0; column < grid.GetColumns(); column++)
        {
            int liveNeighbours = CountLiveNeighbours(row, column);

            int cellValue = grid.GetValue(row, column);
            
            if(cellValue == 1)
            {
                // Condensed Rule 1:
                //    A cell with more than three or less than two neighbours dies
                if(liveNeighbours > 3 || liveNeighbours < 2)
                {
                    tempGrid.SetValue(row, column, 0);
                }
                else
                {
                    tempGrid.SetValue(row, column, 1);
                }
            }
            else
            {
                // Condensed Rule 2:
                //    A cell with exactly three neighbours becomes alive.
                if(liveNeighbours == 3)
                {
                    tempGrid.SetValue(row, column, 1);
                }
                else
                {
                    tempGrid.SetValue(row, column, 0);
                }
            }
        }
    }


    grid = tempGrid;
}

void Simulation::MouseCells(int row, int column)
{
    std::vector<std::pair<int, int>> neighgourOffsets = 
    {
        { 0,  0}, // Cell with mouse
        { 1,  0}, // Directly Below
        { 0,  1}, // To the right
        { 1,  1}  // Diagonal lower right
    };

    for (const auto& offset : neighgourOffsets)
    {
        // Toroidal Grid: wrap around on edges
        int neighbourRow = (row + offset.first + grid.GetRows()) % grid.GetRows();
        int neighbourCol = (column + offset.second + grid.GetColumns()) % grid.GetColumns();
        grid.SetValue(neighbourRow, neighbourCol, 1);
    }
}
