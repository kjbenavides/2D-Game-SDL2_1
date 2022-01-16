#include <SDL.h>

bool _quit = false;

bool _leftClick = false;
bool _rightClick = false;
bool _middleClick = false;

int _windowWidth = 640;
int _windowHeight = 480;
int _screenWidth = _windowWidth*2;
int _screenHeight = _windowHeight*2;

int _numberOfTiles = 0;
int _numberOfObjects = 0;

int _mouseX = 0;
int _mouseY = 0;

SDL_Window *_Window = NULL;
SDL_Renderer *_Renderer = NULL;
SDL_Event _e;

SDL_Rect _camera = {0, 0, 640, 480};
int _cameraX; int _cameraY; int _cameraNewX; int _cameraNewY; int _cameraVelX; int _cameraVelY;

SDL_Rect _Projectile = {0, 0, 4, 4};
int _projectileVelX = 0;
int _projectileVelY = 0;
int _projectileSpeed = 2;
int _projectileFrames = 10;
int _projectileLocX = 0;
int _projectileLocY = 0;
bool _shoot = false;
