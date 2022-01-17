#include <iostream>
#include <fstream>
#include <SDL.h>
#include "globals.h"
#include "tiles.h"
#include "player.h"


using namespace std;

Tile object[20]; // Create a small array of tile objects

bool loadObjMap()
{
    ifstream objMap("objMap");

    int tileNumber = 0;

    if (objMap.is_open()) // If file opened successfully
    {
        int x = 0; int y = 0;
        char c;

        while (objMap.get(c))
        {
            if (c == '1') // If read char is 1, create Box object at the coordinates
            {
                object[tileNumber].setTile(x*32, y*32, 32, 32, Box);
                tileNumber++;
                _numberOfObjects++;
            }
            if (c == '0')
            {

            }
            if (c != ' ') // If not a space, advance x/y coordinates accordingly
            {
                x++;
                if (x > _windowWidth/32) // Advance y coordinate if we reach the right side of the window
                {
                    x = 0; // Reset x (20,0 becomes 0,1 or 20,3 becomes 0,4; etc)
                    y++;
                }
            }
        }
    }
    objMap.close();

    return true;
}
