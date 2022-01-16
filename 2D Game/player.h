#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

extern SDL_Rect Player;

extern const int playerSpeed;
extern int playerVelOffsetX;
extern int playerVelOffsetY;
extern int playerVelX;
extern int playerVelY;
extern int playerX;
extern int playerY;
extern int playerNewX;
extern int playerNewY;

void movePlayerX();
void movePlayerY();
void setPlayer(int, int);

#endif // PLAYER_H_INCLUDED
