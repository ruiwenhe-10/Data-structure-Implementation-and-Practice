#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <string>

using namespace std;

#include "WordLadder.h"


int main(){
    
    // queue< stack<int> > myquene;
    // stack<int> mystack;
    // mystack.push(1);
    // mystack.push(2);
    // mystack.push(3);
    // mystack.push(6);
    // mystack.push(4);
    // mystack.push(5);
    // myquene.push(mystack);
    // myquene.front().pop();
    // cout << myquene.front().top() << endl;
    
   string dictFile, wordBegin, wordEnd, outFile;
   cout << "Enter the name of the dictionary file: ";
   cin >> dictFile;
   cout << endl;
  cout << "Enter the name of the output file: ";
  cin >> outFile;
  cout << endl;
  cout << "Enter the first word: ";
  cin >> wordBegin;
  cout << endl;
  while (wordBegin.size() != 5) {
      cout << "Word must have exactly 5 characters." << endl
         << "Please reenter the first word: ";
      cin >> wordBegin;
      cout << endl;
  }
  cout << "Enter the last word: ";
  cin >> wordEnd;
  cout << endl;
  while (wordEnd.size() != 5) {
      cout << "Word must have exactly 5 characters." << endl
         << "Please reenter the last word: ";
      cin >> wordEnd;
      cout << endl;
  }
   
	WordLadder wl(dictFile);
	
	wl.outputLadder(wordBegin, wordEnd, outFile);
    
    
    return 0;
}
