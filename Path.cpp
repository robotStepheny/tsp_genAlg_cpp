/*
 * Path.cpp
 *
 *  Created on: Feb 27, 2015
 *      Author: Stepheny
 */

#include "Path.h"
#include <algorithm>
#include <sstream>
#include<iostream>


using namespace std;

Path::Path()
{
   fitness = 0;
	distance = 0;
	
   for (int i = 0; i < CheckpointHolder::numberOfCheckpoints(); ++i)
   {
      path.push_back(Checkpoint());
   }

   random_shuffle(path.begin(), path.end());
}

Path::Path(int x)
{
   fitness = 0;
	distance = 0;
	
	for (int i = 0; i < 25; i++)
	{
		Checkpoint cp(-777, -777, -777, -777);  //arbritrary
		path.push_back(cp);
	}
}

Path::Path(vector<Checkpoint> cph)
{
   fitness = 0;
   distance = 0;
	
   for (int i = 0; i < cph.size(); ++i)
   {
      path.push_back(Checkpoint(cph[i]));
      fitness = 1/getDistance();
   }
   random_shuffle(path.begin(), path.end());
   path = cph;
}

void Path::generateIndividual()
{
   for (int i = 0; i < CheckpointHolder::numberOfCheckpoints(); ++i)
   {
      setCheckpoint(i, CheckpointHolder::getCheckpoint(i));
   }

	random_shuffle(path.begin(), path.end());
}

Checkpoint Path::getCheckpoint(int pos)
{
	return path[pos];
}

void Path::setCheckpoint(int pathPos, Checkpoint point)
{
	path.at(pathPos) = Checkpoint(point);
	fitness = 0;
	distance = 0;
}

double Path::getFitness()
{
	if (!fitness) //fitness is 0
	{
		fitness = 1/getDistance();
	}
	return fitness;
}

//total path distance
int Path::getDistance()
{
	if (distance == 0)
	{
	   int totalPathDistance = 0;

	   for (int i = 0; i < pathSize(); i++)
	   {
	      Checkpoint start = getCheckpoint(i);
	      Checkpoint end;

		   start = path[i];
		   //check whether or not we are done traversing path
		   if (i + 1 < pathSize())
		   {
			   end = path[i+1];//if we are done, calculate from last point to beginning point
		   }
		   else
		   {
			   end = path[0];
		   }

		   int intermediateDist = start.distanceTo(end);
		   totalPathDistance += intermediateDist;

	   }

		distance = totalPathDistance;
	}

	return distance;
}

int Path::pathSize()
{
	return path.size();
}

bool Path::containsCheckpoint(Checkpoint point)
{
	for (int i= 0; i < path.size(); i++)
	{
		if (path[i].getX() == point.getX() &&
			path[i].getY() == point.getY() &&
			path[i].getZ() == point.getZ() &&
			path[i].getImportance() == point.getImportance())
			return true;
	}
	return false;
}

string Path::toString()
{
	stringstream fullPath;
	for (int i = 0; i < pathSize(); i++)
	{
		fullPath<<getCheckpoint(i).toString() << " -> ";
	}
	return fullPath.str();
}

void Path::shiftToStart()
{ 
	
	for (int i = 0; i < getDistance(); i++)
	{	//cannot have any points given with 0 importance
		if (path[0].getImportance() != 0)
		{
			rotate(path.begin(), path.end() - 1, path.end());
		}
		else 
		{
			break;
		}
	}
}

void Path::removeLowestH()
{
	double nodeValues[25];
	
	//starting point is path[0] which we do not want to get rid of
	for (int i = 1; i < 25; i++)
	{
		nodeValues[i] = path[i].getImportance()/(path[i-1].distanceTo(path[i]) + path[i].distanceTo(path[i+1]) - path[i-1].distanceTo(path[i+1]) );
	}

	//each point has a value now, find smallest:
	int smallest = 1;
	for (int i = 2; i < 25; i++)
	{
		if (nodeValues[i] < nodeValues[smallest])
		{
			smallest = i;
		}
	}
	path.erase(path.begin() + smallest);
	distance = 0;
}

void Path::addCheckpoint(Checkpoint p)
{
	path.push_back(p);
}

