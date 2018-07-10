#include "Character.h"
#include "math.h"
#include <stdio.h>      /* printf */
#include <stdlib.h>
#include <iostream>

Character::Character()
{
    width = 44;     //Character dimensions
    height = 48;
}

Character::Character(LTexture* image, float x, float y, char alphabet)
{
    spriteSheetTexture = image;

    /** conditions for clipping every character i.e. (alphabets & numbers) from the sprite sheet using respective ASCII values **/

    if (((int) alphabet) >= 65 && ((int) alphabet) <= 75 )
    {
        spriteClips.x = abs (65 - ((int) alphabet)) * 44;
        spriteClips.y = 0 * 48;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    else if (((int) alphabet) >= 76 && ((int) alphabet) <= 86 )
    {
        spriteClips.x = abs (76 - ((int) alphabet)) * 44;
        spriteClips.y = 1 * 48;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    else if (((int) alphabet) >= 87 && ((int) alphabet) <= 90)
    {
        spriteClips.x = abs (87 - ((int) alphabet)) * 44;
        spriteClips.y = 2 * 48;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    else if (((int) alphabet) >= 97 && ((int) alphabet) <= 103)
    {
        spriteClips.x = abs ((97 - 4) - ((int) alphabet)) * 44;
        spriteClips.y = 2 * 48;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    else if (((int) alphabet) >= 104 && ((int) alphabet) <= 114 )
    {
        spriteClips.x = abs (104 - ((int) alphabet)) * 44;
        spriteClips.y = 3 * 48;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    else if (((int) alphabet) >= 115 && ((int) alphabet) <= 122 )
    {
        spriteClips.x = abs (115 - ((int) alphabet)) * 44;
        spriteClips.y = 4 * 48;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    else if (((int) alphabet) >= 48 && ((int) alphabet) <= 50 )
    {
        spriteClips.x = abs ((48 - 8) - ((int) alphabet)) * 44;
        spriteClips.y = 4 * 48;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    else if (((int) alphabet) >= 51 && ((int) alphabet) <= 57 )
    {
        spriteClips.x = abs (51  - ((int) alphabet)) * 44;
        spriteClips.y = 5 * 48;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    else if (((int)alphabet) == 32)     // condition for space
    {
        spriteClips.x = 5 * 44;
        spriteClips.y = 8 * 48;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }

    position.x = x;
    position.y = y;

    this->width = spriteClips.w;
    this->height = spriteClips.h;
}

Character::~Character()
{
    char n = (int) alphabet + 97;
    std::cout << "\nCharacter " << n << " Destroyed";
}

void Character::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    spriteSheetTexture->Render( position.x - width / 2, position.y - height / 2, &spriteClips, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { position.x - width / 2, position.y - height / 2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}

void Character::SetPosition(Point& position)
{
    this->position.x = position.x - width / 2;
    this->position.y = position.y - height / 2;
}

void Character::SetPosition(int x, int y)
{
    this->position.x = x - width / 2;
    this->position.y = y - height / 2;
}

int Character::GetFrameWidth()
{
    return width;
}
int Character::GetFrameHeight()
{
    return height;
}

