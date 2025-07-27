#include "food.h"
#include "snake.h"

class Game {
private:
    Snake snake = Snake();
    Food food = Food();
    bool running = true;
public:
    void Draw();
    void Update();
    void ChangeSnakeDirection(Direction newDir);
    void CheckCollisionWithFood();
    void CheckCollisionWithEdges();
    void CheckCollisionWithTail();
    void GameOver();
    bool CheckGameOver();
    void PlayAgain();
};