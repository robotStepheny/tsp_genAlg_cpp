/*
 * GeneticAlgorithm.cpp
 *
 *  Created on: Feb 27, 2015
 *      Author: Stepheny
 */

#include "GeneticAlgorithm.h"
#include "Path.h"
#include <stddef.h>
#include <stdlib.h>
#include <iostream>

GeneticAlgorithm::GeneticAlgorithm()
{

}

Population GeneticAlgorithm::evolvePopulation(Population pop)
{
	Population newPop(pop.populationSize(), false);
	int eOffset = 0;

	if (elitism)
	{
		newPop.savePath(0, pop.getFittest());
		eOffset = 1;
	}

	for (int i = eOffset; i < newPop.populationSize(); i++)
	{
		Path parentA = tournamentSelection(pop);
		Path parentB = tournamentSelection(pop);
		Path child = crossover(parentA, parentB);
		//add child to new pop
		newPop.savePath(i, child);
	}

	for (int i = eOffset; i < newPop.populationSize(); i++)
	{
		mutate(newPop.getPath(i));
	}

	return newPop;
}

Path GeneticAlgorithm::crossover(Path& parentA, Path& parentB)
{
	Path child(1);

	int start = rand() % parentA.pathSize(); //random num within path size
	int end = rand() % parentA.pathSize(); //random num within path size

	for (int i = 0; i < child.pathSize(); i++)
	{
		if (start < end && i > start && i < end)
		{
			child.setCheckpoint(i, parentA.getCheckpoint(i));
		}

		else if (start > end)
		{
			if (!(i < start && i > end))
			{
				child.setCheckpoint(i, parentA.getCheckpoint(i));
			}
		}
	}

	for(int i = 0; i < parentB.pathSize(); i++)
	{
		//if child doesn't contain parent cp
		if (!child.containsCheckpoint(parentB.getCheckpoint(i)))
		{
			//find empty spot
			for (int j = 0; j < child.pathSize(); j++)
			{
				//check if spot is empty
				if (child.getCheckpoint(j).getX() == -777)
				{
					child.setCheckpoint(j, parentB.getCheckpoint(i));
					break;
				}
			}
		}
	}

	return child;

}

void GeneticAlgorithm::mutate(Path path)
{
	for (int i = 0; i < path.pathSize(); i++)
	{
		if (rand() < mutationRate)
		{						   
			Checkpoint point1 = path.getCheckpoint(i);
			Checkpoint point2 = path.getCheckpoint(j);

			//swap
			path.setCheckpoint(j, point1);
			path.setCheckpoint(i, point2);
		}
	}
}

Path& GeneticAlgorithm::tournamentSelection(Population pop)
{
	//create tournament pop
	Population tournament(tournamentSize, false);
	for (int i = 0; i < tournamentSize; i++)
	{
		//for every path in tournament - random path
		int ID = rand() % pop.populationSize();
		tournament.savePath(i, pop.getPath(ID));

	}
	Path& fittest = *(new Path(tournament.getFittest()));
	//Path fittest = tournament.getFittest();
	return fittest;
}
