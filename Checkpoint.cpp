/*
 * Checkpoint.cpp
 *
 *  Created on: Feb 26, 2015
 *      Author: Stepheny
 */

#include "Checkpoint.h"
#include <cmath>
#include <sstream>

using namespace std;

Checkpoint::Checkpoint()
{

}

/* for 3D points, uncomment adding in Z -- currently set for 2D*/

Checkpoint::Checkpoint(double x2, double y2, int i);//double z2, int i)
{
	x = x2;
	y = y2;
	//z = z2;
	importance = i;
}

Checkpoint::~Checkpoint()
{
}

double Checkpoint::getX()
{
	return x;
}
double Checkpoint::getY()
{
	return y;
}

/*double Checkpoint::getZ()
{
	return z;
}*/

void Checkpoint::setX(int val)
{
	x = val;
}

int Checkpoint::getImportance()
{
	return importance;
}

//calculate straight line distance between two 3d points
double Checkpoint::distanceTo(Checkpoint point)
{
	double xDistance = abs (x - point.getX());
	double yDistance = abs (y - point.getY());
	//double uptime = ( 6 - point.getZ() + 6 - z ) / 0.7;
	
	double distance = sqrt((xDistance*xDistance) + (yDistance*yDistance) ) / 2 ;

	return distance;// + uptime;
}

string Checkpoint::toString()
{
	stringstream s;
	s << "(" << x << ", " << y << ", " << z << ")" << "[" << importance << "]";
	return s.str();

}



