#ifndef BASEPRINT_H
#define BASEPRINT_H
#include <iostream>
using namespace std;
class BasePrint {
	private:
		/* Value to Print */
		double value;

	public:
		/* Constructors */
		BasePrint() : value(0) {};
		BasePrint(double value) : value(value) {};
		
		/* Pure Virtual Print Function */
		virtual void print() = 0;
};

#endif