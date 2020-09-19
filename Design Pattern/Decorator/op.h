#ifndef OP_H
#define OP_H
#include "component.h"

class Op : public Base {
      private:
			double value;
      public:
			Op(double);
			double evaluate();
};

#endif

