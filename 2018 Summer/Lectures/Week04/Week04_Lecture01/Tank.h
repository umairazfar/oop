#pragma once
#include"Unit.h"
#include"Turret.h"

class Tank: public Unit
{
private:
    Turret* turret;
public:
    Tank();
    Tank(SDL_Texture* bodyImg, SDL_Texture* turretImg, int x, int y);
    virtual ~Tank();
    void Draw(SDL_Renderer* gRenderer);
    void Move(int direction);
};
