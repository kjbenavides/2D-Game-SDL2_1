#ifndef TILES_H_INCLUDED
#define TILES_H_INCLUDED

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

extern int Wall;
extern int Floor;
extern int Box;

extern Tile tile[];
extern SDL_Rect renderTileRect;

bool loadMap();

#endif // TILES_H_INCLUDED
