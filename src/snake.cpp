#include <deque>
#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include "snake.h"
#include "snake_textures.h"
#include "utils.h"


const Vector2 directionVectors[] = {
    Vector2{0, -1},
    Vector2{0, 1},
    Vector2{-1, 0},
    Vector2{1, 0}
};

const std::deque<Vector2> Snake::INITIAL_SNAKE_BODY = {Vector2{6, 9}, Vector2{5,9}, Vector2{4, 9}};

Snake::Snake()
{
    headImages[UP] = LoadTexture(HEAD_UP.c_str());
    headImages[DOWN] = LoadTexture(HEAD_DOWN.c_str());
    headImages[LEFT] = LoadTexture(HEAD_LEFT.c_str());
    headImages[RIGHT] = LoadTexture(HEAD_RIGHT.c_str());

    tailImages[UP] = LoadTexture(TAIL_UP.c_str());
    tailImages[DOWN] = LoadTexture(TAIL_DOWN.c_str());
    tailImages[LEFT] = LoadTexture(TAIL_LEFT.c_str());
    tailImages[RIGHT] = LoadTexture(TAIL_RIGHT.c_str());
    
    bodyImages[VERTICAL] = LoadTexture(BODY_VERTICAL.c_str());
    bodyImages[HORIZONTAL] = LoadTexture(BODY_HORIZONTAL.c_str());
    bodyImages[TOP_LEFT] = LoadTexture(BODY_TOP_LEFT.c_str());
    bodyImages[TOP_RIGHT] = LoadTexture(BODY_TOP_RIGHT.c_str());
    bodyImages[BOTTOM_LEFT] = LoadTexture(BODY_BOTTOM_LEFT.c_str());
    bodyImages[BOTTOM_RIGHT] = LoadTexture(BODY_BOTTOM_RIGHT.c_str());   
}

Snake::~Snake()
{
    for(auto& tex : headImages) UnloadTexture(tex);
    for(auto& tex : bodyImages) UnloadTexture(tex);
    for(auto& tex : tailImages) UnloadTexture(tex);
}

void Snake::Draw() 
{
    drawScaled(headImg, Vector2{
        OFFSET + body[0].x * CELL_SIZE,
        OFFSET + body[0].y * CELL_SIZE
    });
    for(size_t i = 1; i < body.size() - 1; i++)
    {
        drawScaled(bodyImgs[i - 1], Vector2{
            OFFSET + body[i].x * CELL_SIZE,
            OFFSET + body[i].y * CELL_SIZE
        });
    }
    drawScaled(tailImg, Vector2{
        OFFSET + body.back().x * CELL_SIZE,
        OFFSET + body.back().y * CELL_SIZE
    });
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
    UpdateImages();
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
    direction = RIGHT;
    UpdateImages();
}

void Snake::LoadHeadImage()
{
    headImg = headImages[direction];
}

void Snake::LoadTailImage()
{
    if(body.size() < 2) return;
    Vector2 tail = body.back();
    Vector2 prev = body[body.size() - 2];
    Vector2 diff = Vector2Subtract(prev, tail); 
    if(diff.x == 1 && diff.y == 0) 
    {
        tailImg = tailImages[LEFT];
    } 
    else if(diff.x == -1 && diff.y == 0)
    {
        tailImg = tailImages[RIGHT];
    } 
    else if(diff.x == 0 && diff.y == 1)
    {
        tailImg = tailImages[UP];
    } 
    else if(diff.x == 0 && diff.y == -1)
    {
        tailImg = tailImages[DOWN];
    } 
    else
    {
        std::cerr << "Warning: Unexpected tail direction (" << diff.x << ", " << diff.y << ")\n";
        tailImg = tailImages[RIGHT];
    }
}


void Snake::LoadBodyImages()
{
    for(int i = 1; i < body.size() - 1; i++)
    {
        Vector2 prev = body[i - 1];
        Vector2 next = body[i + 1];
        Vector2 diffPrev = Vector2Subtract(body[i], prev);
        Vector2 diffNext = Vector2Subtract(next, body[i]);
    
        if(Vector2Equals(diffPrev, diffNext))
        {
            if(diffPrev.y == 0 && (diffPrev.x == 1 || diffPrev.x == -1))
            {
                bodyImgs.push_back(bodyImages[HORIZONTAL]);
            } else if(diffPrev.x == 0 && (diffPrev.y == 1 || diffPrev.y == -1))
            {
                bodyImgs.push_back(bodyImages[VERTICAL]);
            } else {
                std::cerr << "WARNING: incorrect body cell position: (" << body[i].x << ", " << body[i].y << ")." << std:: endl;
            }
        } else {
            if((diffNext.y == 1 && diffPrev.x == 1) || (diffNext.x == -1 && diffPrev.y == -1)) {
                bodyImgs.push_back(bodyImages[BOTTOM_LEFT]);
            } else if((diffNext.y == 1 && diffPrev.x == -1) || (diffNext.x == 1 && diffPrev.y == -1)) {
                bodyImgs.push_back(bodyImages[BOTTOM_RIGHT]);
            } else if((diffNext.y == -1 && diffPrev.x == 1) || (diffNext.x == -1 && diffPrev.y == 1)) {
                bodyImgs.push_back(bodyImages[TOP_LEFT]);
            } else if((diffNext.y == -1 && diffPrev.x == -1) || (diffNext.x == 1 && diffPrev.y == 1)) {
                bodyImgs.push_back(bodyImages[TOP_RIGHT]);
            } else {
                std::cerr << "WARNING: incorrect body cell position: (" << body[i].x << ", " << body[i].y << ")." << std:: endl;
            }
        } 
    }
}

void Snake::UpdateImages()
{
    bodyImgs.clear();
    LoadHeadImage();
    LoadTailImage();
    LoadBodyImages();
}