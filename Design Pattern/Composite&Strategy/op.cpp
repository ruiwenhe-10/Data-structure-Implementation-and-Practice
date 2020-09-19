#include "op.h"

Op::Op(double num) : value(num){}

double Op::evaluate(){
	return value;
}
