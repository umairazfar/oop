#include"Character.h"
#include<iostream>
using namespace std;


Character::Character()
{
    width = 44;
    height = 48;
    character_value = 0;
}

Character::Character(LTexture* image, float x, float y, char letter)
{
    spriteSheetTexture = image;
    character_value = 0;
    int asci_letter = int(letter);

    //cout << asci_letter << endl;

    //first line from the image
    if (asci_letter > 64 && asci_letter < 76)
    {
        x_displacement = 0;
        int starting_asci = 65;
        while (starting_asci != asci_letter)
        {
            x_displacement = x_displacement + 44;
            starting_asci++;
        }

    }
    //second line from the image
    if (asci_letter >75 && asci_letter < 87)
    {
        y_displacement = 48;
        x_displacement = 0;
        int starting_asci = 76;
        while (starting_asci != asci_letter)
        {
            x_displacement = x_displacement + 44;
            starting_asci++;
        }
    }
    //third line from the image for capital letters only
    if (asci_letter >86 && asci_letter < 91)
    {
        y_displacement = 48+48;
        x_displacement = 0;
        int starting_asci = 87;
        while (starting_asci != asci_letter)
        {
            x_displacement = x_displacement + 44;
            starting_asci++;
        }
    }
    //third line, lower case letters
    if (asci_letter >96 && asci_letter < 104)
    {
        y_displacement = 48+48;
        x_displacement = 44*4;
        int starting_asci = 97;
        while (starting_asci != asci_letter)
        {
            x_displacement = x_displacement + 44;
            starting_asci++;
        }
    }
    //in case of space
/*
    if (asci_letter = 32)
    {
        y_displacement = 48*9;
        x_displacement = 44*5;
    }
*/
    //Frame 0
    spriteClips.x = 0+ x_displacement;
    spriteClips.y = 0+ y_displacement;
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

void Character::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
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

