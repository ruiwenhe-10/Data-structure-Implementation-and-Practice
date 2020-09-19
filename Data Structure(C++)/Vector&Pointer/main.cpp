#include <iostream>


using namespace std;

#include "IntVector.h"


int main() {
    IntVector a(0);
    
    cout << a.size() << endl;
    cout << a.capacity() << endl;
    if (a.empty()) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    
    a.insert(0, 1);
    for (unsigned i = 0; i < a.size(); ++i) {
        cout << a.at(i) << ' ';
    }
    cout << endl;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}