#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <fstream>
#include <string>

using namespace std;

int main() {
    list<int> c;
    c.push_back(1);
    c.push_back(2);
    c.push_back(3);
    c.push_back(4);
    c.push_back(5);
    
    for (list<int>::iterator it = c.begin(); it != c.end(); ++it) {
        if ((*it) == 3) {
            it = c.erase(it);
        }
    }
    
    for (list<int>::iterator it = c.begin(); it != c.end(); ++it) {
        cout << ' ' << *it;
        
    }
    
    
    
    
    
    
    
    return 0;
}