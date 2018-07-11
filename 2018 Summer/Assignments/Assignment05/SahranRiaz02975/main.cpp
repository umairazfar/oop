#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "LTexture.h"
#include "Character.h"
#include "Word.h"
#include "Button.h"

//Predefined screen width and height

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

bool init();
bool loadMedia();
void close();

SDL_Window* gWindow = NULL; //Pointer of type SDL_Window is made to point at NULL, initially
SDL_Renderer* gRenderer = NULL; //Pointer of type SDL_Renderer is made to point at NULL, initially
LTexture gSpriteSheetTexture; //Object of class LTexture is declared

int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			bool quit = false;                      //Main loop flag
			SDL_Event e;                            //Event handler
			long int frame = 0;                     //Current animation frame
			/* initialize random seed: */
            srand(time(NULL));
            //You can comment out the code line below, pass a word string in the Word constructor, and see it displayed at the center of the SDL window
            /* ********************************************************************************************** */
            //Word word("Sahran", (float)SCREEN_WIDTH / 2, (float)SCREEN_HEIGHT / 2, &gSpriteSheetTexture);
            /* ********************************************************************************************** */
            //You can comment out the code line below, pass a word string in the Button constructor, and see it displayed at the center of the SDL window on a centered button
            /* ********************************************************************************************** */
            Button button("Sahran Riaz", &gSpriteSheetTexture,(float)SCREEN_WIDTH / 2, (float)SCREEN_HEIGHT / 2);
            /* ********************************************************************************************** */
            //You can comment out the code line below, pass a character in the Character constructor, and see it displayed at the center of the SDL window
            /* ********************************************************************************************** */
            //Character character(&gSpriteSheetTexture,(float)SCREEN_WIDTH / 2, (float)SCREEN_HEIGHT / 2, 'x');
			/* ********************************************************************************************** */
			while (!quit)                          //While application is running
			{
			    if (frame % 120 == 0)
                {

                }
				while (SDL_PollEvent(&e) != 0)   //Handle events on queue
				{
					//User requests quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
				}

				const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

                if (currentKeyStates[SDL_SCANCODE_RIGHT])
                {

                }
                if (currentKeyStates[SDL_SCANCODE_LEFT])
                {

                }
                if (currentKeyStates[SDL_SCANCODE_UP])
                {

                }

                if (currentKeyStates[SDL_SCANCODE_DOWN])
                {

                }
                if (currentKeyStates[SDL_SCANCODE_SPACE])
                {

                }
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);    //Clear screen
				SDL_RenderClear(gRenderer);
				/* ******************************************************************************************************* */
                //For Rendering
                /* ******************************************************************************************************* */
                //character.Render(frame, gRenderer, false);  //To render the passed character on to the screen
                button.DisplayButton(frame, gRenderer, false);  //To render the passed word onto the button on to the screen
                //word.DisplayString( frame, gRenderer, false);  //To render the passed word on to the screen
				SDL_RenderPresent(gRenderer);  //Update screen
				++frame;                       //Go to next frame
			}
		}
	}
	//Free resources and close SDL
	close();
	return 0;
}

bool init()
{
	//Initialization flag
	bool success = true;
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (gRenderer == NULL)
            {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            }
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}
	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;
	//Load sprite sheet texture
	if (!gSpriteSheetTexture.LoadFromFile("Images/fontSprite.png", gRenderer))
	{
		printf("Failed to load sprite sheet texture!\n");
		success = false;
	}
	return success;
}

void close()
{
	//Free loaded images
	gSpriteSheetTexture.Free();
	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;
	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}
