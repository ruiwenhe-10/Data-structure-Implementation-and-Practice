#include <iostream>
#include <cmath>

#include "decorator.h"

double Ceil::evaluate(){
 return ceil(decorated->evaluate());
}

double Floor::evaluate(){
 return floor(decorated->evaluate());
}

double Abs::evaluate(){
 return abs(decorated->evaluate());
}
