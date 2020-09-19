#ifndef BASEFACTORY_H
#define BASEFACTORY_H
#include <iostream>
using namespace std;

#include "BasePrint.h"

class BaseFactory {
	public:
		BaseFactory() {};
		virtual BasePrint* generatePrint(double value) = 0; 

};

#endif