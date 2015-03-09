/*
 * CheckpointHolder.cpp
 *
 *  Created on: Feb 27, 2015
 *      Author: Stepheny
 */

#include "CheckpointHolder.h"
#include<iostream>

using namespace std;

vector<Checkpoint> CheckpointHolder::allCheckpoints;

void CheckpointHolder::addCheckpoint(Checkpoint point)
{
    //cout << "adding cp: " << point.toString() << endl;
	CheckpointHolder::allCheckpoints.push_back(Checkpoint(point));
}

Checkpoint CheckpointHolder::getCheckpoint(int index)
{
	return CheckpointHolder::allCheckpoints[index];
}

int CheckpointHolder::numberOfCheckpoints()
{
	return CheckpointHolder::allCheckpoints.size();
}
