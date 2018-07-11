#include "Character.h"
#include <iostream>


Character::Character()  //Default constructor used to assign width and height with values relevant to the width and height of parts of the sprite sheet
{
    width = 44;
    height = 48;
    characterValue = 0;
}

Character::Character(LTexture* image, float x, float y, char character)  //Character that needs to be drawn is passed here
{
    spriteSheetTexture = image;
    characterValue = (int)character;
//Each if condition checks whether the attained ascii value is in the range of a row of small or capital alphabets present in the sprite sheet
//if the ascii value matches then according to its x and y position in the sprite sheet, it is clipped, width and height remain constant
    if (characterValue >= 65 && characterValue <= 75)
    {
        spriteClips.x = ((characterValue - 65) * 44);
        spriteClips.y = 0;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    else if (characterValue >= 76 && characterValue <= 86)
    {
        spriteClips.x = ((characterValue - 76) * 44);
        spriteClips.y = 48;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    else if (characterValue >=87 && characterValue <= 90)
    {
        spriteClips.x = ((characterValue - 87) * 44);
        spriteClips.y = 96;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    else if (characterValue >= 97 && characterValue <= 103)
    {
        spriteClips.x = ((characterValue - 97) * 44 + 176);
        spriteClips.y = 96;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    else if (characterValue >= 104 && characterValue <= 114)
    {
        spriteClips.x = ((characterValue - 104) * 44);
        spriteClips.y = 144;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    else if (characterValue >= 115 && characterValue <= 122)
    {
        spriteClips.x = ((characterValue - 115) * 44);
        spriteClips.y = 192;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    else if (characterValue >= 48 && characterValue <= 50)
    {
        spriteClips.x = ((characterValue - 48) * 44 + 352);
        spriteClips.y = 192;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    else if (characterValue >= 51 && characterValue <= 57)
    {
        spriteClips.x = ((characterValue - 51) * 44);
        spriteClips.y = 240;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
//If space is pressed
    else if (characterValue == 32)
    {
        spriteClips.x = 200;
        spriteClips.y = 384;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    else
    {
        //These four loops run for characters in the sprite sheet
        //They try to find if an ascii value is present in one of the four arrays pre-defined arrays
        //Then according to the y position and x position, determined by the state of the iterator on an array, the desired symbol is clipped
        for (int x = 0; x < 4; x++)
        {
            if (asciiSymbolsArrFRow[x] == characterValue)
            {
                spriteClips.x = (x * 44 + 308);
                spriteClips.y = 240;
                spriteClips.w = 44;
                spriteClips.h = 48;
            }
        }
        for (int y = 0; y < 11; y++)
        {
            if (asciiSymbolsArrSRow[y] == characterValue)
            {
                spriteClips.x = (y * 44);
                spriteClips.y = 288;
                spriteClips.w = 44;
                spriteClips.h = 48;
            }
        }
        for (int z = 0; z < 11; z++)
        {
            if (asciiSymbolsArrThRow[z] == characterValue)
            {
                spriteClips.x = (z * 44);
                spriteClips.y = 336;
                spriteClips.w = 44;
                spriteClips.h = 48;
            }
        }
        for (int m = 0; m < 5; m++)
        {
            if (asciiSymbolsArrFouRow[m] == characterValue)
            {
                spriteClips.x = (m * 44);
                spriteClips.y = 384;
                spriteClips.w = 44;
                spriteClips.h = 48;
            }
        }
    }
    //Passed x and y values are assigned to the x and y of a position object
    position.x = x;
    position.y = y;
    this -> width = spriteClips.w;
    this -> height = spriteClips.h;
}

Character::~Character()  //Destructor
{
    char n = characterValue + 97;
    std::cout<<"\nCharacter "<<n<<" Destroyed";
}

//To render the character
void Character::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{

    spriteSheetTexture -> Render(position.x - width / 2, position.y - height / 2, &spriteClips, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
    if(debug == true)
    {
        SDL_Rect rect = {position.x - width / 2, position.y - height / 2, width, height};
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
        SDL_RenderDrawRect(gRenderer, &rect);
    }
}

// Following two functions are for the positioning of the character

void Character::SetPosition(Point& position)
{
    this -> position.x = position.x - width / 2;
    this -> position.y = position.y - height / 2;
}

void Character::SetPosition(int x, int y)
{
    this -> position.x = x - width / 2;
    this -> position.y = y - height / 2;
}

int Character::GetFrameWidth()
{
    return width;
}
int Character::GetFrameHeight()
{
    return height;
}
