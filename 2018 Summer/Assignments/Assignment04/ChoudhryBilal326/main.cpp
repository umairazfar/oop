/*
Habib University, Summer Semester 2018,
Object Oriented Programming & Design Methodologies(CS224),
Assignment # 04; Rectangle Pushed & Popped in Stack.
Instructor: Dr. Umair Azfar Khan
TA: Ahmed Ali(aa02190)
Choudhry Bilal Mazhar (cm00326)
*/

/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

#include <SDL.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <iostream>
#include"Rect.h"
#include"Stack.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool init();
bool loadMedia();
void close();

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

bool init()
{
    bool success = true;

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Warning: Linear texture filtering not enabled!" );
        }

        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Create renderer for window
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
            }
        }
    }

    return success;
}

bool loadMedia()
{
    bool success = true;
    return success;
}

void close()
{
    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}

int main( int argc, char* args[] )
{
    Stack StackStorage;
    Stack StackRedo;
    //Start up SDL and create window
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {

        if( !loadMedia() )  //Load media
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            bool quit = false;  //Main loop controller

            SDL_Event e;        //Event handler that takes care of all events

            bool mouseClicked = false;
            SDL_Rect fillRect;
            int oldx = 0;
            int oldy = 0;

            Rect* rect = NULL;

            //While application is running
            while( !quit )
            {
                //Handle events on queue
                while( SDL_PollEvent( &e ) != 0 )
                {
                    //User requests quit
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }

                    if( e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
                    {
                        //Get mouse position
                        int x, y;
                        SDL_GetMouseState( &x, &y );

                        if(e.type ==  SDL_MOUSEMOTION)
                        {
                            if(mouseClicked == true)
                                fillRect = { oldx, oldy, x - oldx, y - oldy };
                        }

                        if(e.type == SDL_MOUSEBUTTONDOWN)
                        {
                            if (e.button.button == SDL_BUTTON_LEFT)
                            {
                                if(mouseClicked == false)
                                {
                                    mouseClicked = true;
                                    oldx = x;
                                    oldy = y;
                                }
                            }
                        }

                        if(e.type == SDL_MOUSEBUTTONUP)
                        {
                            mouseClicked = false;
                            rect = new Rect(&fillRect);
                            if(e.button.button == SDL_BUTTON_LEFT)
                            {
                                if(StackRedo.ShowStack())
                                {
                                    StackRedo.DeleteStack();
                                }
                                StackStorage.Push(rect);
                            }
                            if(e.button.button == SDL_BUTTON_RIGHT)
                            {
                                Rect* StackPopStorage = StackStorage.Pop();//rectangles stored in StackPopStorage after poping
                                if(StackPopStorage != NULL)//checking if StackPopStorage if not empty
                                {
                                    StackRedo.Push(StackPopStorage);//rectangles pushed to StackPopStorage
                                }
                            }
                            if (e.button.button == SDL_BUTTON_MIDDLE)
                            {
                                Rect* StackStore = StackRedo.Pop();//StackStorage formed rectangle type and rectangle popped from StackRedo and stored in it
                                if(StackStore != NULL)
                                {
                                    StackStorage.Push(StackStore);//rectangles pushed from StackStorage to StackStore
                                }
                            }

                        }

                    }
                }
                //Clear screen

                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                SDL_RenderClear( gRenderer );

                if (rect != NULL)
                {
                    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
                    StackStorage.Show(gRenderer);
                }

                SDL_RenderPresent( gRenderer );
            }
            delete rect;//deteles the rect to avoid dangling memory and memory leaks
        }
    }

    close();

    return 0;
}
