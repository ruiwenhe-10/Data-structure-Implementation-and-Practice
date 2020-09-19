#include "sqr.h"

Sqr::Sqr(Base* expression): expression(expression) {}

double Sqr::evaluate() {
	return expression->evaluate() * expression->evaluate();
}
