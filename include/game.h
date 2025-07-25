#include "food.h"
#include "snake.h"

class Game {
private:
    Snake snake = Snake();
    Food food = Food();
public:
    void Draw();
    void Update();
    void ChangeSnakeDirection(Direction newDir);
    void CheckCollisionWithFood();
    void CheckCollisionWithEdges();
    void GameOver();
};