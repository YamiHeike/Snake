#include <raylib.h>
#include "food.h"
#include "colors.h"
#include "settings.h"

const char* FOOD_IMAGE_PATH = "../assets/images/apple.png";

Food::Food() : position(getRandomPosition()) {
    Image image = LoadImage(FOOD_IMAGE_PATH);
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
}

Food::~Food() {
    UnloadTexture(texture);
}

void Food::Draw() 
{
    DrawTexture(texture, position.x * CELL_SIZE, position.y * CELL_SIZE, WHITE);
}

Vector2 Food::getRandomPosition()
{
    float x = GetRandomValue(0, CELL_COUNT - 1);
    float y = GetRandomValue(0, CELL_COUNT - 1);
    return Vector2{x, y};
}