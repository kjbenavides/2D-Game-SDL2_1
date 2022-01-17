#include <SDL.h>
#include <iostream>
#include "globals.h"
#include "tiles.h"
#include "objects.h"
#include "collision.h"

// Creates the player which is a rect and sets them at the center of the screen
SDL_Rect Player = {640/2 - 16, 480/2 - 16, 32, 32};

// Velocity and speed variables for determining player movement
int playerSpeed = 2;
int playerVelOffsetX = 0;
int playerVelOffsetY = 0;
int playerVelX = 0;
int playerVelY = 0;
// Player coordinates
int playerX = Player.x;
int playerY = Player.y;
int playerNewX = 0;
int playerNewY = 0;

void movePlayerX()
{
    playerX -= playerVelX; // Move the player along x-axis
    _camera.x = playerX - _windowWidth/2 + Player.w/2; // Update camera X coord
    // Move tiles and objects relative to the camera and their starting position
    for (int i = 0; i < _numberOfTiles; i++)
    {
        tile[i].rect.x = tile[i].getInitialX() + _camera.x;
    }
    for (int i = 0; i < _numberOfObjects; i++)
    {
        object[i].rect.x = object[i].getInitialX() + _camera.x;
    }

    handleTileCollisionX(); // Handle collisions after movement
}

void movePlayerY()
{
    playerY -= playerVelY;
    _camera.y = playerY - _windowHeight/2 + Player.h/2;
    for (int i = 0; i < _numberOfTiles; i++)
    {
        tile[i].rect.y = tile[i].getInitialY() + _camera.y;
    }
    for (int i = 0; i < _numberOfObjects; i++)
    {
        object[i].rect.y = object[i].getInitialY() + _camera.y;
    }

    handleTileCollisionY();
}
