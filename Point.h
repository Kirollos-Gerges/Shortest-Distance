#if !defined Point_h
#define Point_h

struct Point				// The name of the struct 
{
	
	double x, y, z;			//the members of the struct which are x,y,z of type double
	
};

/******************************************************************
 *
 * Desc : A function that creates the points using the structure point
 * Pre  : paramaters of x,y,z of a variable type of double
 * Post : dynamically allocated point
 *
 ******************************************************************/
 
Point* createPoint(double x, double y, double z);

/******************************************************************
 *
 * Desc : display the point to the screen
 * Pre  : a point
 * Post : nothing
 *
 ******************************************************************/
 
void displayPoint(Point* p);

/******************************************************************
 *
 * Desc : destroy the point after using
 * Pre  : a point
 * Post : nothing
 *
 ******************************************************************/
 
void destroyPoint(Point* p);

/******************************************************************/
 
#endif /* Point_h */