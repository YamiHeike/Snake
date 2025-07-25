#ifndef SNAKE_H
#define SNAKE_H
#include <raylib.h>
#include <deque>
#include "settings.h"
#include "colors.h"

enum Direction {
    UP, DOWN, LEFT, RIGHT
};

class Snake {
private:
    std::deque<Vector2> body = {Vector2{6, 9}, Vector2{5,9}, Vector2{4, 9}};
    Direction direction = RIGHT;
    Direction nextDirection = RIGHT;
    bool pendingGrowth = false;
public:
    void Draw();
    void Update();
    void SetDirection(Direction newDir);
    bool IsInSnakeBody(Vector2 point);
    Vector2 GetHead();
    unsigned int GetLength();
    void Grow();
};

#endif