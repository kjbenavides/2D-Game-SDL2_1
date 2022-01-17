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

    if (leftA >= rightB) // If the left side of A doesn't intersect the right side of B
    {
        return false;
    }
    if (rightA <= leftB) // If the right side of A doesn't intersect the left side of B
    {
        return false;
    }
    if (topA >= bottomB) // Top A doesn't intersect Bottom B
    {
        return false;
    }
    if (bottomA <= topB) // Bottom A doesn't intersect Top B
    {
        return false;
    }
    return true; // Collision detected
}

bool checkMouseCollision(SDL_Rect a)
{
	// Variables for each side of rect a
    int leftA = a.x;
    int rightA = a.x + a.w;
    int topA = a.y;
    int bottomA = a.y + a.h;

	// If the mouse lies outside the box
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
    return true; // Mouse in box, collision detected
}

void handleTileCollisionX()
{
    // Player/Tile Collision
    for (int i = 0; i < _numberOfTiles; i++)
    {
		// If the player collides with a tile
        if (checkTileCollision(Player, tile[i].rect) == true)
        {
            if (tile[i].getTileType() == Wall) // Wall collision
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
            object[i].rect.x += playerVelX; // Pushes the object away at the same speed as the player
            object[i].setInitialX(playerVelX); // Sets the object's new X coordinate
        }
        // Object/Object Collision
        for (int ii = 0; ii < _numberOfObjects; ii++)
        {
            if (ii != i)
            {
				// If they collide
                if (checkTileCollision(object[i].rect, object[ii].rect) == true)
                {
                    playerX += playerVelX; // Move player
                    object[i].setInitialX(-playerVelX); // Moves object[i] towards player
                    for (int j = 0; j < _numberOfTiles; j++) 
                    {
                        tile[j].rect.x += playerVelX; // Move the map with the player
                    }
                    if (checkTileCollision(object[i].rect, Player) == false) // No collision with player
                    {
                        object[i].rect.x -= playerVelX; // Moves object[i] towards player
                        for (int l = 0; l < _numberOfObjects; l++) 
                        {
                            object[l].rect.x += playerVelX; // Move the objects with the player
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
                if (tile[j].getTileType() == Wall) // If the object collides with a wall
                {
                    object[i].setInitialX(-playerVelX); // Move the object back towards the player
                    playerX += playerVelX; // Move the player
                    for (int k = 0; k < _numberOfTiles; k++) 
                    {
                        tile[k].rect.x += playerVelX; // Move every tile with the player
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
	// Same as checking for collision along X-axis
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
        // Object/Object Collision
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
    if (_leftClick) // Player holding left click
    {
        for (int i = 0; i < _numberOfTiles; i++)
        {
            if (checkMouseCollision(tile[i].rect) == true)
            {
				// Find the tile colliding with the mouse and change it into a Wall
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
