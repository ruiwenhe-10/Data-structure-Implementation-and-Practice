#include <iostream>
#include "strategy.h"
// #include "container.h"

void SelectionSort::sort(Container* container) {
	for (unsigned i = 0; i < container->size(); ++i) {
		unsigned min = i;
		for (unsigned j = i+ 1; j < container->size(); ++j) {
			if ((*container).at(j)->evaluate() < (*container).at(min)->evaluate()) {
				min = j;
			}
		}
		container->swap(i, min);
	}
}

void BubbleSort::sort(Container* container) {
	for (unsigned i = 0; i < container->size(); ++i) {
		for (unsigned j = 0; j < container->size() - 1; ++j) {
			if ((*container).at(j)->evaluate() > (*container).at(j+1)->evaluate()) {
				container->swap(j, j+1);
			}
		}
	}
}
