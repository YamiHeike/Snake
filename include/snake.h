#ifndef SNAKE_H
#define SNAKE_H
#include <raylib.h>
#include <deque>
#include "settings.h"
#include "colors.h"

class Snake {
private:
    std::deque<Vector2> body = {Vector2{6, 9}, Vector2{5,9}, Vector2{4, 9}};
public:
    void Draw();
};

#endif