#include <iostream>
#include <SDL.h>
#include <fstream>
#include <string>
#include <math.h>
#include "globals.h"
#include "player.h"
#include "tiles.h"

using namespace std;

void pollControls()
{
	// If the player moves their mouse,
	// capture the coordinates
    if (_e.type == SDL_MOUSEMOTION)
    {
        _mouseX = _e.motion.x;
        _mouseY = _e.motion.y;
    }

	// If the player presses a mouse button
    if (_e.type == SDL_MOUSEBUTTONDOWN)
    {
        if (_e.button.button == SDL_BUTTON_LEFT) // Left Mouse
        {
            _leftClick = true;
            cout << "LC Down \n";
        }
        if (_e.button.button == SDL_BUTTON_RIGHT) // Right Mouse
        {
            _rightClick = true;
            cout << "RC Down \n";
        }
        if (_e.button.button == SDL_BUTTON_MIDDLE) // Middle Mouse
        {
            _middleClick = true;
			// Coordinates to calculate the angle between the player and the mouse
            int x1 = playerX + tile[0].rect.x; int y1 = playerY + tile[0].rect.y;
            int x2 = _mouseX; int y2 = _mouseY;
			// Variables for the differences between points
            float xx; float yy;
			// The angle the projectile will be fired in
            float angle;

			// Find the difference
            xx = x2 - x1;
            yy = y2 - y1;

            angle = atan2(yy, xx); // Calculate the angle

			// Find the required velocity of the projectile 
            _projectileVelX = cos(angle) * _projectileSpeed * 10;
            _projectileVelY = sin(angle) * _projectileSpeed * 10;

			// Starting location of projectile
            _projectileLocX = x2;
            _projectileLocY = y2;

            _shoot = true;

            cout << "MC Down \n";
        }
    }
    else if (_e.type == SDL_MOUSEBUTTONUP) // Player lets go of mouse button
    {
        if (_e.button.button == SDL_BUTTON_LEFT)
        {
            _leftClick = false;
            cout << "LC Up \n";
        }
        else if (_e.button.button == SDL_BUTTON_RIGHT)
        {
            _rightClick = false;
            cout << "RC Up \n";
        }
    }

    if (_e.type == SDL_KEYDOWN && _e.key.repeat == false)
    {
        switch (_e.key.keysym.sym) // Which key is being pressed
        {
		// A: Move player left
		// D: Move right
		// W: Move up
		// S: Move down
        case SDLK_a:
            playerVelX -= playerSpeed;
            break;
        case SDLK_d:
            playerVelX += playerSpeed;
            break;
        case SDLK_w:
            playerVelY -= playerSpeed;
            break;
        case SDLK_s:
            playerVelY += playerSpeed;
            break;
		// Left: Moves tiles, player, and camera left
		// Right: Moves everything right
		// Down: Moves everything down
		// Up: Moves everything up
        case SDLK_LEFT:
			// Go through all the tiles and move them to the left
            for (int i = 0; i < _numberOfTiles; i++)
            {
                tile[i].rect.x -= 32;
            }
			// Move player and camera to the left
            Player.x -= 32;
            _camera.x -= 32;
            break;
        case SDLK_RIGHT:
            for (int i = 0; i < _numberOfTiles; i++)
            {
                tile[i].rect.x += 32;
            }
            Player.x += 32;
            _camera.x += 32;
            break;
        case SDLK_DOWN:
            for (int i = 0; i < _numberOfTiles; i++)
            {
                tile[i].rect.y += 32;
            }
            Player.y += 32;
            _camera.y += 32;
            break;
        case SDLK_UP:
            for (int i = 0; i < _numberOfTiles; i++)
            {
                tile[i].rect.y -= 32;
            }
            Player.y -= 32;
            _camera.y -= 32;
            break;
        // R: Reads map
        case SDLK_r:
            {
                ifstream Map1("map");
                if (Map1)
                {
                    Map1.seekg(0, Map1.end);
                    int length = Map1.tellg();
                    Map1.seekg(0, Map1.beg);

                    char *buffer = new char [length];

                    if (Map1.is_open())
                    {
                        cout << "MAP OPEN \n";
                    }

                    Map1.read(buffer, length);
                    cout << buffer;

                    Map1.close();
                    if (!Map1.is_open())
                    {
                        cout << "MAP CLOSED \n";
                    }
                    delete[] buffer;
                }
            }
            break;
        // E: Saves map
        case SDLK_e:
            {
                ofstream Map2("map2");
                int x = 0;
                if (Map2)
                {
                    for (int i = 0; i < _numberOfTiles; i++)
                    {
                        Map2 << " " << tile[i].getTileType();
                        x++;
                        if (x >= _windowWidth/32)
                        {
                            x = 0;
                            Map2 << "\n";
                        }
                    }
                }
                Map2.close();
                if (!Map2.is_open())
                {
                    cout << "Map Saved to map2";
                }
            }
            break;
        }
    }
    else if (_e.type == SDL_KEYUP && _e.key.repeat == false) // Player lets go of a key
    {
        switch (_e.key.keysym.sym) // Which key unpressed
        {
		// Stops moving the player in the direction they were once they release the key
        case SDLK_a:
            playerVelX += playerSpeed;
            break;
        case SDLK_d:
            playerVelX -= playerSpeed;
            break;
        case SDLK_w:
            playerVelY += playerSpeed;
            break;
        case SDLK_s:
            playerVelY -= playerSpeed;
            break;
        }
    }
}
