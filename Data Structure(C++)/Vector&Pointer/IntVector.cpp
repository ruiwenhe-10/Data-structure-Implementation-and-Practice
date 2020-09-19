#include<iostream>
#include<stdexcept>
using namespace std;


#include "IntVector.h"

//     unsigned sz;               // stores the size of the IntVector (the number of elements currently being used).
//     unsigned cap;              // store the size of the array
//     int *data;                 //stores the address of the dynamically-allocated array of integers
    
IntVector::IntVector() {
    sz = 0;
    cap = 0;
    data = 0;
}

IntVector::IntVector(unsigned size, int value) {
    sz = size;
    cap = size;
    data = new int[size];
    for (unsigned i = 0; i < size; ++i) {
        data[i] = value;
    }
}

IntVector::~IntVector() {
  delete[] data;  
}

unsigned IntVector::size() const {
    return sz;
}

unsigned IntVector::capacity() const {
    return cap;
}

bool IntVector::empty() const {
    bool em = false;
    if (sz == 0) {
        em = true;
    }
    return em;
}

const int & IntVector::at(unsigned index) const {
    if(index >= sz) {
        throw out_of_range("IntVector::at_range_check");
    }
    return data[index];
}

const int & IntVector::front() const {
    return data[0];
}

const int & IntVector::back() const {
    return data[sz - 1];
}

void IntVector::expand() {
    if (cap != 0) {
        cap = cap * 2;
        int* temp = new int[cap];
        for (unsigned int i = 0; i < sz; ++i) {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
    }
    else {
        cap = 1;
        if (data == 0) {
            data = new int[1];
        }
    }
}

void IntVector::expand(unsigned amount) {
    if (cap != 0) {
        cap = cap + amount;
        int* temp = new int[cap];
        for (unsigned int i = 0; i < sz; ++i) {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
    }
    else {
        cap = amount;
        
        if (data == 0) {
            data = new int[amount];
        }
    }
}

void IntVector::insert(unsigned index, int value) {
    if (index >= 0 && index <= sz) {
        if (sz == cap) {
        expand();
        }
        sz = sz + 1;
        for (unsigned int i = sz - 1; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = value;
    }
    else {
        throw out_of_range("IntVector::insert_range_check");
    }
}

// void IntVector::insert(unsigned index, int value) {
//             if (index > sz - 1) {
//                 throw out_of_range("IntVector::insert_range_check");
//             }
              
//                 // sz = sz + 1;
                
//                 // if (cap < sz) {
//                 //     expand();
                   
//                 // }
//                 if (sz + 1 > cap) {
//                     expand();
//                 }
//               sz = sz + 1;
//                 for (unsigned int i = sz - 1; i > index; i--) {

//                         data[i] = data[i-1];
//                 }
//                 data[index] = value; 

            
//         }

void IntVector::erase(unsigned index) {
    if (index < sz) {
        for (unsigned int i = index; i + 1 < sz; ++i) {
            data[i] = data[i + 1];
        }
    sz = sz - 1;
    }
    else {
        throw out_of_range("IntVector::erase_range_check");
    }
}

void IntVector::push_back(int value) {
    sz = sz + 1;
    if (sz > cap) {
    expand();
    }
    data[sz - 1] = value;
}

void IntVector::pop_back() {
    sz = sz - 1;
}

void IntVector::clear() {
    sz = 0;
}

void IntVector::resize(unsigned size, int value) {
  if (size > cap * 2) {
      expand(size - cap);
  }
  else if (size > cap) {
      expand();
  }
  if (size < sz) {
      sz = size;
  }
  if (size > sz) {
      int a = sz;
      sz = size;
      for (unsigned i = a; i < sz; ++i) {
          data[i] = value;
      }
  }
}

void IntVector::reserve(unsigned n) {
    if (n > cap) {
    expand(n - cap);
    }
}

void IntVector::assign(unsigned n, int value) {
    resize(n);
    sz = n;
    for(unsigned int i = 0; i < sz; ++i) {
        data[i] = value;
    }
}

int & IntVector::at(unsigned index) {
    if(index >= sz) {
        throw out_of_range("IntVector::at_range_check");
    }
    return data[index];
}

int & IntVector::front() {
    return data[0];
}

int & IntVector::back() {
    return data[sz - 1];
}