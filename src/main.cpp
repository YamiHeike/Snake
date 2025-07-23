#include <raylib.h>
#include "game.h"
#include "colors.h"
#include "settings.h"

double lastUpdateTime = 0;

bool eventTriggered(double interval)
{
    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main(void)
{
    InitWindow(CELL_SIZE * CELL_COUNT, CELL_SIZE * CELL_COUNT, "Snake");
    SetTargetFPS(60);
    Game game = Game();
    while(!WindowShouldClose()) 
    {
        if(IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) game.ChangeSnakeDirection(UP);
        if(IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) game.ChangeSnakeDirection(DOWN);
        if(IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) game.ChangeSnakeDirection(RIGHT);
        if(IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) game.ChangeSnakeDirection(LEFT);    
        BeginDrawing();
        if(eventTriggered(0.1)) 
        {
            game.Update();
        }
        ClearBackground(BACKGROUND);
        game.Draw();
        EndDrawing();
    }
}