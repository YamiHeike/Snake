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
    static const std::deque<Vector2> INITIAL_SNAKE_BODY;
    std::deque<Vector2> body = INITIAL_SNAKE_BODY;
    Direction direction = RIGHT;
    Direction nextDirection = RIGHT;
    bool pendingGrowth = false;
    std::deque<Vector2> GetHeadlessBody() const;
public:
    void Draw();
    void Update();
    void SetDirection(Direction newDir);
    bool IsInSnakeBody(Vector2 point, bool includeHead = true) const;
    Vector2 GetHead() const;
    unsigned int GetLength() const;
    void Grow();
    void Reset();
};

#endif