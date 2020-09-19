#ifndef LIST_CONTAINER_H
#define LIST_CONTAINER_H

#include <list>
#include "container.h"

class ListContainer : public Container {

	private: 
		list<Base*> container;

	public:
        	ListContainer(BaseFactory*);
                void add_element(Base* element);
                void print();
                void sort();
                void swap(int i,int j);
                Base* at(int i);
                unsigned size();
};

#endif