#include"Character.h"
#include<iostream>

Character::Character()
{
    width = 44;
    height = 48;
    character_value = 0;
}

Character::Character(LTexture* image, float x, float y, char character) //overloaded constructor takes character in the arguement as well.
{
    //Below we are first calculating the code, than setting a range and accordingly obtaining the clips of the symbol and characters. ,
    spriteSheetTexture = image;                       //a lot of conditions have been applied, so that the desired character can be obtained.
    character_value = 0;                              //the logic applied below, to minimize the condition is that some alphabets are in the same order as there ascii code, so for that we calculate the difference between the least ascii code so that accordingly we can obtain the image.
    character_value = (int) character;
    int difference = 0;
    if (character_value >= 65 && character_value <= 75)
    {
        difference = character_value - 65;
        spriteClips.x = difference * 44;
        spriteClips.y = 0;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    else if (character_value >= 76 && character_value <= 86)
    {
        difference = character_value - 76;
        spriteClips.x = difference * 44;
        spriteClips.y = 48;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    else if(character_value >= 87 && character_value <= 90)
    {
        difference = character_value - 87;
        spriteClips.x = difference * 44;
        spriteClips.y = 96;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    else if(character_value >= 97 && character_value <= 103)
    {
        difference = character_value - 97;
        spriteClips.x = (difference * 44)+ (4 * 44);
        spriteClips.y = 96;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    else if(character_value >= 104 && character_value <= 114)
    {
        difference = character_value - 104;
        spriteClips.x = difference * 44;
        spriteClips.y = 144;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    else if(character_value >= 115 && character_value <= 122)
    {
        difference = character_value - 115;
        spriteClips.x = difference * 44;
        spriteClips.y = 192;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    else if(character_value >= 48 && character_value <= 50)
    {
        difference = character_value - 48;
        spriteClips.x = difference * 44;
        spriteClips.y = 192;
        spriteClips.w = 44;
        spriteClips.h = 48;

    }
    else if(character_value >= 51 && character_value <= 57)
    {
        difference = character_value - 51;
        spriteClips.x = difference * 44;
        spriteClips.y = 240;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    else if(character_value == 46)
    {
        spriteClips.x = 308;
        spriteClips.y = 240;
        spriteClips.w = 44;
        spriteClips.h = 48;

    }
    else if(character_value == 44)
    {
        spriteClips.x = 352;
        spriteClips.y = 240;
        spriteClips.w = 44;
        spriteClips.h = 48;

    }
    else if(character_value == 59)
    {
        spriteClips.x = 396;
        spriteClips.y = 240;
        spriteClips.w = 44;
        spriteClips.h = 48;

    }
    else if(character_value == 58)
    {
        spriteClips.x = 440;
        spriteClips.y = 240;
        spriteClips.w = 44;
        spriteClips.h = 48;

    }
    else if(character_value == 63)
    {
        spriteClips.x = 0;
        spriteClips.y = 288;
        spriteClips.w = 44;
        spriteClips.h = 48;

    }
    else if(character_value == 33)
    {
        spriteClips.x = 44;
        spriteClips.y = 288;
        spriteClips.w = 44;
        spriteClips.h = 48;

    }
    else if(character_value == 45)
    {
        spriteClips.x = 88;
        spriteClips.y = 288;
        spriteClips.w = 44;
        spriteClips.h = 48;

    }
    else if(character_value == 95)
    {
        spriteClips.x = 132;
        spriteClips.y = 288;
        spriteClips.w = 44;
        spriteClips.h = 48;

    }
    else if(character_value == 126)
    {
        spriteClips.x = 176;
        spriteClips.y = 288;
        spriteClips.w = 44;
        spriteClips.h = 48;

    }
    else if(character_value == 35)
    {
        spriteClips.x = 220;
        spriteClips.y = 288;
        spriteClips.w = 44;
        spriteClips.h = 48;

    }
    else if(character_value == 34)
    {
        spriteClips.x = 264;
        spriteClips.y = 288;
        spriteClips.w = 44;
        spriteClips.h = 48;

    }
    else if(character_value == 39)
    {
        spriteClips.x = 308;
        spriteClips.y = 288;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    else if(character_value == 38)
    {
        spriteClips.x = 352;
        spriteClips.y = 288;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    else if(character_value == 40)
    {
        spriteClips.x = 396;
        spriteClips.y = 288;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    else if(character_value == 41)
    {
        spriteClips.x = 440;
        spriteClips.y = 288;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    else if(character_value == 91)
    {
        spriteClips.x = 0;
        spriteClips.y = 336;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    else if(character_value == 93)
    {
        spriteClips.x = 44;
        spriteClips.y = 336;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    else if(character_value == 124)
    {
        spriteClips.x = 88;
        spriteClips.y = 336;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    else if(character_value == 96)
    {
        spriteClips.x = 132;
        spriteClips.y = 336;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    else if(character_value == 92)
    {
        spriteClips.x = 176;
        spriteClips.y = 336;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    else if(character_value == 47)
    {
        spriteClips.x = 220;
        spriteClips.y = 336;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    else if(character_value == 64)
    {
        spriteClips.x = 264;
        spriteClips.y = 336;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    else if(character_value == -80)
    {
        spriteClips.x = 308;
        spriteClips.y = 336;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    else if(character_value == 43)
    {
        spriteClips.x = 352;
        spriteClips.y = 336;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    else if(character_value == 61)
    {
        spriteClips.x = 396;
        spriteClips.y = 336;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    else if(character_value == 42)
    {
        spriteClips.x = 440;
        spriteClips.y = 336;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    else if(character_value == 36)
    {
        spriteClips.x = 0;
        spriteClips.y = 384;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    else if(character_value == -93)
    {
        spriteClips.x = 44;
        spriteClips.y = 384;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    else if(character_value == -128)
    {
        spriteClips.x = 88;
        spriteClips.y = 384;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    else if(character_value == 60)
    {
        spriteClips.x = 132;
        spriteClips.y = 384;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    else if(character_value == 62)
    {
        spriteClips.x = 176;
        spriteClips.y = 384;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    else if(character_value == 32)
    {
        spriteClips.x = 246;
        spriteClips.y = 458;
        spriteClips.w = 20;
        spriteClips.h = 20;
    }




    position.x = x;
    position.y = y;

    this->width = spriteClips.w;
    this->height = spriteClips.h;
}

Character::~Character()
{
    char n = character_value + 97;
    std::cout<<"\nCharacter "<<n<<" Destroyed";
}

void Character::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)  //after it has obtained the clip, it renders it and displays it on the screen.
{

    spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &spriteClips, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { position.x - width/2, position.y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}

void Character::SetPosition(Point& position)
{
    this->position.x = position.x - width/2;
    this->position.y = position.y - height/2;
}

void Character::SetPosition(int x, int y)
{
    this->position.x = x - width/2;
    this->position.y = y - height/2;
}

int Character::GetFrameWidth()
{
    return width;
}
int Character::GetFrameHeight()
{
    return height;
}

