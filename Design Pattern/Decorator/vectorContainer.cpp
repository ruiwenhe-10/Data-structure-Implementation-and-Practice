#include <iostream>
#include "container.h"
#include "vectorContainer.h"
#include "component.h"
#include "strategy.h"
#include "BasePrint.h"
#include "BaseFactory.h"

using namespace std;

vectorContainer::vectorContainer(BaseFactory* factory) {
	this->factory = factory;
}

void vectorContainer::add_element(Base* b){
  	container.push_back(b);
}

void vectorContainer::print(){
	BasePrint* baseP = 0;

	for (unsigned i = 0; i < container.size(); i++){
		baseP = factory->generatePrint(container.at(i)->evaluate());
		baseP->print();
	}
}

void vectorContainer::sort(){
	sort_function->sort(this);
}

void vectorContainer::swap(int x, int y){
	Base* temp = container.at(x);
	container.at(x) = container.at(y);
	container.at(y) = temp;	
}

Base* vectorContainer::at(int x){
	return container.at(x);
}

unsigned vectorContainer::size(){
	return container.size();
}
