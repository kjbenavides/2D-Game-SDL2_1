#include <iostream>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "primary.h"


using namespace std;

void initSDL()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    _Window = SDL_CreateWindow("2D Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _windowWidth, _windowHeight, SDL_WINDOW_SHOWN);
    _Renderer = SDL_CreateRenderer(_Window, -1, SDL_RENDERER_PRESENTVSYNC);
}

void Render()
{
    // Render Background
    SDL_SetRenderDrawColor(_Renderer, White.r, White.g, White.b, White.a);
    SDL_RenderClear(_Renderer);

    // Render Tiles
    for (int i = 0; i <= _numberOfTiles; i++)
    {
        if (checkTileCollision(_camera, tile[i].rect) == true)
        {
            if (tile[i].tileType == Wall)
            {
                SDL_SetRenderDrawColor(_Renderer, Black.r, Black.g, Black.b, Black.a);
            }
            else if (tile[i].tileType == Floor)
            {
                SDL_SetRenderDrawColor(_Renderer, Blue.r, Blue.g, Blue.b, Blue.a);
            }
            SDL_RenderFillRect(_Renderer, &tile[i].rect);
        }
    }

    for (int i = 0; i <= _numberOfObjects; i++)
    {
        if (checkTileCollision(_camera, object[i].rect) == true)
        {
            if (object[i].tileType == Box)
            {
                SDL_SetRenderDrawColor(_Renderer, Green.r, Green.g, Green.b, Green.a);
            }
            SDL_RenderFillRect(_Renderer, &object[i].rect);
        }
    }

    // Render Player
    SDL_SetRenderDrawColor(_Renderer, Red.r, Red.g, Red.b, Red.a);
    SDL_RenderFillRect(_Renderer, &Player);

    SDL_SetRenderDrawColor(_Renderer, Green.r, Green.g, Green.b, Green.a);
    SDL_RenderFillRect(_Renderer, &_Projectile);

    SDL_RenderPresent(_Renderer);
}

int main(int argc, char *argv[])
{
    initSDL();
    loadMap();
    loadObjMap();
//    _Projectile.x = tile[0].rect.x + playerX;
//    _Projectile.y = tile[0].rect.y + playerY;
//    int frames = 0;
    while (!_quit)
    {
        while (SDL_PollEvent(&_e) != 0)
        {
            if (_e.type == SDL_QUIT)
            {
                _quit = true;
            }
            pollControls();
        }

        // Move Player and check/handle tile collisions
        movePlayerX();
        movePlayerY();

        // Handle Projectile Movement
//        if (_middleClick == true)
//        {
//            if (frames <= _projectileFrames)
//            {
//                _Projectile.x += _projectileVelX;
//                _Projectile.y += _projectileVelY;
//                frames++;
//            }
//        }
//        if (!_shoot)
//        {
//            _Projectile.x = Player.x + tile[0].rect.x + Player.w/2 - _Projectile.w/2;
//            _Projectile.y = Player.y + tile[0].rect.y + Player.h/2 - _Projectile.h/2;
//        }

        // Check/handle mouse collisions
        handleMouseCollision();

        Render();
//        cout << object[0].getInitialX();
    }
    return 0;
}
