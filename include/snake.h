#ifndef SNAKE_H
#define SNAKE_H
#include <raylib.h>
#include <deque>
#include "settings.h"
#include "colors.h"

enum Direction {
    UP, DOWN, LEFT, RIGHT
};

enum BodyDirection {
    VERTICAL, HORIZONTAL, TOP_LEFT, TOP_RIGHT, BOTTOM_LEFT, BOTTOM_RIGHT
};

class Snake {
private:
    Texture2D headImg;
    Texture2D tailImg;
    std::deque<Texture2D> bodyImgs;
    Texture2D headImages[4];
    Texture2D tailImages[4];
    Texture2D bodyImages[6];
    static const std::deque<Vector2> INITIAL_SNAKE_BODY;
    std::deque<Vector2> body = INITIAL_SNAKE_BODY;
    Direction direction = RIGHT;
    Direction nextDirection = RIGHT;
    bool pendingGrowth = false;
    std::deque<Vector2> GetHeadlessBody() const;
    void LoadHeadImage();
    void LoadTailImage();
    void LoadBodyImages();
    void UpdateImages();
public:
    Snake();
    ~Snake();
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