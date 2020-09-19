#ifndef DECORATOR_H
#define DECORATOR_H

#include "component.h"

class Decorator:public Base {
	protected:
		Base* decorated;
	public:
		Decorator():decorated(NULL){}
		Decorator(Base* b): decorated(b) {}
		virtual double evaluate() = 0;
};

class Ceil : public Decorator {
	public:
		Ceil(Base* b): Decorator(b) {}
		double evaluate();
};

class Floor : public Decorator {
	public:
		Floor(Base* b): Decorator(b) {}
		double evaluate();
};

class Abs : public Decorator {
	public:
		Abs(Base* b): Decorator(b) {};
		double evaluate();
};

#endif
