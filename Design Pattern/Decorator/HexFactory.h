#ifndef HEX_FACTORY_H
#define HEX_FACTORY_H
#include "BaseFactory.h"
#include "HexPrint.h"

class HexFactory: public BaseFactory{
	public:
		HexFactory() {};
		BasePrint* generatePrint(double value);
};

#endif