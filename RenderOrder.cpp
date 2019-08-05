//Kirollos Gerges, ME Student, T00271723

//program Describtion:

/*When working with graphics and computers it is often advantageous to know the relative
position of one object to other objects in the scene. Imagine you have a camera looking
at a collection of spheres in a scene, if one sphere blocks out part of a second sphere,
those portions do not need to be drawn. This concept is called occlusion and enables us
to draw more complicated scenes using less CPU cycles and produce graphics faster.
For this program, you will create multiple files to allow the program to sort a collection
of points so that you can find out which points fall behind others allowing them to be skipped.
The points to be sorted will be read in from a file the user will specify using command line arguments.
 */
 
/*Build : g++ -c RenderOrder.cpp Points.cpp point.cpp
		: g++ -o RenderOrder.exe RenderOrder.o Points.o Point.o
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include "Points.h"

using namespace std;

void sortPointsByDistance(Points* p, Point refPoint);																	//A function prototype for sorting the points with repspect to the distance

float distanceFromRefPoint(Point p, Point refPoint);																	//A function prototype for getting the distance from a reference point

void sortPointsByDistance(Points* p, Point refPoint)																	//The function for sorting the points with repspect to the distance (selection sort)
{
	// Variables
	
	int i;
	int j;
	int min;
	Point temp;

	for(i = 0; i < p->size; i++)																						//looping through
	{
		min = i;																										//setting the min index to i
		j = i+1;																										//setting j for us to start from the 2nd index
		for(j; j < p->size; j++)
		{
			if(distanceFromRefPoint(*(p->array[j]), refPoint) > distanceFromRefPoint(*(p->array[min]), refPoint))       //to get it descendingly we've got to see if the following index is greater than the first
			min = j;																									//will set the following index to the min index in case its greater
		}

		if(i != min)																									//incase not the minimum index
		{
			//to swap where we will set to a temporary
			
			temp = *(p->array[i]);
			
			*(p->array[i]) = *(p->array[min]);
			
			*(p->array[min]) = temp;
		}
	}

}

float distanceFromRefPoint(Point p, Point refPoint)																	//The function that manipulate the distance from the reference point
{
	double disX = p.x - refPoint.x;																						//The Parameter of the distance of x
	double disY = p.y - refPoint.y;																						//The Parameter of the distance of y
	double disZ = p.z - refPoint.z;																						//The Parameter of the distance of z
	
	return sqrt( disX * disX + disY * disY + disZ * disZ);																//the point itself

}

int main(int argc, char* argv[])																						//the main function with a command line argument for the parameters
{
		
	if(argc != 5)																										//in case not getting 5 command line arguments
	{
		
		cout << "please input filename and reference point co-ordinates as command line arguments" << endl;				//giving a message to put the correct formate
		cout << "As of: " << argv[0] << " filename x y z" << endl;
		
		return 1;
	}

	Points *p = createPoints(argv[1]);																					//to create the points array from the file
	
	Point *refPoint = createPoint(atof(argv[2]), atof(argv[3]), atof(argv[4]));											//creating the reference points from the inputed parameters in the command line
	
	if(p != 0)																											//if we get the array
	{	
		cout << "" << endl;
		cout << "Unsorted:" << endl;																					//will display the unsorted array of points
		cout << "" << endl;
		displayPoints(p);

		sortPointsByDistance(p, *refPoint);																				//will sort the points descendingly with respect to the reference points

		cout << "" << endl;
		cout << "Sorted:" << endl;																						//will print out the sorted points
		cout << "" << endl;
		displayPoints(p);

	}
}


