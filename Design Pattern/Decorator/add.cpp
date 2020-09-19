#include "add.h"

Add::Add(Base* left, Base* right): lhs(left), rhs(right) {}

double Add::evaluate(){
	return lhs->evaluate() + rhs->evaluate();
}
