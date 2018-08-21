#include"Turret.h"

Turret::Turret(SDL_Texture* image, int x, int y):Unit(image, x, y)
{

}

Turret::~Turret()
{
    cout<<"\nTurret Destructor Called";
}
