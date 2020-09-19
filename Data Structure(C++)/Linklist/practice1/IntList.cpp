#include <iostream>
#include <cstdlib>
using namespace std;

#include "IntList.h"

IntList::IntList() {
    head = 0;
    tail = 0;
}

IntList::~IntList() {
    IntNode* temp;
    
    while(head) {         //destructor that loops through entire list and deletes
        temp = head -> next;        //grabs head by temp, then reassigns head, and deletes temp
        delete head;
        head = temp;
	}
}

void IntList::display() const {
    IntNode* current;
    if (head) {
        cout << head -> data;
        for (current = head -> next; current != 0; current = current -> next) {
            cout << ' ' << current -> data;
        }
    }
    return;
}

void IntList::push_front(int value) {
    IntNode* tmp = new IntNode(value);
    if (head){
    tmp->next = head;
    head = tmp;
    }
    else {
        head = tmp;
        tail = tmp;
    }
    
}
    
void IntList::pop_front() {
    if (head) {
        IntNode* tem = head;
        head = head->next;
        delete tem;
    }
}

bool IntList::empty() const {
    bool emp = false;
    if(head == 0) {
         emp = true;
    }
    else {
        emp = false;
    }
    return emp;
}    

IntList::IntList(const IntList &cpy) {
    head = 0;
    tail = 0;
    for (IntNode *curr = cpy.head; curr != 0; curr = curr->next)
    {
        push_back(curr->data);
    }
    return;
}

IntList & IntList::operator=(const IntList &rhs) {
        
        if (this != &rhs) {
            clear();
            for (IntNode *curr = rhs.head; curr != 0; curr = curr->next) {
             push_back(curr->data);
            }
        }
    return *this;
}


void IntList::push_back(int value) {
    IntNode *tmp = new IntNode(value);
    if (head != 0 && tail != 0) {
    tail->next = tmp;
    tail = tmp;
    }
    else {
        tail = tmp;
        head = tmp;
    }
    return;
}

void IntList::clear() {
    while (head != 0) {
        pop_front();
    }
    return;
}

void IntList::selection_sort() {
    IntNode* current = 0;
    IntNode* min = 0;
    IntNode* inner = 0;
    for (current = head; current != 0; current = current->next) {
        min = current;
        for (inner = current->next; inner != 0; inner = inner->next) {
            if (inner->data < min->data) {
                min = inner;
            }
        }
        swap(current->data, min->data);
    }
    return;
}

// void IntList::insert_ordered(int value) {
    
//     IntNode* current = head;
//     IntNode* position = head;
//     if (head == 0) {
//         push_front(value);
//     }
//     else{
//         while (current->data <= value) {
//             position = current;
//             current = current->next;
//         }
//         if (position == tail) {
//             push_back(value);
//         }
//         else if (position == head) {
//             push_front(value);
//         }
//         else {
//             IntNode* tmp = new IntNode(value);
//             tmp->next = position->next;
//             position->next = tmp;
//         }
//     }
//     return;
// }

void IntList::insert_ordered(int value) {
    if(head == 0) {
        push_front(value);
    }
    else {
        if(value <= head->data) {
            push_front(value);
        }
        else if(value >= tail->data)
        {
            push_back(value);
        }
        else
        {
            IntNode *prev = head;
            IntNode *curr = head->next;
            IntNode *temp = new IntNode(value);
            int i = 0;
            while(curr != 0 && i == 0)
            {
                if(value >= prev->data && value <= curr->data)
                {
                    temp->next = curr;
                    prev->next = temp;
                    i = 1;
                }
                prev = curr;
                curr = curr->next;
            }
           
        }
    }
}


// void IntList::remove_duplicates() {
//     IntNode* pre;
//     IntNode* dup;
//     for (IntNode* i = head; i != NULL; i = i -> next) {
//         pre = i;
//         for (IntNode* j = i -> next; j != 0; j = j -> next) {
//             if ((j -> data == i -> data) && j != 0){
//                 if (j == tail) {
//                     pre->next = j -> next;
//                     tail = pre;
//                     delete j;
//                     j = pre;
//                 }
//                 else {
//                 dup = j;
//                 pre->next = dup->next;
//                 delete dup;
//                 j = pre;
//                 }
//             }
//             else {
//                 pre = pre -> next;
//             }
//         }
//     }
  
// }


void IntList::remove_duplicates() {
    
    IntNode* prev;
        for (IntNode* i = head; i != 0; i = i -> next) {
            prev = i;
            for (IntNode* curr = i -> next; curr != 0; curr = curr -> next) {
                if ((i -> data == curr -> data) && curr != 0) {
                    if (curr == tail) {
                        prev -> next = curr -> next;
                        tail = prev;
                        delete curr;
                        curr = prev;
                    }
                    else {
                    prev -> next = curr -> next;
                    
                    delete curr;
                    curr = prev;
                    }
                }
                else {
                    prev = prev -> next;
                }    
            }
            
        }
}


ostream & operator<<(ostream &out, const IntList &rhs) {
    IntNode* current = 0;
    current = rhs.head;
    while (current != 0) {
        out << current->data;
        current = current->next;
        if (current != 0) {
            out << " ";
        }
    }
    return out;

}
    

