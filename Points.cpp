#include "Points.h"
#include <iostream>
#include <fstream>

using namespace std;

Points* createPoints(const char* filename)                          					//A Function to create points 
{
	ifstream infile(filename);															//reading from a file
	
	if(infile.fail())																	//in case of failing to read the file
	{
		
		cout << "Error reading the file :" << filename << "check your input" <<endl;	//input error message
		return 0;																		//will terminate the program
	}
  
	Points* p = new Points;																//dynamically allocating points
	
	infile >> p->size;																	//reading the first line which is actually the size
	
	p->array = new Point*[p->size];														//setting the array size to the read value of the first line wile dynamically allcotaing it. 
	
	double x;																			//declaring x as variable of type double
	double y;																			//declaring y as variable of type double
	double z;																			//declaring z as variable of type double
	
	for(int i = 0; i< p->size; i++)														//looping through to get the values of the parameters
	{
		infile >> x >> y >> z;															//reading x and then in the next line y and then z since we start now from index 1
		p->array[i] = createPoint(x, y, z);												//we will create the points parameters and putting it in the array
	}
	infile.close();																		//will close the file
	
	return p;																			
}

void displayPoints(Points* p)															//A Function to display the collection of points 
{
	for(int i = 0; i< p->size; i++)														//looping through
	{
		
		displayPoint(p->array[i]);														//will diplay every point's parameters(x,Y,Z) consequently till we finish the collection we got
	
	}
}

void destroyPoints(Points* p)															//will destroy the dynamically allocated array we created after being done with it.
{
	for(int i = 0; i< p->size; i++)														//looping through
	{
		
		destroyPoint(p->array[i]);														//destroy each point parameters (X,Y,Z)
		
	}
	delete []p->array;																	//will delete the array
	delete p;
}