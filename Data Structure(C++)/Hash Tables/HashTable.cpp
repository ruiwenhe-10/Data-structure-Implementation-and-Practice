#include "HashTable.h"
#include "WordEntry.h"
#include <iterator>

using namespace std;

/* HashTable constructor
*  input s is the size of the array
*  set s to be size
*  initialize array of lists of WordEntry
*/
HashTable::HashTable (int s) {
    hashTable = new list<WordEntry>[s];
	size = s;
}


/* computeHash
*  return an integer based on the input string
*  used for index into the array in hash table
*  be sure to use the size of the array to 
*  ensure array index doesn't go out of bounds
*/
int HashTable::computeHash(const string &s) {
    
   return s.size() % size;
}


/* put
*  input: string word and int score to be inserted
*  First, look to see if word already exists in hash table
*   if so, addNewAppearence with the score to the WordEntry
*   if not, create a new Entry and push it on the list at the
*   appropriate array index
*/
void HashTable::put(const string &s, int score) {
    list<WordEntry>::iterator curr;

    if (contains(s)) {
        
        for(curr = hashTable[computeHash(s)].begin(); curr != hashTable[computeHash(s)].end(); ++curr) {
        
            if (curr->getWord() == s) {
                
                curr->addNewAppearance(score); 
                return;
                
            }
        
        }
    }
    
    else {
        hashTable[computeHash(s)].push_back(WordEntry(s,score));
    }
	 
}

/* getAverage
*  input: string word 
*  output: the result of a call to getAverage()
*          from the WordEntry
*  Must first find the WordEntry in the hash table
*  then return the average
*  If not found, return the value 2.0 (neutral result)
*/

double HashTable::getAverage(const string &s) {
    list<WordEntry>::iterator curr;
     
     for(curr = hashTable[computeHash(s)].begin(); curr != hashTable[computeHash(s)].end(); ++curr) {
        
        if (curr->getWord() == s) {
            
           
            return curr->getAverage();
        }
        
    }
    return 0.0;
}

/* contains
* input: string word
* output: true if word is in the hash table
*         false if word is not in the hash table
*/
bool HashTable::contains(const string &s) {
     list<WordEntry>::iterator curr;
     
    //  if(hashTable[computeHash(s)].empty()) {
    //      return false;
    //  }
     
     for(curr = hashTable[computeHash(s)].begin(); curr != hashTable[computeHash(s)].end(); ++curr) {
        // cout << "1" << endl;
        if (curr->getWord() == s) {
            return true;
        }
    }
    
    
    return false;
}