#include <raylib.h>
#include "food.h"
#include "colors.h"
#include "settings.h"

Food::Food(float x, float y) : position{x, y} {
    Image image = LoadImage("../assets/images/food.png");
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