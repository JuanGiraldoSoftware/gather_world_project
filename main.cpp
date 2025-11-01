#include <iostream>

extern "C" {
    #include "raylib.h"
}

void EventPlayerMove(Vector2& dPlayerPos){

    if (IsKeyDown(KEY_D)) dPlayerPos.x+=2.0f;
    if (IsKeyDown(KEY_A)) dPlayerPos.x-=2.0f;
    if (IsKeyDown(KEY_W)) dPlayerPos.y-=2.0f;
    if (IsKeyDown(KEY_S)) dPlayerPos.y+=2.0f;

}

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Hello Raylib!");

    Vector2 playerPos = { (float)screenWidth/2, (float)screenHeight/2 }; // Screen center
    Vector2 resourcePos = { (float)screenWidth/2 + 20, (float)screenHeight/2 + 20};

    SetTargetFPS(60); //Setting game frames-per-second dif.
    
    while (!WindowShouldClose())
    {
        EventPlayerMove(playerPos);

        BeginDrawing();

            ClearBackground(RAYWHITE);
            //Player Updater
            DrawCircleV(playerPos, 10, BLACK);
            //Resources
            DrawCircleV(resourcePos, 7, RED);
        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
