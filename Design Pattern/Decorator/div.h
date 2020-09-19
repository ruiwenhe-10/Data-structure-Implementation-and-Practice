#ifndef DIV_H
#define DIV_H
#include "component.h"

class Div : public Base {
     private:
		Base* lhs;
		Base* rhs;

     public:
		Div(Base*, Base*);
		double evaluate();	

};

#endif
