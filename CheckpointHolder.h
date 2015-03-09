/*
 * CheckpointHolder.h
 *
 *  Created on: Feb 27, 2015
 *      Author: Stepheny
 */

#ifndef CHECKPOINTHOLDER_H_
#define CHECKPOINTHOLDER_H_

#include <vector>
#include "Checkpoint.h"

using namespace std;

class CheckpointHolder {
public:
	static void addCheckpoint(Checkpoint);
	static Checkpoint getCheckpoint(int);
	static int numberOfCheckpoints();
	static vector<Checkpoint> allCheckpoints;
};

#endif /* CHECKPOINTHOLDER_H_ */
