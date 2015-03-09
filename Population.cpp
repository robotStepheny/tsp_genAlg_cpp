/*
 * Population.cpp
 *
 *  Created on: Feb 27, 2015
 *      Author: Stepheny
 */

#include "Population.h"
#include "Path.h"

//create a population of paths
Population::Population(int popSize, bool init) {
   paths = new Path[popSize];
   size = popSize;

	if (init)
	{
	   Path* newPath;
		for (int i = 0; i < popSize; i++)
		{
			newPath = new Path(); //this might be an issue, what is it copying? Is it copying from checkpoint holder? actually yeah I think so
			newPath->generateIndividual();
			savePath(i, *newPath);
		}
	}
}

void Population::savePath(int index, Path path)
{
	paths[index] = path;
}

Path Population::getPath(int index)
{
	return paths[index];
}

Path Population::getFittest()
{
	Path fittest = paths[0];
	for (int i = 1; i < populationSize(); i++)
	{
		if (fittest.getDistance() > getPath(i).getDistance())
		{
			fittest = getPath(i);
		}
	}
	return fittest;
}

int Population::populationSize()
{
	return size;
}
