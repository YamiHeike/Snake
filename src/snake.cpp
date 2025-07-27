#include <deque>
#include <raylib.h>
#include <raymath.h>
#include "snake.h"

const Vector2 directionVectors[] = {
    Vector2{0, -1},
    Vector2{0, 1},
    Vector2{-1, 0},
    Vector2{1, 0}
};

const std::deque<Vector2> Snake::INITIAL_SNAKE_BODY = {Vector2{6, 9}, Vector2{5,9}, Vector2{4, 9}};

void Snake::Draw() 
{
    for(unsigned int i = 0; i < body.size(); i++) {
        float x = body[i].x;
        float y = body[i].y;

        Rectangle bodyCell = Rectangle{OFFSET + x * CELL_SIZE, OFFSET + y * CELL_SIZE, static_cast<float>(CELL_SIZE), static_cast<float>(CELL_SIZE)};
        DrawRectangleRounded(bodyCell, 0.5, 6, ACCENT);
    }
}

void Snake::Update() 
{
    direction = nextDirection;
    body.push_front(Vector2Add(body[0], directionVectors[static_cast<int>(direction)]));
    if(pendingGrowth == false) 
    {
        body.pop_back();
    } else
    {
        pendingGrowth = false;
    }
}

void Snake::SetDirection(Direction newDir)
{
    if ((direction == UP && newDir == DOWN) ||
        (direction == DOWN && newDir == UP) ||
        (direction == LEFT && newDir == RIGHT) ||
        (direction == RIGHT && newDir == LEFT)) {
        return; 
    }
    nextDirection = newDir;
}

Vector2 Snake::GetHead() const
{
    return body[0];
}

std::deque<Vector2> Snake::GetHeadlessBody() const
{
    auto headlessBody = body;
    headlessBody.pop_front();
    return headlessBody;
}

unsigned int Snake::GetLength() const
{
    return body.size();
}

bool Snake::IsInSnakeBody(Vector2 point, bool includeHead) const
{
    std::deque<Vector2> bodyToCheck = includeHead ? body : GetHeadlessBody();

    for(size_t cell = 0; cell < bodyToCheck.size(); cell++)
    {
        if(Vector2Equals(bodyToCheck[cell], point)) return true;
    }
    return false;
}

void Snake::Grow()
{
    pendingGrowth = true;
}

void Snake::Reset()
{
    body = INITIAL_SNAKE_BODY;
    SetDirection(RIGHT);
}