#ifndef SUB_H
#define SUB_H
#include "component.h"

class Sub : public Base {

    private:
		Base* lhs;
		Base* rhs;

    public:
		Sub(Base*, Base*);
		double evaluate();
};

#endif