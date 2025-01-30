#include <vector>
#include <utility>
#include "simulation.hpp"

void Simulation::Draw()
{
    grid.Draw();
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
        int neighbourRow = row + offset.first;
        int neighbourCol = column + offset.second;
    }
    return 0;
}
