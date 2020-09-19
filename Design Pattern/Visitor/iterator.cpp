#include "iterator.h"
#include "composite.h"
#include <stack>

using namespace std;

void PreorderIterator::first() {
    // Empty the stack (just in case we had something leftover from another run)
    // Create an iterator for the Base* that we built the iterator for
    // Initialize that iterator and push it onto the stack
    Iterator* it = self_ptr->create_iterator();
    if (it != NULL) {
        it->first();

        while (!iterators.empty()) {
            iterators.pop();
        }
        iterators.push(it);
   }
}

void PreorderIterator::next() {
    // Create an iterator for the item on the top of the stack
    // Initialize the iterator and push it onto the stack
    // As long as the top iterator on the stack is_done(), pop it off the stack and then advance whatever iterator is now on top of the stack
    Iterator* it = iterators.top()->current()->create_iterator();
    it->first();

    iterators.push(it);

    while (!iterators.empty() && iterators.top()->is_done()) {
        iterators.pop();
        if (iterators.empty()) {
            break;
        }
        iterators.top()->next();
    }
}

bool PreorderIterator::is_done() {
    // Return true if there are no more elements on the stack to iterate
    return iterators.empty();
}

Base* PreorderIterator::current() {
    // Return the current for the top iterator in the stack
    return iterators.top()->current();
}

void OperatorIterator::first() {
    current_ptr = self_ptr->get_left();
}

void OperatorIterator::next() {
    // current_ptr = self_ptr->get_right();
    // current_ptr = NULL;
    if (current_ptr == self_ptr->get_left()) {
        current_ptr = self_ptr->get_right();
    }
    else {
        current_ptr = NULL;
    }
}

bool OperatorIterator::is_done() {
    if (current_ptr == NULL){
    	return true;
    }
    return false;
}

Base* OperatorIterator::current() {
    return current_ptr;
}

void UnaryIterator::first() {
    current_ptr = self_ptr->get_left();
}

void UnaryIterator::next() {
    current_ptr = NULL;
}

bool UnaryIterator::is_done() {
    if (current_ptr == NULL){
    	return true;
    }
    return false;
}

Base* UnaryIterator::current() {
    return current_ptr;
}

void NullIterator::first() {
    return;
}

void NullIterator::next() {
    return;
}

bool NullIterator::is_done() {
    return true;
}

Base* NullIterator::current() {
    return NULL;
}