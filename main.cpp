#include <iostream>

extern "C" {
    #include "raylib.h"
}

int main()
{
    InitWindow(800, 450, "Hello Raylib!");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Hello World from Raylib!", 190, 200, 20, BLACK);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
