#include <SDL.h>
#include <iostream>
#include "globals.h"
#include "tiles.h"
#include "objects.h"
#include "collision.h"

SDL_Rect Player = {640/2 - 16, 480/2 - 16, 32, 32};

int playerSpeed = 2;
int playerVelOffsetX = 0;
int playerVelOffsetY = 0;
int playerVelX = 0;
int playerVelY = 0;
int playerX = Player.x;
int playerY = Player.y;
int playerNewX = 0;
int playerNewY = 0;

void movePlayerX()
{
    // Moving the tiles not the player
//    Player.x += playerVelX;
    playerX -= playerVelX;
    _camera.x = playerX - _windowWidth/2 + Player.w/2;
    for (int i = 0; i < _numberOfTiles; i++)
    {
        tile[i].rect.x = tile[i].getInitialX() + _camera.x;
    }
    for (int i = 0; i < _numberOfObjects; i++)
    {
        object[i].rect.x = object[i].getInitialX() + _camera.x;
    }
////    for (int i = 0; i < _numberOfTiles; i++)
////    {
////        tile[i].rect.x -= playerVelX;
////    }
////    playerX += playerVelX;
////    _Projectile.x -= playerVelX;
    handleTileCollisionX();

}

void movePlayerY()
{
//    Player.y += playerVelY;
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

////    for (int i = 0; i < _numberOfTiles; i++)
////    {
////        tile[i].rect.y -= playerVelY;
////    }
////    playerY += playerVelY;
////    _Projectile.y -= playerVelY;
    handleTileCollisionY();
}
