#include <iostream>
#include "DoubleFactory.h"
#include "DoublePrint.h"

using namespace std;

BasePrint* DoubleFactory::generatePrint(double value){
	DoublePrint* d = new DoublePrint(value);
	return d;
}