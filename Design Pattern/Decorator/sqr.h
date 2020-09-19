#ifndef SQR_H
#define SQR_H

#include "component.h"

class Sqr : public Base {
	private:
		Base* expression;

	public:
		Sqr(Base*);		
	 	double evaluate();

};

#endif
