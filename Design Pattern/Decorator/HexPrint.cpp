#include <iostream>
#include <stdio.h>
#include "HexPrint.h"

using namespace std;

void HexPrint::print() {
	printf("%#x", *(unsigned int*)&value);
	cout << endl;
}