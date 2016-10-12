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

/* 	uncomment all references to Z if you want a 3D point 
	I should really just inherit it..... gah
*/

class Checkpoint 
{
public:
	Checkpoint();
	Checkpoint(double, double);
	Checkpoint(double, double, int);// double, int);
	virtual ~Checkpoint();
	double getX();
	double getY();
	//double getZ();
	void setX(int);
	int getImportance();
	double distanceTo(Checkpoint);
	string toString();

private:

	double x;
	double y;
	//double z;
	int importance;

};

#endif /* CHECKPOINT_H_ */
