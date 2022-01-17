#include <iostream>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "primary.h"


using namespace std;
/*
	Initializes the SDL library
	Creates a window for rendering
*/
void initSDL()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    _Window = SDL_CreateWindow("2D Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _windowWidth, _windowHeight, SDL_WINDOW_SHOWN);
    _Renderer = SDL_CreateRenderer(_Window, -1, SDL_RENDERER_PRESENTVSYNC);
}
/*
	Renders the background, tiles, objects,
	then finally the player in order
*/
void Render()
{
    // Render Background
    SDL_SetRenderDrawColor(_Renderer, White.r, White.g, White.b, White.a);
    SDL_RenderClear(_Renderer); // Clear the screen with the color, White, set in the line above
    // Render Tiles
    for (int i = 0; i <= _numberOfTiles; i++) // Go through each tile
    {
		// If the tile is within the camera's viewport
        if (checkTileCollision(_camera, tile[i].rect) == true)
        {
			// Draw a wall if tileType is Wall
            if (tile[i].tileType == Wall) 
            {
				// Render color for rect set to SDL_Color Black
                SDL_SetRenderDrawColor(_Renderer, Black.r, Black.g, Black.b, Black.a);
            }
			// Draw a floor if tileType is Floor
            else if (tile[i].tileType == Floor) 
            {
                SDL_SetRenderDrawColor(_Renderer, Blue.r, Blue.g, Blue.b, Blue.a);
            }
			// Render the tile using its coordinates, dimensions, and tileType
            SDL_RenderFillRect(_Renderer, &tile[i].rect);
        }
    }
    for (int i = 0; i <= _numberOfObjects; i++) // Go through each object
    {
        if (checkTileCollision(_camera, object[i].rect) == true) // Within viewport
        {
			// Draw a box is tileType is Box
            if (object[i].tileType == Box)
            {
                SDL_SetRenderDrawColor(_Renderer, Green.r, Green.g, Green.b, Green.a);
            }
			// Render the object
            SDL_RenderFillRect(_Renderer, &object[i].rect);
        }
    }
    // Render Player
    SDL_SetRenderDrawColor(_Renderer, Red.r, Red.g, Red.b, Red.a);
    SDL_RenderFillRect(_Renderer, &Player);
	// Update the screen
    SDL_RenderPresent(_Renderer);
}

int main(int argc, char *argv[])
{
	// Initialize everything and load the game
    initSDL();
    loadMap();
    loadObjMap();
	// Main game loop
    while (!_quit)
    {
        while (SDL_PollEvent(&_e) != 0) // Event in queue
        {
            if (_e.type == SDL_QUIT) // On a quit event
            {
                _quit = true;
            }
            pollControls();
        }
        // Move Player and check/handle tile collisions
        movePlayerX();
        movePlayerY();
        // Check/handle mouse collisions
        handleMouseCollision();
		// Render after handling movement/collisions
        Render();
    }
    return 0;
}
