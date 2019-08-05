#if !defined Points_h
#define Points_h
#include "Point.h"

struct Points
{
	Point** array;		//an array member of a structure type point
	int size; 			//num of elements in array
};

/******************************************************************
 *
 * Desc : create the points from a file
 * Pre  : a string of a filename
 * Post : dynamically allocated points
 *
 ******************************************************************/
 
Points* createPoints(const char* filename);

/******************************************************************
 *
 * Desc : display the points to the screen
 * Pre  : points
 * Post : nothing
 *
 ******************************************************************/
 
void displayPoints(Points* p);

/******************************************************************
 *
 * Desc : destroy the points after using
 * Pre  : points
 * Post : nothing
 *
 ******************************************************************/
 
void destroyPoints(Points* p);

/******************************************************************/

#endif /* Points_h */