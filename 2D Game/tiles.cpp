#include <iostream>
#include <fstream>
#include <SDL.h>
#include "globals.h"
#include "player.h"

using namespace std;

int Wall = 0;
int Floor = 1;
int Box = 1;

class Tile
{

public:
    Tile();
    Tile(int, int, int, int, int);
    SDL_Rect rect;
    void setTile(int, int, int, int, int);
    void setTileType(int);
    void getCoords();
    void getDim();
    int getTileType();
    int getInitialX();
    int getInitialY();
    void setInitialY(int);
    void setInitialX(int);
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
    rect.x = x; rect.y = y; rect.w = w; rect.h = h;
    Tile::x = x; Tile::y = y; Tile::w = w; Tile::h = h;
}

void Tile::setTile(int x, int y, int w, int h, int tileType)
{
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
    cout << Tile::x << ", " << Tile::y << endl;
}

void Tile::getDim()
{
    cout << Tile::w << ", " << Tile::h << endl;
}

int Tile::getTileType()
{
    return tileType;
}

// May be key to camera issue with SDL_Rect(s) (e.g. tile[i].rect.x = tile[i].getInitialPosX + _camera.x) (if camera is at (32,0) and tile is
                                                                                                           // initially at (0,0), then offset
                                                                                                           // by x by +32)
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
    Tile::initialX = Tile::x += velocity;
}

void Tile::setInitialY(int velocity)
{
    Tile::initialY = Tile::y += velocity;
}

Tile tile[375];

bool loadMap()
{
    // Constructor with file argument opens the file

    int tileNumber = 0;

    ifstream Map("map");

    if (Map.is_open())
    {
        cout << "Map open ";

        int space = 0;
        int x = 0;
        int y = 0;

        char c;

//        Map.seekg(0, Map.end);
//        int length = Map.tellg();
//        Map.seekg(0, Map.beg);

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
//            cout << c;
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
//        cout << _numberOfTiles << endl;

        Map.close();
    }

    return true;
}
