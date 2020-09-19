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
#include "BaseFactory.h"
#include "BasePrint.h"
#include "BinaryPrint.h"
#include "DoublePrint.h"
#include "HexPrint.h"
#include "BinaryFactory.h"
#include "DoubleFactory.h"
#include "HexFactory.h"
#include <sstream>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    BaseFactory* base = 0;
    //TEST BASEPRINT SUB CLASSES
    BinaryPrint* binaryPrint = new BinaryPrint(*argv[2]);
    DoublePrint* doublePrint = new DoublePrint(*argv[2]);
    HexPrint* hexPrint = new HexPrint(*argv[2]);

    binaryPrint->print();
    doublePrint->print();
    hexPrint->print();
    cout << endl;

    //TEST BASEFACTORY SUB CLASSES
    if (argc < 2) {
        cout << "No argument passed in" << endl;
        return 0;
    }
    string arg = argv[1];
    if (arg == "b") {
        cout << "New BinaryFactory created" << endl;
        base = new BinaryFactory();
    }
    else if (arg == "d") {
        cout << "New DoubleFactory created" << endl;
        base = new DoubleFactory();
    }
    else if (arg == "h") {
        cout << "New HexFactory created" << endl;
        base = new HexFactory();
    }
    else {
        cout << "Invalid argument" << endl;
        return 0;
    }

    Op* op1 = new Op(5);
    Op* op2 = new Op(3.5);
    Op* op3 = new Op(4);
    Op* op4 = new Op(6);
    Mult* A = new Mult(op1, op2);
    Sub* B = new Sub(op3, op4);
    Add* C = new Add(A, B);
    Sqr* D = new Sqr(C);

    // cout << D->evaluate() << endl;

    vectorContainer* container1 = new vectorContainer(base);
    container1->add_element(A);
    container1->add_element(B);
    container1->add_element(D);
    cout << "Vector container Before Sort: " << endl;
    container1->print();
    container1->set_sort_function(new BubbleSort());
    container1->sort();  
    cout << "Vector container After Sort: " << endl;
    container1->print(); 

  ListContainer* container2 = new ListContainer(base);
  container2->add_element(A);
  container2->add_element(B);
  container2->add_element(D);
  cout << "List container Before Sort: " << endl;
  container2->print();
  container2->set_sort_function(new SelectionSort());
  container2->sort(); 
  cout << "List container After Sort: " << endl;
  container2->print();

   // Floor* f = new Floor(A);
   // cout << f->evaluate()<<endl;
   // Ceil* ce = new Ceil(A);
   // cout << ce->evaluate()<<endl;
   // Abs* ab = new Abs(f);
   // cout << ab->evaluate()<<endl;

    return 0;
  
};
