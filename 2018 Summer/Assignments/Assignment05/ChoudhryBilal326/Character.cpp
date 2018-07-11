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

    //Frame 0
    spriteClips.x = 0;
    spriteClips.y = 0;
    spriteClips.w = 44;
    spriteClips.h = 48;

    position.x = x;
    position.y = y;

    this->width = spriteClips.w;
    this->height = spriteClips.h;
}

void Character::Redefine(LTexture* image, float x, float y)
{
    spriteSheetTexture = image;
    character_value = 0;

    //Frame 0
    spriteClips.x = 0;
    spriteClips.y = 0;
    spriteClips.w = 44;
    spriteClips.h = 48;

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

void Character::Render(int charNumber,int seqNumber,int len,long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    int alphabet=1;
    if(charNumber>=65 && charNumber<=90) // 'A - Z'
    {
        alphabet = charNumber - 65; // ASCII code for upper case letter 'A' is 65
        // ASCII code ranging from 65-90 for upper case alphabets
    }
    else if(charNumber>=97 && charNumber<=122) // 'a - z'
    {
        alphabet = charNumber - 97;
        alphabet = alphabet + 26; // offset for first 26 upper case letters from the source image
        // ASCII code ranging from 97-122 for lower case alphabets
        //first 26 characters of the source image
    }
    else if(charNumber>=48 && charNumber<=57) // '0 -9'
    {
        alphabet = charNumber - 48; // ASCII code ranging from 48-57 for numerics
        alphabet = alphabet + 52; // first 54 characters of the source image
    }

    else if(charNumber==32) // ' ' - ASCII code for blank space is 32
    {
        alphabet = charNumber - 32;
        alphabet = alphabet + 93; // 93rd location in the source image
    }

    else if(charNumber==46) // '.' - ASCII code for full stop
    {
        alphabet = charNumber - 46;
        alphabet = alphabet + 62; // 62nd location according to coordinate mapping on the source image
    }

    else if(charNumber==44) // ',' - ASCII code for comma
    {
        alphabet = charNumber - 44;
        alphabet = alphabet + 63; //63rd location according to coordinate mapping on the source image
    }

    else if(charNumber==59) // ';' - ASCII code for colon
    {
        alphabet = charNumber - 59;
        alphabet = alphabet + 64; //
    }

    else if(charNumber==58) // ':' - ASCII code for semi colon
    {
        alphabet = charNumber - 58;
        alphabet = alphabet + 65;
    }

    else if(charNumber==63) // '?' - ASCII code for question mark
    {
        alphabet = charNumber - 63;
        alphabet = alphabet + 66;
    }

    else if(charNumber==33) // '!' - ASCII code for exclamation mark
    {
        alphabet = charNumber - 33;
        alphabet = alphabet + 67;
    }

    else if(charNumber==45) // '-' - ASCII code for hyphen
    {
        alphabet = charNumber - 45;
        alphabet = alphabet + 68;
    }

    else if(charNumber==95) // '_' - ASCII code for underscore
    {
        alphabet = charNumber - 95;
        alphabet = alphabet + 69;
    }

    else if(charNumber==126) // '~' - ASCII code for tilde
    {
        alphabet = charNumber - 126;
        alphabet = alphabet + 70;
    }

    else if(charNumber==35) // '#' - ASCII code for hash sign
    {
        alphabet = charNumber - 35;
        alphabet = alphabet + 71;
    }

    else if(charNumber==34) // '"' - ASCII code for inverted commas
    {
        alphabet = charNumber - 34;
        alphabet = alphabet + 72;
    }

    else if(charNumber==39) // ''' - ASCII code for apostrophe
    {
        alphabet = charNumber - 39;
        alphabet = alphabet + 73;
    }

    else if(charNumber==38) // '&' - ASCII code for and sign
    {
        alphabet = charNumber - 38;
        alphabet = alphabet + 74;
    }

    else if(charNumber==40) // '(' - ASCII code for open parenthesis
    {
        alphabet = charNumber - 40;
        alphabet = alphabet + 75;
    }

    else if(charNumber==41) // ')' - ASCII code for close parenthesis
    {
        alphabet = charNumber - 41;
        alphabet = alphabet + 76;
    }

    else if(charNumber==91) // '[' - ASCII code for open square bracket
    {
        alphabet = charNumber - 91;
        alphabet = alphabet + 77;
    }

    else if(charNumber==93) // ']' - ASCII code for close square bracket
    {
        alphabet = charNumber - 93;
        alphabet = alphabet + 78;
    }

    else if(charNumber==124) // '|' - ASCII code for the vertical line symbol
    {
        alphabet = charNumber - 124;
        alphabet = alphabet + 79;
    }

    else if(charNumber==96) // '`' - ASCII code for tilde
    {
        alphabet = charNumber - 96;
        alphabet = alphabet + 80;
    }

    else if(charNumber==92) // '\' - ASCII code for slash sign
    {
        alphabet = charNumber - 92;
        alphabet = alphabet + 81;
    }

    else if(charNumber==47) // '/' - ASCII code for back slash sign
    {
        alphabet = charNumber - 47;
        alphabet = alphabet + 82;
    }

    else if(charNumber==64) // '@' - ASCII code for at the rate sign
    {
        alphabet = charNumber - 64;
        alphabet = alphabet + 83;
    }
    /*
        else if(charNumber==248) // '°' - ASCII code for degree
        {
            alphabet = charNumber - 248;
            alphabet = alphabet + 84;
        }
    */
    else if(charNumber==43) // '+' - ASCII code for plus sign
    {
        alphabet = charNumber - 43;
        alphabet = alphabet + 85;
    }

    else if(charNumber==61) // '=' - ASCII code for equals to sign
    {
        alphabet = charNumber - 61;
        alphabet = alphabet + 86;
    }

    else if(charNumber==42) // '*' - ASCII code for esterik sign
    {
        alphabet = charNumber - 42;
        alphabet = alphabet + 87;
    }

    else if(charNumber==36) // '$' - ASCII code for dollar sign
    {
        alphabet = charNumber - 36;
        alphabet = alphabet + 88;
    }
    /*
        else if(charNumber==156) // '£' - ASCII code for pound sign
        {
            alphabet = charNumber - 156;
            alphabet = alphabet + 89;
        }

        else if(charNumber==) // '€' - ASCII code for euro sign
        {
            alphabet = charNumber - ;
            alphabet = alphabet + 90;
        }
    */
    else if(charNumber==60) // '<' - ASCII code for less then sign
    {
        alphabet = charNumber - 60;
        alphabet = alphabet + 91;
    }

    else if(charNumber==62) // '>' - ASCII code for greater then sign
    {
        alphabet = charNumber - 62;
        alphabet = alphabet + 92;
    }

    int xVal = (alphabet % 11) * 44; // mod of 11 function is used in order to obtain value ranging from 0-10
    int yVal = int(alphabet/11) * 48;// 11 characters in a single row in the source image first being at from topLeft::topRight(0,0)-(44,0) and the last being at (440,0)-(484,0)

    spriteClips.x = xVal;
    spriteClips.y = yVal;
    spriteSheetTexture->Render( (position.x - width/2) - ((len-1)*22) + (seqNumber*45), position.y - height/2, &spriteClips, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    // length of the input string -1 being multiplied by half of the width of the image
    // in order to attain the center position of the screen for the character image to load


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

