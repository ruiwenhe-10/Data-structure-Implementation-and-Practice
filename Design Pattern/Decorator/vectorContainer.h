#ifndef VECTORCONTAINER_H
#define VECTORCONTAINER_H

#include "container.h"
#include "component.h"
#include <vector>
class vectorContainer:public Container{
   private:
		vector<Base*> container;
   public:
		vectorContainer(BaseFactory*);
		void add_element(Base*);
		void print();
		void sort();
		void swap(int, int);
		Base* at(int);
		unsigned size();	

};

#endif
