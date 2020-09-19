#ifndef HEXPRINT_H
#define HEXPRINT_H
#include <iostream>
#include "BasePrint.h"

class HexPrint : public BasePrint {
	private:
		double value;
	public:
		HexPrint(): value(0){};
		HexPrint(double value): value(value){};
		void print();
};

#endif