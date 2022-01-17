#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

extern SDL_Rect Player;

// Global variables for use in the collision, player, and control modules
extern const int playerSpeed;
extern int playerVelOffsetX;
extern int playerVelOffsetY;
extern int playerVelX;
extern int playerVelY;
extern int playerX;
extern int playerY;
extern int playerNewX;
extern int playerNewY;

/*
	Move player across the X-axis
	Handle collisions on the X-axis
*/
void movePlayerX();

/*
	Move player across the Y-axis
	Handle collisions on the Y-axis
*/
void movePlayerY();

#endif // PLAYER_H_INCLUDED
