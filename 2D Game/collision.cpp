#include <iostream>
#include <SDL.h>
#include "globals.h"
#include "player.h"
#include "tiles.h"
#include "objects.h"

bool checkTileCollision(SDL_Rect a, SDL_Rect b)
{
	// Variables for each side of the A and B rects
    int leftA = a.x;
    int rightA = a.x + a.w;
    int topA = a.y;
    int bottomA = a.y + a.h;

    int leftB = b.x;
    int rightB = b.x + b.w;
    int topB = b.y;
    int bottomB = b.y + b.h;

    if (leftA >= rightB)
    {
        return false;
    }
    if (rightA <= leftB)
    {
        return false;
    }
    if (topA >= bottomB)
    {
        return false;
    }
    if (bottomA <= topB)
    {
        return false;
    }
    return true;
}

bool checkMouseCollision(SDL_Rect a)
{
    int leftA = a.x;
    int rightA = a.x + a.w;
    int topA = a.y;
    int bottomA = a.y + a.h;

    if (leftA >= _mouseX)
    {
        return false;
    }
    if (rightA <= _mouseX)
    {
        return false;
    }
    if (topA >= _mouseY)
    {
        return false;
    }
    if (bottomA <= _mouseY)
    {
        return false;
    }

    return true;
}

void handleTileCollisionX()
{
    // Player/Tile Collision
    for (int i = 0; i < _numberOfTiles; i++)
    {
        if (checkTileCollision(Player, tile[i].rect) == true)
        {
            if (tile[i].getTileType() == Wall)
            {
                playerX += playerVelX;
                for (int j = 0; j < _numberOfTiles; j++)
                {
                    tile[j].rect.x += playerVelX;
                }
                for (int k = 0; k < _numberOfObjects; k++)
                {
                    object[k].rect.x += playerVelX;
                }
                std::cout << "XCOLLISION \n";
            }
        }
    }
    // Object/Player/Tile Collision
    for (int i = 0; i < _numberOfObjects; i++)
    {
        if (checkTileCollision(object[i].rect, Player) == true)
        {
            object[i].rect.x += playerVelX;
            object[i].setInitialX(playerVelX);
        }
        // Tile/Tile Collision
        for (int ii = 0; ii < _numberOfObjects; ii++)
        {
            if (ii != i)
            {
                if (checkTileCollision(object[i].rect, object[ii].rect) == true)
                {
                    playerX += playerVelX;
                    object[i].setInitialX(-playerVelX);
                    for (int j = 0; j < _numberOfTiles; j++)
                    {
                        tile[j].rect.x += playerVelX;
                    }
                    if (checkTileCollision(object[i].rect, Player) == false)
                    {
                        object[i].rect.x -= playerVelX;
                        for (int l = 0; l < _numberOfObjects; l++)
                        {
                            object[l].rect.x += playerVelX;
                        }
                    }
                }
            }
        }
        // Object/Tile Collision
        for (int j = 0; j < _numberOfTiles; j++)
        {
            if (checkTileCollision(object[i].rect, tile[j].rect) == true)
            {
                if (tile[j].getTileType() == Wall)
                {
                    object[i].setInitialX(-playerVelX);
                    playerX += playerVelX;
                    for (int k = 0; k < _numberOfTiles; k++)
                    {
                        tile[k].rect.x += playerVelX;
                    }
                    if (checkTileCollision(object[i].rect, Player) == false)
                    {
                        object[i].rect.x -= playerVelX;
                        for (int l = 0; l < _numberOfObjects; l++)
                        {
                            object[l].rect.x += playerVelX;
                        }
                    }
                }
            }
        }
    }
}

void handleTileCollisionY()
{
    for (int i = 0; i < _numberOfTiles; i++)
    {
        if (checkTileCollision(Player, tile[i].rect) == true)
        {
            if (tile[i].getTileType() == Wall)
            {
                playerY += playerVelY;
                for (int j = 0; j < _numberOfTiles; j++)
                {
                    tile[j].rect.y += playerVelY;
                }
                for (int k = 0; k < _numberOfObjects; k++)
                {
                    object[k].rect.y += playerVelY;
                }
                std::cout << "YCOLLISION \n";
            }
        }
    }
    // Object/Player/Tile Collision
    for (int i = 0; i < _numberOfObjects; i++)
    {
        if (checkTileCollision(object[i].rect, Player) == true)
        {
            object[i].rect.y += playerVelY;
            object[i].setInitialY(playerVelY);
        }
        // Tile/Tile Collision
        for (int ii = 0; ii < _numberOfObjects; ii++)
        {
            if (ii != i)
            {
                if (checkTileCollision(object[i].rect, object[ii].rect) == true)
                {
                    playerY += playerVelY;
                    object[i].setInitialY(-playerVelY);
                    for (int j = 0; j < _numberOfTiles; j++)
                    {
                        tile[j].rect.y += playerVelY;
                    }
                    if (checkTileCollision(object[i].rect, Player) == false)
                    {
                        object[i].rect.y -= playerVelY;
                        for (int l = 0; l < _numberOfObjects; l++)
                        {
                            object[l].rect.y += playerVelY;
                        }
                    }
                }
            }
        }
        // Object/Tile Collision
        for (int j = 0; j < _numberOfTiles; j++)
        {
            if (checkTileCollision(object[i].rect, tile[j].rect) == true)
            {
                if (tile[j].getTileType() == Wall)
                {
                    object[i].setInitialY(-playerVelY);
                    playerY += playerVelY;
                    for (int k = 0; k < _numberOfTiles; k++)
                    {
                        tile[k].rect.y += playerVelY;
                    }
                    if (checkTileCollision(object[i].rect, Player) == false)
                    {
                        object[i].rect.y -= playerVelY;
                        for (int l = 0; l < _numberOfObjects; l++)
                        {
                            object[l].rect.y += playerVelY;
                        }
                    }
                }
            }
        }
    }
}

void handleMouseCollision()
{
    if (_leftClick)
    {
        for (int i = 0; i < _numberOfTiles; i++)
        {
            if (checkMouseCollision(tile[i].rect) == true)
            {
                tile[i].setTileType(Wall);
            }
        }
    }
    else if (_rightClick)
    {
        for (int i = 0; i < _numberOfTiles; i++)
        {
            if (checkMouseCollision(tile[i].rect) == true)
            {
                tile[i].setTileType(Floor);
            }
        }
    }
}
