#include <SDL.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <iostream>
#include "Rect.h"
#include "Stack.h"


using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Global declarations of functions
bool init();
bool loadMedia();
void close();

SDL_Window* gWindow = NULL;  //Pointer of type SDL_Window is made to point at NULL, initially
SDL_Renderer* gRenderer = NULL;  //Pointer of type SDL_Renderer is made to point at NULL, initially

bool init()  //Used to initialize the SDL window
{
	bool success = true;

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
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);

			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}

			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
			}
		}
	}

	return success;
}

bool loadMedia()  //This function is used as a formality, LoadMedia will always be successful
{
	bool success = true;
    return success;
}

void close()  //Deallocates all the SDL type pointers
{
	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

int main (int argc, char* args[])
{
	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}

	else
	{
		if (!loadMedia())  //Load media
		{
			printf("Failed to load media!\n");
		}

		else
		{
			bool quit = false;  //Main loop controller

			SDL_Event e;  //Event handler that takes care of all events, this events handler stores all the events in a queue

			Stack stk;  //Main stack

			Stack backupStk;  //Backup stack used to store the popped rectangles, rectangles will be popped from the stack while undo

			bool mouseClicked = false;  //Bool variable used to help in debugging
			SDL_Rect fillRect;  //Object of the type SDL_Rect is created
			int oldx = 0;  //Used to store the mouse position
            int oldy = 0;  //Used to store the mouse position

            Rect* rect = NULL;  //Pointer of type Rect is initialized to NULL

			//While application is running
			while ( !quit )
			{
				//Handle events on queue
				while ( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if ( e.type == SDL_QUIT )
					{
						quit = true;
					}

					if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP)
                    {
                        //Get mouse position
                        int x, y;
                        SDL_GetMouseState( &x, &y );

                        if (e.type ==  SDL_MOUSEMOTION)
                        {
                            if (mouseClicked == true)
                                fillRect = { oldx , oldy , x - oldx, y - oldy };
                        }

                        if (e.type == SDL_MOUSEBUTTONDOWN)  //If mouse key pressed
                        {
                            if (e.button.button == SDL_BUTTON_LEFT)  //If that pressed key is the left one
                            {
                                if (mouseClicked == false)
                                {
                                    mouseClicked = true;
                                    oldx = x;  //Stores the x position of the mouse
                                    oldy = y;  //Stores the y position of the mouse
                                }
                            }

                            else if (e.button.button == SDL_BUTTON_RIGHT)  //If that clicked button is right
                            {
                                if (mouseClicked == false)  //Same as above
                                {
                                    mouseClicked = true;
                                }
                            }

                            else if (e.button.button == SDL_BUTTON_MIDDLE)  //If that clicked button is middle
                            {
                                if (mouseClicked == false)
                                {
                                    mouseClicked = true;
                                }
                            }
                        }

                        if (e.type == SDL_MOUSEBUTTONUP)  //If after pressing the key that key is lifted
                        {
                            if (e.button.button == SDL_BUTTON_RIGHT)  //If right key is lifted
                            {
                                mouseClicked = false;
                                backupStk.Push(stk.Pop());  //Node on the top of the stack is removed from the main stack and pushed in the backup stack for potential redo
                                cout << "A rectangle was pushed into the backup stack" << endl;
                            }

                            else if (e.button.button == SDL_BUTTON_LEFT)  //If left key is lifted
                            {
                                mouseClicked = false;
                                rect = new Rect(fillRect);  //A random address of a rectangle is assigned to the rect pointer
                                stk.Push(*rect);  //Rectangle pointed to by rect is pushed into the main stack
                                cout << "A rectangle was pushed into the main stack" << endl;
                                backupStk.Remove();  //Backup stack is completely cleaned, particularly since after undo if another rectangle is created, redo should not be possible
                            }

                            else if (e.button.button == SDL_BUTTON_MIDDLE) //If middle key is lifted
                            {
                                bool isEmpty = backupStk.IsEmpty();  //Stores either true or false depending on whether or not the backup stack is empty

                                if (isEmpty == true)
                                {
                                    cout << "Nothing was undone" << endl;
                                }

                                else if (isEmpty == false)
                                {
                                    stk.Push(backupStk.Pop());  //If backup stack has a node, it is popped from it and pushed back into the main stack
                                }
                            }
                        }
                    }
				}
				delete rect;

                //Clear screen
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );  //White color is rendered
                SDL_RenderClear( gRenderer );

                stk.Show(gRenderer, &fillRect);  //Each rectangle in the main stack is made onto the SDL window
                SDL_RenderPresent(gRenderer);  //It continues to display the made rectangles

			}

		}
	}

	close();

	return 0;
}



