/*
 * Population.h
 *
 *  Created on: Feb 27, 2015
 *      Author: Stepheny
 */

#ifndef POPULATION_H_
#define POPULATION_H_

#include "Path.h"
#include "CheckpointHolder.h"

class Population {
public:
	Population();
	Population(int, bool);
	void savePath(int, Path);
	Path getPath(int);
	Path getFittest();
	int populationSize();

private:
	Path* paths;
	int size;

};

#endif /* POPULATION_H_ */
