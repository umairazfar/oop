#include"Tank.h"

Tank::Tank()
{

}

Tank::Tank(SDL_Texture* bodyImg, SDL_Texture* turretImg, int x, int y):Unit(bodyImg, x, y)
{
    cout<<this->x;
    turret = new Turret(turretImg, this->x, this->y-30);
}

Tank::~Tank()
{
    cout<<"\nTank Destructor Called";
    delete turret;
}

void Tank::Draw(SDL_Renderer* gRenderer)
{
    Unit::Draw(gRenderer);
    turret->Draw(gRenderer);
}

void Tank::Move(int direction)
{
    Unit::Move(direction);
    turret->Move(direction);
}

