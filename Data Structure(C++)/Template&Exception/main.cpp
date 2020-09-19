#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cstdlib>

using namespace std;

template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index) {
    unsigned minvalindex;
    minvalindex = index;
    for(unsigned i = index + 1; i < vals.size(); ++i) {
        if(vals.at(i) < vals.at(minvalindex)) {
            minvalindex = i;
        }
    }
    return minvalindex;
}

template<typename T>
void selection_sort(vector<T> &vals) {
    for (unsigned i = 0; i < vals.size(); ++i) {
        swap(vals.at(i), vals.at(min_index(vals,i)));
    }
    return;
}

template<typename T>
T getElement(vector<T> vals, int index) {
       unsigned i = index;
       if (i < 0 || i >= vals.size()) {
            throw out_of_range("out of range exception occured");   
         }
    return vals.at(index);
}



vector<char> createVector(){
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}







int main() {
    
    
    vector<string> a;
    a.push_back("abcd");
    a.push_back("cdef");
    a.push_back("like");
    a.push_back("zxczx");
    a.push_back("aaaaa");
    a.push_back("fffff");
    for (unsigned i = 0; i < a.size(); ++i) {
        cout << a.at(i) << ' ';
    }
    cout << endl;
    selection_sort(a);
    for (unsigned i = 0; i < a.size(); ++i) {
        cout << a.at(i) << ' ';
    }
    cout << endl;
    
    
      //Part B
     srand(time(0));
     vector<char> vals = createVector();
     char curChar;
     int index;
     int numOfRuns = 10;
     while(--numOfRuns >= 0){
         try {
         cout << "Enter a number: " << endl;
         cin >> index;
         curChar = getElement(vals,index);
         cout << "Element located at " << index << ": is " << curChar << endl;
         }
         catch (const out_of_range& excpt) {
              cout << excpt.what() << endl;
         }
    }  
    
    
    
    
    
    return 0;
}