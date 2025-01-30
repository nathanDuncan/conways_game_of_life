// Imports
#include <raylib.h>
#include "simulation.hpp"

int main()
{
    // Create simulation window
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;
    const int CELL_SIZE = 25;
    int FPS = 12;

    Color GREY = {29, 29, 29, 255};

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
    SetTargetFPS(FPS);
    Simulation simulation{WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE};

    simulation.SetCellValue(3,4, 1);

    

    /*** Simulation loop ***/ 
    while (!WindowShouldClose())
    {
        // Event Handeling

        // Update state

        // Drawing
        BeginDrawing();
        ClearBackground(GREY);
        simulation.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
