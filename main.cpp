#include <iostream>

#include "raylib.h"


void DisplayActionButton(Vector2 Player,Vector2 Resource){
    if(CheckCollisionCircles(Player,10,Resource,7)){ // Displaying ACTION BUTTON on Collision. 
        DrawRectangle(Resource.x+5,Resource.y+5, 80,20, BLUE);
        const char* text_button = " Gather";
        DrawText(text_button, (int)Resource.x+5, (int)Resource.y+5,20,WHITE);
    }
}

void TriggerHoverOverActionButton(Rectangle btn, bool& hoverOver){
    if(CheckCollisionPointRec(GetMousePosition(), btn)){
        hoverOver=true;
        DrawRectangle(btn.x+5,btn.y+5, 110,30, BLUE);
        const char* text_button = " Gather";
        DrawText(text_button, (int)btn.x+5, (int)btn.y+5,30,WHITE);
    }else{
        hoverOver=false;
    }

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

    bool hover = false;

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
            //std::cout<<hover<<std::endl;
            if(!hover) DisplayActionButton(playerPos,resourcePos);
            TriggerHoverOverActionButton({resourcePos.x+5,resourcePos.y+5, 80,20},hover);
        EndDrawing();

    }

    CloseWindow();
    return 0;
}
