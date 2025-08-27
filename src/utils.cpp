#include "utils.h"
#include <raylib.h>

void drawScaled(Texture2D texture, Vector2 drawPos)
{
    float scale = 30.0f / texture.width;
    DrawTextureEx(texture, drawPos, 0.0f, scale, WHITE);
}