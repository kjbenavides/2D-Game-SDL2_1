#ifndef GLOBALS_H_INCLUDED
#define GLOBALS_H_INCLUDED

/*
    Global variables
*/

extern bool _quit;

extern bool _leftClick;
extern bool _rightClick;
extern bool _middleClick;

extern int _windowWidth;
extern int _windowHeight;
extern int _screenWidth;
extern int _screenHeight;

extern int _numberOfTiles;
extern int _numberOfObjects;

extern int _mouseX;
extern int _mouseY;

extern SDL_Window *_Window;
extern SDL_Renderer *_Renderer;
extern SDL_Event _e;

extern SDL_Rect _camera;
extern int _cameraX; extern int _cameraY; extern int _cameraNewX; extern int _cameraNewY; extern int _cameraVelX; extern int _cameraVelY;


#endif // GLOBALS_H_INCLUDED
