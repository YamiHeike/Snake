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
    InitWindow(2 * OFFSET + CELL_SIZE * CELL_COUNT, 2 * OFFSET + CELL_SIZE * CELL_COUNT, "Snake");
    SetTargetFPS(60);
    Game game = Game();
    while(!WindowShouldClose()) 
    {
        if(IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) game.ChangeSnakeDirection(UP);
        if(IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) game.ChangeSnakeDirection(DOWN);
        if(IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) game.ChangeSnakeDirection(RIGHT);
        if(IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) game.ChangeSnakeDirection(LEFT);  
        if(game.CheckGameOver() && GetKeyPressed())
        {
            game.PlayAgain();
        }  
        BeginDrawing();
        if(eventTriggered(0.1)) 
        {
            game.Update();
        }
        ClearBackground(BACKGROUND);
        DrawRectangleLinesEx(Rectangle{static_cast<float>(OFFSET - 5), static_cast<float>(OFFSET -5), static_cast<float>(CELL_SIZE * CELL_COUNT + 10), static_cast<float>(CELL_SIZE * CELL_COUNT + 10)}, 5, ACCENT);
        int fontSize = 40;
        DrawText("SNAKE", OFFSET, 20, fontSize, ACCENT);
        DrawText(TextFormat("%i", game.GetScore()), OFFSET - 5, OFFSET + CELL_SIZE*CELL_COUNT + 10, 40, ACCENT);
        game.Draw();
        EndDrawing();
    }
}