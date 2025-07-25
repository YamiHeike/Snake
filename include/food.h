#ifndef FOOD_H
#define FOOD_H

#include <raylib.h>
#include "snake.h"

class Food {
private:
    Vector2 position;
    Texture2D texture;
public:
    Food();
    ~Food();
    void Draw();
    Vector2 GetPosition();
    void GenerateNewPosition(Snake& snake);
    Vector2 GetRandomPosition();
};

#endif