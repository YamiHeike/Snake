#include <raylib.h>
#include "colors.h"
#include "food.h"
#include "settings.h"
#include "snake.h"

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

    Food food = Food();
    Snake snake = Snake();

    while(!WindowShouldClose()) 
    {
        if(IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) snake.SetDirection(UP);
        if(IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) snake.SetDirection(DOWN);
        if(IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) snake.SetDirection(RIGHT);
        if(IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) snake.SetDirection(LEFT);
        
        BeginDrawing();
        if(eventTriggered(0.1)) 
        {
            snake.Update();
        }
        ClearBackground(BACKGROUND);
        food.Draw();
        snake.Draw();
        EndDrawing();
    }
}