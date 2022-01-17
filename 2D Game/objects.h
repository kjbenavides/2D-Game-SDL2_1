#ifndef OBJECTS_H_INCLUDED
#define OBJECTS_H_INCLUDED

/*
	Loads a specific objMap file and
	places objects around the map
	@returns true if the map loads successfully
*/
bool loadObjMap();

extern Tile object[]; // Global object array

#endif // OBJECTS_H_INCLUDED
