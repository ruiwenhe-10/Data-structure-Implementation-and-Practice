#include "mult.h"

Mult::Mult(Base* left, Base* right): lhs(left), rhs(right){}

double Mult::evaluate(){
	return lhs->evaluate() * rhs->evaluate();
}
