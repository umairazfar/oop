/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

/**
Step 1: Headers
**/
#include <SDL.h>    //SDL functions and data types to make any SDL code are needed
#include <stdio.h>  //Standard IO library to print errors to the console e.g printf
#include <string>
#include <cmath>
#include <iostream>
#include"Rect.h"
#include"Stack.h"

/**
Step 2: Declare Screen Dimension
**/
//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

/**
We have functions to handle initialization, loading media,
and closing down the SDL application.
**/
bool init();        //Starts up SDL and creates window
bool loadMedia();   //Loads media
void close();       //Frees media and shuts down SDL

SDL_Window* gWindow = NULL;     //Declare our SDL window which we will be creating
SDL_Renderer* gRenderer = NULL; //Declare our SDL screen surface, which is just a 2D  contained by window


bool init()
{
    bool success = true;
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) //When there's an error, SDL_Init returns -1
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        //SDL_GetError returns the latest error produced by an SDL function.
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
        //If SDL initialized successfully, we'll want to create a window using SDL_CreateWindow(6 Arguments).
        //1st Argument is the Windows caption
        //The next 2 arguments define the x and y position the window is created in.
        //The next 2 arguments define the window's width and height.
        //Last: SDL_WINDOW_SHOWN makes sure the window is shown when it is created.
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )//If there is an error, SDL_CreateWindow returns NULL.
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
/**
SDL requires this type of arguments in main function
**/

int main( int argc, char* args[] )
{
    Stack originalStack;
    Stack tempStack;
    //Start up SDL and create window
    if( !init() )//Initialize SDL
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
            Rect* point = NULL;

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
                            if (e.button.button == SDL_BUTTON_LEFT)
                            {
                                originalStack.Push(rect);   //Pushing into the Original Stack
                                tempStack.deleteStk(); //Empty and Deletes the Temporary Stack, So that user will not able to redo if he draw something after using undo.

                            }
                            if (e.button.button == SDL_BUTTON_MIDDLE)//Redo Functionality
                            {
                                Rect* tempStorage = tempStack.Pop(); //Popping from temporary stack
                                if (tempStorage != NULL) //Making sure temporary Stack is not empty
                                {
                                    originalStack.Push(tempStorage); //Pushing into Original Stack
                                }
                            }

                            if (e.button.button == SDL_BUTTON_RIGHT)//Undo Functionality
                            {
                                Rect* tempStorage1 = originalStack.Pop();//Popping from Original stack
                                if (tempStorage1 != NULL)//Making sure original Stack is not empty
                                {
                                    tempStack.Push(tempStorage1);//Pushing into temporary Stack
                                }
                                originalStack.Show(gRenderer);
                            }
                        }

                    }
                }
                //Clear screen

                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                SDL_RenderClear( gRenderer );

                if (rect != NULL)
                {
                    SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0xFF, 0xFF );
                    originalStack.Show(gRenderer);
                }

                SDL_RenderPresent( gRenderer ); //Update the screen with any rendering performed.
            }
        }
    }

    close();

    return 0;
}
