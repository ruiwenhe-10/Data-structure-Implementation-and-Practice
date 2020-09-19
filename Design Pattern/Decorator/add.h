#ifndef ADD_H
#define ADD_H

#include "component.h"

class Add : public Base {
   private: 
		Base* lhs;
		Base* rhs;

   public:
		Add(Base*, Base*);
		double evaluate();
};

#endif
