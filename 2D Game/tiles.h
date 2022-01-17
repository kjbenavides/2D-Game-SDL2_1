#ifndef TILES_H_INCLUDED
#define TILES_H_INCLUDED

/*
	The Tile Class
	Tile objects are used for building the tile map,
	also for collision detection and handling
*/
class Tile
{

public:
    Tile(); // Default constructor, doesn't really do anything

	/*
		Custom constructor to create the tile 
		@param int x, y tile coordinates
		@param int w, h tile width and height
		@param int tileType
	*/
    Tile(int, int, int, int, int);

	/*
		Sets a specific tile at a location
		Can be used to change the coordinates, size, and type
		@param int x, y tile coordinates
		@param int w, h tile width and height
		@param int tileType
	*/
    void setTile(int, int, int, int, int);

	/*
		Changes the tile type
		@param int tileType
	*/
    void setTileType(int);

    	/*
		Output the coordinates of the tile to the console
	*/
    void getCoords();

	/*
		Output the width and height of the tile to the console
	*/
    void getDim();

	/*
		@returns an int, tileType
	*/
    int getTileType();

	/*
		@returns an int, the tile's starting X coordinate
	*/
    int getInitialX();

	/*
		@returns an int, the tile's starting Y coordinate
	*/
    int getInitialY();

	/*
		Sets the tile's starting X coordinate
		Useful for movable tiles
		@param int velX, for determining where to set X
	*/
    void setInitialX(int);

	/*
		Sets the tile's starting Y coordinate
		@param int velY, for determining where to set Y
	*/
    void setInitialY(int);

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

// Tile types for use by other modules
extern int Wall;
extern int Floor;
extern int Box;

extern Tile tile[];
extern SDL_Rect renderTileRect;

/*
	Reads the game's map file, "map"
	Creates the map from the file
	@returns true if successful
*/
bool loadMap();

#endif // TILES_H_INCLUDED
