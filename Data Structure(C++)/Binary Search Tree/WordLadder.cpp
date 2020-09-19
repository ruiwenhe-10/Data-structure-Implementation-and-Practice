#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <fstream>
#include <string>


#include "WordLadder.h"

using namespace std;

WordLadder::WordLadder(const string &inputFile) {
    string input;
    ifstream inFS;
    inFS.open(inputFile.c_str());
    if(!inFS.is_open()) {
        cout << "Error opening" << ' ' << inputFile << endl;
        return;
    }
    while (inFS >> input) {
        if(input.size() != 5) {
            cout << "Wrong string size" << endl;
            return;
        }
        else {
            dict.push_back(input);
        }
    }
    inFS.close();
    return;
}



void WordLadder::outputLadder(const string &start, const string &end, const string &outputFile) {
    queue< stack<string> > myquene;
    
    stack<string> mystack;
    
    stack<string> newstack;
    int counter = 0;
    bool done = false;
    
    ofstream ouFS;
    ouFS.open(outputFile.c_str());
    if(!ouFS.is_open()) {
        cout << "Error opening" << ' ' << outputFile << endl;
        return;
    }
    
    
    if (start != end)  {
    
    
    mystack.push(start);
    
    myquene.push(mystack);

    while(myquene.empty() != true && done != true) {
        string topword = myquene.front().top();
        for (list<string>::iterator it = dict.begin(); it != dict.end();) {
            if (done != true) {
            string word = *it;
            counter = 0;
            for (int i  = 0; i < 5; ++i) {
                if (topword.at(i) == word.at(i)) {
                    ++counter;
                }
            } // inner for
            if (counter == 4) {             //word off by one letter found!
            
                newstack = myquene.front();
               
                newstack.push(word);
              
                if (word == end) {
                done = true;
                }
                else {
                myquene.push(newstack);
             
                it = dict.erase(it);
              
                }
            }
            else {
                ++it;
            }
        }
        else {
            it = dict.end();
        }
        } // for
        myquene.pop();
    }  // while
    
     list<string> outlist;
    while (!newstack.empty()) {
        outlist.push_front(newstack.top());
        newstack.pop();
    }
    // int numbercount = 0;
    // int count = 1;
    // int enter = 0;
    // for (list<string>::iterator it = outlist.begin(); it != outlist.end();  ++it) {
    //     ++enter;
    //     if (enter > 2) {
    //     string target = *it;
    //     numbercount = 0;
    //     ++count;
    //     for (int i = 0; i < 5; ++i) {
    //         if(outlist.front().at(i) == target.at(i)) {
    //             ++numbercount;
    //         }
    //     }
    //     if (numbercount == 4) {
    //         string frontword = outlist.front();
    //         for (int b = 0; b < count; ++b) {
    //             outlist.pop_front();
    //         }
    //         outlist.push_front(frontword);
    //     }
    // }// if
    // }
    
    
    if(done == true) {
        for (list<string>::iterator it = outlist.begin(); it != outlist.end();  ++it) {
            ouFS << *it << endl;
        }
    }
    else {
        ouFS << "No Word Ladder Found." << endl;   
    }
    }
    else {
    ouFS << start << endl;
    }
    
    ouFS.close();
    return;
    }

