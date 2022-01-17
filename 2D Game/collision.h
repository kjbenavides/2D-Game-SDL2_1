#ifndef COLLISION_H_INCLUDED
#define COLLISION_H_INCLUDED

/*
	Simple collision detection function
	Checks whether two rectangles are intersecting
	@param   SDL_Rect a, b both rectangles being checked
	@returns bool true if collision was found,
			 false otherwise
*/
bool checkTileCollision(SDL_Rect a, SDL_Rect b);
/*
	Takes a Tile's or other SDL_Rect to test for 
	collision with the mouse pointer
	@param   SDL_Rect a
	@returns bool true if collision was detected,
			 false otherwise
*/
bool checkMouseCollision(SDL_Rect a);
/*
	Handles collisions between the player,
	objects, and the map tiles along the x-axis
*/
void handleTileCollisionX();
/*
	Handles collisions between the player,
	objects, and the map tiles along the y-axis
*/
void handleTileCollisionY();
/*
	Handles collisions with the mouse and map tiles
	Checks whether player is trying to add/remove tiles
*/
void handleMouseCollision();

#endif // COLLISION_H_INCLUDED
