#include <iostream>


using namespace std;


#include "IntList.h"


IntList::IntList() {
    dummyHead = new IntNode(0);
    dummyTail = new IntNode(0);
}

IntList::~IntList() { //destructor now works
    while(!empty()) {
        pop_front();
    } 
}


void IntList::push_front(int value) {
    
    IntNode* temp = new IntNode(value);
  
    if (dummyHead->next == 0) {//empty list
        dummyHead -> next = temp;
        dummyTail -> prev = temp;
        
    }
    else {
        
        temp -> next = dummyHead -> next;       
        dummyHead -> next -> prev = temp;
        dummyHead -> next = temp;
        
    }
 return;
}



void IntList::pop_front() {                     //this popfront works
    if(dummyHead -> next == 0) {
        return;
    }
    else {
        IntNode* temp = dummyHead -> next;
        if (temp -> next == 0)     {            //check if there is only one node in the list
            dummyHead -> next = 0;
            dummyTail -> prev = 0;
        }
        else {
            dummyHead -> next = temp -> next;
            temp -> next -> prev = 0;
        }
        delete temp;
    }
}

void IntList::push_back(int value) {
    IntNode* temp = new IntNode(value);
    if (dummyHead -> next == 0) {               //empty list
        dummyHead -> next = temp;
        dummyTail -> prev = temp;
    }
    else {
        dummyTail -> prev -> next = temp;
        temp -> prev = dummyTail -> prev;
        dummyTail -> prev = temp;
    }
    
}

void IntList::pop_back() {
   if(dummyTail -> prev == 0) {
      return;
   }
   else {
    IntNode* temp = dummyTail -> prev;  //record the last note
    if (temp -> prev == 0) {            //check if there is only one node in the list
        dummyHead -> next = 0;
        dummyTail -> prev = 0;
    }
    else {
    dummyTail -> prev = temp -> prev;
    temp -> prev -> next = 0;
    }
    delete temp;
    }
    
}


bool IntList::empty() const {
    if (dummyHead -> next == 0) {
        return true;
    }
    else {
        return false;
    }
}

ostream & operator<<(ostream &out, const IntList &rhs)  {
    for (IntNode* current = rhs.dummyHead -> next; current != 0; current = current -> next) { 
    out << current -> data;
    if (current -> next != 0) {
        out << " ";
    }
    }
    return out;
}


void IntList::printReverse() const {

    if(dummyTail == 0) {
        return;
    }
    for(IntNode* current = dummyTail->prev; current != 0; current = current->prev) {
        cout << current->data << " ";
    }

}