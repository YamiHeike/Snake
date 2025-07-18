#include <raylib.h>
#include "colors.h"
#include "food.h"
#include "settings.h"

typedef enum GameScreen { LOGO = 0, TITLE, GAMEPLAY, ENDING } GameScreen;


int main(void)
{
    InitWindow(CELL_SIZE * CELL_COUNT, CELL_SIZE * CELL_COUNT, "Snake");
    SetTargetFPS(60);

    Food food = Food();

    while(!WindowShouldClose()) 
    {
        BeginDrawing();

        ClearBackground(BACKGROUND);
        food.Draw();

        EndDrawing();

    }
}