/*
 * GeneticAlgorithm.h
 *
 *  Created on: Feb 27, 2015
 *      Author: Stepheny
 */

#ifndef GENETICALGORITHM_H_
#define GENETICALGORITHM_H_

#include "Population.h"
#include "Path.h"
class GeneticAlgorithm 
{
public:
	GeneticAlgorithm();
	static Population evolvePopulation(Population);
	static Path crossover(Path&, Path&);
	static void mutate(Path);
	static Path& tournamentSelection(Population);

private:
	static const double mutationRate = 0.02;
	static const int tournamentSize = 5;
	static const bool elitism = true;

};

#endif /* GENETICALGORITHM_H_ */
