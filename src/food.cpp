#include <raylib.h>
#include <stdexcept>
#include "food.h"
#include "colors.h"
#include "snake.h"
#include "settings.h"

const char* FOOD_IMAGE_PATH = "../assets/images/apple.png";

Food::Food() : position(GetRandomPosition()) {
    Image image = LoadImage(FOOD_IMAGE_PATH);
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
}

Food::~Food() {
    UnloadTexture(texture);
}

void Food::Draw() 
{
    // DrawTexture(texture, OFFSET + position.x * CELL_SIZE, OFFSET + position.y * CELL_SIZE, WHITE);
    float scale = 30.0f / texture.width;  // Scale from 32 to 30
    Vector2 drawPos = {
        OFFSET + position.x * CELL_SIZE,
        OFFSET + position.y * CELL_SIZE
    };

    DrawTextureEx(texture, drawPos, 0.0f, scale, WHITE);
}

Vector2 Food::GetPosition()
{
    return position;
}

void Food::GenerateNewPosition(Snake& snake)
{
    const int maxAttempts = 1000;
    int attempts = 0;
    Vector2 newPos;
    do 
    {
        newPos = GetRandomPosition();
        attempts++;
    } while(snake.IsInSnakeBody(newPos) && attempts < maxAttempts);
    if(attempts >= maxAttempts)
    {
        throw std::runtime_error("Failed to place food: no valid positions left");
    }
    position = newPos;
}

Vector2 Food::GetRandomPosition()
{
    float x = GetRandomValue(0, CELL_COUNT - 1);
    float y = GetRandomValue(0, CELL_COUNT - 1);
    return Vector2{x, y};
}