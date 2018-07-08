#include"Character.h"
#include<iostream>
using namespace std;

Character::Character()
{
    width = 44;
    height = 48;
    character_value = 0;
}

Character::Character(LTexture* image, float x, float y)
{

    spriteSheetTexture = image;
    character_value = 0;

    position.x = x;
    position.y = y;

    this->width = spriteClips.w;
    this->height = spriteClips.h;
}

Character::~Character()
{

}

void Character::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    spriteSheetTexture->Render( position.x, position.y, &spriteClips, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
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

void Character::getCharacter(int a,int b,int c, int d)
{
    spriteClips.x = a;
    spriteClips.y = b;
    spriteClips.w = c;
    spriteClips.h = d;
}


void Character::asciiToimage(int asci)
{
    int diff=0;
    width = 44;
    height = 48;
    if (asci>=65 && asci<=75) //Line 1
    {
        diff=asci-65;
        getCharacter(width*diff,height*0,44,48);
    }

    if (asci>=76 && asci<=86) //Line 2
    {
        diff=asci-76;
        getCharacter(width*diff,height*1,44,48);
    }

    if (asci>=87 && asci<=90) //Line 3 PART 1
    {
        diff=asci-87;
        getCharacter(width*diff,height*2,44,48);
    }

    if (asci>=97 && asci<=103) //Line 3 PART 2
    {
        diff=asci-97;
        getCharacter((width*diff)+(44*4),height*2,44,48);
    }

    if (asci>=104 && asci<=114) //Line 4
    {
        diff=asci-104;
        getCharacter(width*diff,height*3,44,48);
    }

    if (asci>=115 && asci<=122) //Line 5 PAwidthRT 1
    {
        diff=asci-115;
        getCharacter(width*diff,height*4,44,48);
    }

    if (asci>=48 && asci<=50) //Line 5 PART 2
    {
        diff=asci-48;
        getCharacter((width*diff)+44*8,height*4,44,48);
    }

    if (asci>=51 && asci<=57) //Line 6 PART 1 (3-9)
    {
        diff=asci-51;
        getCharacter(width*diff,height*5,44,48);
    }

    //Specific Symbols

    if (asci==46) // .
    {
        getCharacter(width*7,height*5,44,48);
    }

    if (asci==44) // ,
    {
        getCharacter(width*8,height*5,44,48);
    }

    if (asci==59) // ;
    {
        getCharacter(width*9,height*5,44,48);
    }

    if (asci==58) // :
    {
        getCharacter(width*10,height*5,44,48);
    }

    if (asci==63) // ?
    {
        getCharacter(width*0,height*6,44,48);
    }

    if (asci==33) // !
    {
        getCharacter(width*1,height*6,44,48);
    }

    if (asci==45) // -
    {
        getCharacter(width*2,height*6,44,48);
    }

    if (asci==95) // _
    {
        getCharacter(width*3,height*6,44,48);
    }

    if (asci==126) // ~
    {
        getCharacter(width*4,height*6,44,48);
    }

    if (asci==35) // #
    {
        getCharacter(width*5,height*6,44,48);
    }

    if (asci==34) // "
    {
        getCharacter(width*6,height*6,44,48);
    }

    if (asci==39) // '
    {
        getCharacter(width*7,height*6,44,48);
    }

    if (asci==38) // &
    {
        getCharacter(width*8,height*6,44,48);
    }

    if (asci==40) // (
    {
        getCharacter(width*9,height*6,44,48);
    }

    if (asci==41) // )
    {
        getCharacter(width*10,height*6,44,48);
    }

    if (asci==91) // [
    {
        getCharacter(width*0,height*7,44,48);
    }

    if (asci==93) // ]
    {
        getCharacter(width*1,height*7,44,48);
    }

    if (asci==124) // |
    {
        getCharacter(width*2,height*7,44,48);
    }

    if (asci==96) // `
    {
        getCharacter(width*3,height*7,44,48);
    }

    if (asci==92) //
    {
        getCharacter(width*4,height*7,44,48);
    }

    if (asci==47) // /
    {
        getCharacter(width*5,height*7,44,48);
    }

    if (asci==64) // @
    {
        getCharacter(width*6,height*7,44,48);
    }

    if (asci==-80) // 248 degree
    {
        getCharacter(width*7,height*7,44,48);
    }

    if (asci==43) // +
    {
        getCharacter(width*8,height*7,44,48);
    }

    if (asci==61) // =
    {
        getCharacter(width*9,height*7,44,48);
    }

    if (asci==42) // *
    {
        getCharacter(width*10,height*7,44,48);
    }

    if (asci==36) // $
    {
        getCharacter(width*0,height*8,44,48);
    }

    if (asci==156) // Pound Sign
    {
        getCharacter(width*1,height*8,44,48);
    }

    if (asci==-128) // Euro Sign
    {
        getCharacter(width*2,height*8,44,48);
    }

    if (asci==60) // <
    {
        getCharacter(width*3,height*8,44,48);
    }

    if (asci==62) // >
    {
        getCharacter(width*4,height*8,44,48);
    }

}
