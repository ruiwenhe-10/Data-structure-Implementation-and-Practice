#ifndef MULT_H
#define MULT_H
#include "component.h"

class Mult : public Base {
    private:
		Base* lhs;
		Base* rhs;

    public:
		Mult(Base*, Base*);
		double evaluate();
};

#endif
