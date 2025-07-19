#include "snake.h"

void Snake::Draw() {
    for(unsigned int i = 0; i < body.size(); i++) {
        float x = body[i].x;
        float y = body[i].y;

        Rectangle bodyCell = Rectangle{x * CELL_SIZE, y * CELL_SIZE, static_cast<float>(CELL_SIZE), static_cast<float>(CELL_SIZE)};
        DrawRectangleRounded(bodyCell, 0.5, 6, ACCENT);
    }
}