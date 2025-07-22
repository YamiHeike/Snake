#include <raylib.h>
#include <raymath.h>
#include "snake.h"

static const Vector2 directionVectors[] = {
    Vector2{0, -1},
    Vector2{0, 1},
    Vector2{-1, 0},
    Vector2{1, 0}
};

void Snake::Draw() 
{
    for(unsigned int i = 0; i < body.size(); i++) {
        float x = body[i].x;
        float y = body[i].y;

        Rectangle bodyCell = Rectangle{x * CELL_SIZE, y * CELL_SIZE, static_cast<float>(CELL_SIZE), static_cast<float>(CELL_SIZE)};
        DrawRectangleRounded(bodyCell, 0.5, 6, ACCENT);
    }
}

void Snake::Update() 
{
    body.pop_back();
    Vector2 currentDirection = directionVectors[static_cast<int>(direction)];
    body.push_front(Vector2Add(body[0], currentDirection));
}

void Snake::SetDirection(Direction newDir)
{
    if ((direction == UP && newDir == DOWN) ||
        (direction == DOWN && newDir == UP) ||
        (direction == LEFT && newDir == RIGHT) ||
        (direction == RIGHT && newDir == LEFT)) {
        return; 
    }
    direction = newDir;
}