#include "Color.h"

Color::Color()  //Default constructor, used to initialize the integer variables in the Color structure to their maximum intensities
{
    red = 255;
    green = 255;
    blue = 255;
}

Color::Color(int red, int green, int blue)  //Parameterized constructor, used to pass the intensity values of red green and blue color respectively to create any secondary color rectangle
{
    this -> red = red;
    this -> green = green;
    this -> blue = blue;
}
