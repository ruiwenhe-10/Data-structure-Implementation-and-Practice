#ifndef DOUBLEPRINT_H
#define DOUBLEPRINT_H
#include "BasePrint.h"

class DoublePrint : public BasePrint {
	private:
		double value;
	public:
		DoublePrint(): value(0) {};
		DoublePrint(double value) : value(value) {};
		void print();
};

#endif