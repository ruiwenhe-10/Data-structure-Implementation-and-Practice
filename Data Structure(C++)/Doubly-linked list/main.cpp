#include<iostream>

using namespace std;

#include "IntList.h"

int main() {
    
    
    IntList list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(4);
    list.push_back(34);
    list.push_back(21);
    // list.push_back(11);
    // list.pop_front();        //pop_back() works, i just test it
    list.pop_back();        //when the list is empty and i try to cout, i get seg fault(fixed!)
    
    
    cout << list << endl;

    
    // list.printReverse();
    
    
    return 0;
}