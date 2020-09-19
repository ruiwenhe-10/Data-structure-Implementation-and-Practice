#include "sub.h"

Sub::Sub(Base* left, Base* right): lhs(left), rhs(right) {}

double Sub::evaluate() {
	return lhs->evaluate() - rhs->evaluate();
}
