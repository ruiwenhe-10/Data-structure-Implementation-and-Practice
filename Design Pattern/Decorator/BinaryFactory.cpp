#include <iostream>
#include "BinaryFactory.h"

using namespace std;

BasePrint* BinaryFactory::generatePrint(double value){
	BinaryPrint* b = new BinaryPrint(value);
	return b;
}