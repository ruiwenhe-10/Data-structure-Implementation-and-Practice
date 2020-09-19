#include "Node.h"

using namespace std;

Node::Node(string data)
{
    word = data;
    left = 0;
    right = 0;
    parent = 0;
}


 Node& Node::operator=(const Node& rhs) {
     if (this != &rhs) {
     this->word = rhs.word;
     }
     
     return *this;
 }
 