/*
 * Path.h
 *
 *  Created on: Feb 27, 2015
 *      Author: Stepheny
 */

#ifndef PATH_H_
#define PATH_H_

#include <vector>
#include "Checkpoint.h"
#include "CheckpointHolder.h"


using namespace std;

class Path {
public:
   Path();
	Path(int);
	Path(vector<Checkpoint>);
	void generateIndividual();
	Checkpoint getCheckpoint(int);
	void setCheckpoint(int, Checkpoint);
	double getFitness();
	int getDistance();
	int pathSize();
	bool containsCheckpoint(Checkpoint);
	string toString();
	void removeLowestH();
	void shiftToStart();
	void addCheckpoint(Checkpoint);

private:
	vector<Checkpoint> path;
	double fitness;
	int distance;

};

#endif /* PATH_H_ */
