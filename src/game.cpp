#include <raylib.h>
#include <raymath.h>
#include "game.h"
#include "snake.h"
#include "food.h"

void Game::Draw()
{
    food.Draw();
    snake.Draw();
}

void Game::Update()
{
    snake.Update();
    CheckCollisionWithFood();
}

void Game::ChangeSnakeDirection(Direction newDir)
{
    snake.SetDirection(newDir);
}

void Game::CheckCollisionWithFood()
{
    if(Vector2Equals(snake.GetHead(), food.GetPosition()))
    {
        food.GenerateNewPosition(snake);
    }
}