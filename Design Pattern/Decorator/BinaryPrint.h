#ifndef BINARYPRINT_H
#define BINARYPRINT_H

#include "BasePrint.h"
#include <cstdio>

#include <bitset>
class BinaryPrint : public BasePrint {
	private:
		double value;
	public:
		BinaryPrint(): value(0){};
		BinaryPrint(double value):value(value){};
		void print();
};

#endif