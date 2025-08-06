#include "food.h"
#include "snake.h"

class Game {
private:
    Snake snake = Snake();
    Food food = Food();
    bool running = true;
    int score = 0;
public:
    void Draw();
    void Update();
    void ChangeSnakeDirection(Direction newDir);
    bool CheckGameOver();
    void CheckCollisionWithFood();
    void CheckCollisionWithEdges();
    void CheckCollisionWithTail();
    void GameOver();
    int GetScore() const;
    void PlayAgain();
};