#include"Enemy.h"

Enemy::Enemy()
{

}

Enemy::~Enemy()
{
    cout<<"Enemy Deallocated"<<endl;
}

Enemy::Enemy(LTexture* image, float x, float y):Unit(image, x, y)
{
    spriteSheetTexture = image;


    //Frame 0
    spriteClips[ 0 ].x = 384;
    spriteClips[ 0 ].y =   0;
    spriteClips[ 0 ].w = 128;
    spriteClips[ 0 ].h = 96;

    //Frame 1
    spriteClips[ 1 ].x = 512;
    spriteClips[ 1 ].y =   0;
    spriteClips[ 1 ].w = 128;
    spriteClips[ 1 ].h = 96;

    //Frame 2
    spriteClips[ 2 ].x = 640;
    spriteClips[ 2 ].y = 0;
    spriteClips[ 2 ].w = 128;
    spriteClips[ 2 ].h = 96;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;
}


void Enemy::Move()
{
     //speedx = speedx * friction;
     //speedy = speedy * friction;

     //x = x + speedx;
     y = y + 2; //speedy;
     if(y > 900)
     {
         SetAlive(false);
     }
}

void Enemy::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    spriteSheetTexture->Render( x- width/2 , y - height/2, &spriteClips[ frame % FLYING_FRAMES ], 0.0, NULL, SDL_FLIP_VERTICAL, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { x - width/2, y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}
