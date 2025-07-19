#include <raylib.h>
#include "colors.h"
#include "food.h"
#include "settings.h"
#include "snake.h"

int main(void)
{
    InitWindow(CELL_SIZE * CELL_COUNT, CELL_SIZE * CELL_COUNT, "Snake");
    SetTargetFPS(60);

    Food food = Food();
    Snake snake = Snake();

    while(!WindowShouldClose()) 
    {
        BeginDrawing();

        ClearBackground(BACKGROUND);
        food.Draw();
        snake.Draw();

        EndDrawing();

    }
}