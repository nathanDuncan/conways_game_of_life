// Imports
#include <raylib.h>
#include "simulation.hpp"
#include <iostream>

int main()
{
    // Create simulation window
    // std::cout << GetMonitorCount() << std::endl;
    // const int WINDOW_WIDTH = GetMonitorWidth(0);
    // std::cout << WINDOW_WIDTH << std::endl;
    // const int WINDOW_HEIGHT = GetMonitorHeight(0);
    // std::cout << WINDOW_HEIGHT << std::endl;
    int WINDOW_WIDTH = 1920;
    int WINDOW_HEIGHT = 1080;
    const int CELL_SIZE = 4;
    int FPS = 12;

    Color GREY = {0, 0, 0, 255};
    long t = 0;

    SetConfigFlags(FLAG_FULLSCREEN_MODE);
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
    SetTargetFPS(FPS);
    Simulation simulation{WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE};

    Vector2 mousePosition = GetMousePosition(); // Get the current mouse position

    /*** Simulation loop ***/ 
    while (!WindowShouldClose())
    {
        // Event Handeling
    

        // Update state
        simulation.Update();

        mousePosition = GetMousePosition(); // Get the current mouse position
        // DrawText(TextFormat("Mouse Position: %.2f, %.2f", mousePosition.x, mousePosition.y), 10, 10, 20, WHITE); // Display the mouse position
        simulation.MouseCells(int(mousePosition.y/CELL_SIZE), int(mousePosition.x/CELL_SIZE));

        // Drawing
        BeginDrawing();
        ClearBackground(GREY);
        simulation.Draw(t);
        EndDrawing();

        t++;

    }

    CloseWindow();
    return 0;
}
