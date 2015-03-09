/*
 * Checkpoint.h
 *
 *  Created on: Feb 26, 2015
 *      Author: Stepheny
 */

#include <string>

#ifndef CHECKPOINT_H_
#define CHECKPOINT_H_

using std::string;

class Checkpoint {
public:
	Checkpoint();
	Checkpoint(double, double, double, int);
	virtual ~Checkpoint();
	double getX();
	double getY();
	double getZ();
	void setX(int);
	int getImportance();
	double distanceTo(Checkpoint point);
	string toString();

private:

	double x;
	double y;
	double z;
	int importance;

};

#endif /* CHECKPOINT_H_ */
