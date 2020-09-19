#include <iostream>

using namespace std;


#include "Heap.h"
#include "PrintJob.h"


Heap::Heap() {
    numItems = 0;
}

PrintJob* Heap::highest() {
    PrintJob* temp = 0;
    if(numItems > 0) {
        temp = arr[0];
    }
    return temp;
}


void Heap::print() {  
    if(numItems > 0) {
    cout << "Priority: " << arr[0]->getPriority() << ", Job Number: " << arr[0]->getJobNumber() << ", Number of Pages: " << arr[0]->getPages() << endl;
    }
}

void Heap::enqueue(PrintJob* item) {
    if (numItems < 10) {
        if(numItems == 0) {
            arr[numItems] = item;
            ++numItems;
        }
        else {
            int x = numItems;
            while(x > 0 && arr[(x-1)/2]->getPriority() < item->getPriority()) {
                arr[x] = arr[(x-1)/2];
                x = (x-1)/2;
            }
            arr[x] = item;
            ++numItems;
        }
    }
}

void Heap::dequeue() {
    if(numItems == 1) {
        numItems = 0;   
    }
    else  {
    arr[0] = arr[numItems-1];
    --numItems;
    trickleDown(0);
    }
}


void Heap::trickleDown(int index) {
   int childIndex = 2 * index + 1;
   int priorityVal = arr[index]->getPriority();

   while (childIndex < numItems) {
      // Find the max among the node and all the node's children
      int maxValue = priorityVal;
      int maxIndex = -1;
      int i = 0;
      for (i = 0; i < 2 && i + childIndex < numItems; i++) {
         if (arr[i + childIndex]->getPriority() > maxValue) {
            maxValue = arr[i + childIndex]->getPriority();
            maxIndex = i + childIndex;
         }
      }
      if (maxValue == priorityVal) {
         return;
      }
      else {
         swap(arr[index],arr[maxIndex]);
         index = maxIndex;
         childIndex = 2 * index + 1;
      }
    }
    
}