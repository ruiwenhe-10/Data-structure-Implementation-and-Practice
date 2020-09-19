#include <iostream>
#include "HexFactory.h"
#include "HexPrint.h"

BasePrint* HexFactory::generatePrint(double value){
	HexPrint* h = new HexPrint(value);
	return h;
}