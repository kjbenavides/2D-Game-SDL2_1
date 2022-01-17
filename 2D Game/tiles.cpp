#include <iostream>
#include <fstream>
#include <SDL.h>
#include "globals.h"
#include "player.h"

using namespace std;

// Variables for the tileType
int Wall = 0;
int Floor = 1;
int Box = 1;

class Tile
{
public:
    Tile();
    Tile(int, int, int, int, int);
    void setTile(int, int, int, int, int);
    void setTileType(int);
    void getCoords();
    void getDim();
    int getTileType();
    int getInitialX();
    int getInitialY();
    void setInitialY(int);
    void setInitialX(int);
    SDL_Rect rect;
    int tileType;
private:
    int initialX;
    int initialY;
    int x;
    int y;
    int w;
    int h;
};

Tile::Tile()
{

};

Tile::Tile(int x, int y, int w, int h, int tileType)
{
	// Set tile properties
    rect.x = x; rect.y = y; rect.w = w; rect.h = h;
    Tile::x = x; Tile::y = y; Tile::w = w; Tile::h = h;
}

void Tile::setTile(int x, int y, int w, int h, int tileType)
{
	// Set tile properties
    rect.x = x; rect.y = y; rect.w = w; rect.h = h;
    Tile::x = x; Tile::y = y; Tile::w = w; Tile::h = h;
    Tile::initialX = x; Tile::initialY = y;
    Tile::tileType = tileType;
}

void Tile::setTileType(int type)
{
    Tile::tileType = type;
}

void Tile::getCoords()
{
    cout << Tile::x << ", " << Tile::y << endl; // "Tile X, Y"
}

void Tile::getDim()
{
    cout << Tile::w << ", " << Tile::h << endl; // "Tile W, H"
}

int Tile::getTileType()
{
    return tileType;
}

int Tile::getInitialX()
{
    return Tile::initialX;
}

int Tile::getInitialY()
{
    return Tile::initialY;
}

void Tile::setInitialX(int velocity)
{
	// Uses the player's current velocity to move the tile
    Tile::initialX = Tile::x += velocity; 
}

void Tile::setInitialY(int velocity)
{
    Tile::initialY = Tile::y += velocity;
}

Tile tile[375]; // Tile object array of 375 tiles, they are 32x32

bool loadMap()
{
    int tileNumber = 0;

    ifstream Map("map"); // Load the specified Map file, "map"

    if (Map.is_open()) // Read the map if the file was opened successfully
    {
        cout << "Map open ";

        int space = 0;
		// Coordinates to determine where tiles are placed
        int x = 0;
        int y = 0;

        char c;
        while (Map.get(c))
        {
            if (c == ' ')
            {
                _numberOfTiles++;
                space++;
            }
            if (c == '0')
            {
                tile[tileNumber].setTile(x*32, y*32, 32, 32, Wall);
                tile[tileNumber].getCoords();
                tileNumber++;
            }
            if (c == '1')
            {
                tile[tileNumber].setTile(x*32, y*32, 32, 32, Floor);
                tileNumber++;
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

        Map.close();
    }

    return true;
}
