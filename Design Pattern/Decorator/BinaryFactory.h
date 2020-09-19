#ifndef BINARY_FACTORY_H
#define BINARY_FACTORY_H
#include "BaseFactory.h"
#include "BinaryPrint.h"

class BinaryFactory: public BaseFactory{
	public:
		BinaryFactory() {};
		BasePrint* generatePrint(double value);
};

#endif