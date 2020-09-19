#ifndef DOUBLE_FACTORY_H
#define DOUBLE_FACTORY_H
#include "BaseFactory.h"

class DoubleFactory: public BaseFactory{
	public:
		DoubleFactory() {};
		BasePrint* generatePrint(double value);
};

#endif