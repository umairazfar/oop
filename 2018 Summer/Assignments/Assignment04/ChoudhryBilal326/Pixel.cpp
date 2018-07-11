#include"Pixel.h"

/** Overloaded constructor uses base class's constructor to initialize **/
Pixel::Pixel(Point& position, Color& color) : Shape(position, color)
{
    type = 0;
}

/** Draws the pixel **/
void Pixel::Draw(BITMAP* buffer)
{
     putpixel(buffer, position.x, position.y, GetColor());
}

