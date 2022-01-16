#ifndef COLLISION_H_INCLUDED
#define COLLISION_H_INCLUDED

bool checkTileCollision(SDL_Rect a, SDL_Rect b);
bool checkMouseCollision(SDL_Rect a);

void handleTileCollisionX();
void handleTileCollisionY();
void handleMouseCollision();

#endif // COLLISION_H_INCLUDED
