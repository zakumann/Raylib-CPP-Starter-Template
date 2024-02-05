#include <iostream>
#include <raylib.h>

using namespace std;

int main () 
{
    // window dimensions
    const int windowWidth{512};
    const int windowHeight{380};
    // initialize the window
    InitWindow(windowWidth, windowHeight, "Dapper Dasher!");

    // acceleration due to gravity (pixels/frame)/frame
    const int gravity{1};
    const int jumpVel{-22};
    bool isInAir{};

    // rectangle dimensions
    const int width{ 50 };
    const int height{ 80 };

    int posY{ windowHeight - height };
    int velocity{0};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        // start drawing
        BeginDrawing();
        ClearBackground(WHITE);

        // ground check
        if (posY >= windowHeight - height )
        {
            // rectangle is on the ground
            velocity = 0;
            isInAir = false;
        } 
        else
        {
            // rectangle is in the air
            velocity += gravity;
            isInAir = true;
        }
        // check for jumping
        if (IsKeyPressed(KEY_SPACE) && !isInAir)
        {
            velocity += jumpVel;
        }

        // update position
        posY += velocity;

        DrawRectangle(windowWidth/2, posY, width, height, BLUE);
        
        // stop drawing
        EndDrawing();
    }
    CloseWindow();
}