#include <iostream>
#include "component.h"
#include "vectorContainer.h"
#include "list_container.h"
#include "strategy.h"
#include "op.h"
#include "add.h"
#include "sub.h"
#include "mult.h"
#include "div.h"
#include "sqr.h"
#include "decorator.h"
#include "floor.h"
#include "ceil.h"
#include "abs.h"


using namespace std;

int main() {
    Op* op1 = new Op(5);
    Op* op2 = new Op(3.5);
    Op* op3 = new Op(4);
    Op* op4 = new Op(6);
    Mult* A = new Mult(op1, op2);
    Sub* B = new Sub(op3, op4);
    Add* C = new Add(A, B);
    Sqr* D = new Sqr(C);


   vectorContainer* container1 = new vectorContainer();
   ListContainer* container2 = new ListContainer();

   container1->add_element(A);
   container1->add_element(B);
   container1->add_element(D);

   container2->add_element(A);
   container2->add_element(B);
   container2->add_element(D);

   cout << "Vector container Before Sort: " << endl;
   container1->print();
   container1->set_sort_function(new BubbleSort());
   container1->sort();	
   cout << "Vector container After Sort: " << endl;
   container1->print(); 

   cout << "List container Before Sort: " << endl;
   container2->print();
   container2->set_sort_function(new SelectionSort());
   container2->sort(); 
   cout << "List container After Sort: " << endl;
   container2->print();

   Floor* f = new Floor(A);
   cout << f->evaluate()<<endl;
   Ceil* ce = new Ceil(A);
   cout << ce->evaluate()<<endl;
   Abs* ab = new Abs(f);
   cout << ab->evaluate()<<endl;
  
};
