#include <iostream>
#include <fstream>
#include <SDL.h>
#include "globals.h"
#include "tiles.h"
#include "player.h"


using namespace std;

Tile object[20];

bool loadObjMap()
{
    ifstream objMap("objMap");

    int tileNumber = 0;

    if (objMap.is_open())
    {
        int x = 0; int y = 0;
        char c;

        while (objMap.get(c))
        {
            if (c == '1')
            {
                object[tileNumber].setTile(x*32, y*32, 32, 32, Box);
                tileNumber++;
                _numberOfObjects++;
            }
            if (c == '0')
            {

            }
            if (c != ' ')
            {
                x++;
                if (x > _windowWidth/32)
                {
                    x = 0;
                    y++;
                }
            }
        }
    }
    objMap.close();

    return true;
}
