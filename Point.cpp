#include "Point.h"
#include <iostream>
#include <iomanip>

using namespace std;

Point* createPoint(double x, double y, double z) //A function to create the point
{
	Point* p = new Point;						 //Dynamically allocate the point structure
	
	p->x = x;									 //Setting x to refer to the member x of the structure point 
	p->y = y;									 //Setting y to refer to the member y of the structure point 
	p->z = z;							   		 //Setting z to refer to the member z of the structure point 
	
	return p;
}

void displayPoint(Point* p)						 //A function to display the point
{
	cout << setprecision(3)<< fixed;			 //Setting the precision to be up to 3 decimal places
	cout << "(" << setw(6) << right << p->x << ", " << setw(7) << right << p->y << ", " << setw(6) << right  << p->z << ")" << endl;		//to output the points with adjustments
	

}

void destroyPoint(Point* p)						 //A function to delete the point
{
	delete p;
}