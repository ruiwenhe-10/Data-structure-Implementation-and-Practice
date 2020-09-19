#include "div.h"

Div::Div(Base* left, Base* right): lhs(left), rhs(right) {}

double Div::evaluate(){
return lhs->evaluate() / rhs->evaluate();
}
