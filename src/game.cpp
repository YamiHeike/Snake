#include <raylib.h>
#include <raymath.h>
#include "game.h"
#include "snake.h"
#include "food.h"

#include <iostream>

void Game::Draw()
{
    food.Draw();
    snake.Draw();
}

void Game::Update()
{
    snake.Update();
    CheckCollisionWithFood();
    CheckCollisionWithEdges();
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
        snake.Grow();
    }
}

void Game::CheckCollisionWithEdges()
{
    Vector2 snakeHead = snake.GetHead();
    if(snakeHead.x == CELL_COUNT || snakeHead.x == -1 || snakeHead.y == CELL_COUNT || snakeHead.y == -1)
    {
        GameOver(); 
    }
}

// TODO: implement game over logic
void Game::GameOver()
{
    std::cout << "Game over" << std::endl;
}