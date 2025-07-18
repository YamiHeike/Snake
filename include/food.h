#ifndef FOOD_H
#define FOOD_H

#include <raylib.h>

class Food {
private:
    Vector2 position;
    Texture2D texture;
public:
    Food();
    ~Food();
    void Draw();
    Vector2 getRandomPosition();
};

#endif