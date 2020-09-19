#include <iostream>
#include <list>
#include "strategy.h"
#include "list_container.h"
#include "component.h"
#include "container.h"
#include "BasePrint.h"
#include "BaseFactory.h"

using namespace std;

ListContainer::ListContainer(BaseFactory* factory) {
	this->factory = factory;
}

void ListContainer::add_element(Base* element) {
	container.push_back(element);
}

void ListContainer::print() {
	list<Base*>::iterator index;
	BasePrint* baseP = 0;

	for (index = container.begin(); index != container.end(); ++index) {
		baseP = factory->generatePrint((*index)->evaluate());
		baseP->print();
	}
}

void ListContainer::sort() {
	sort_function->sort(this);
}

void ListContainer::swap(int i, int j) {
	list<Base*>::iterator it1 = container.begin();
	int counter1 = i;

	while (counter1 != 0) {
		++it1;
		--counter1;
	}

	list<Base*>::iterator it2 = container.begin();
	int counter2 = j;

	while (counter2 != 0) {
		++it2;
		--counter2;
	}

	//swapping
	Base* temp = *it1;
	*it1 = *it2;
	*it2 = temp;
}

Base* ListContainer::at(int i) {
	list<Base*>::iterator index = container.begin();
	int counter = i;

	while (counter != 0) {
		++index;
		--counter;
	}

	return *index;
}

unsigned ListContainer::size() {
	return container.size();
}