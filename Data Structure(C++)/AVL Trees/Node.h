#ifndef NODE_H
#define NODE_H

using namespace std;

#include<string>

class Node {
    friend class AVLTree;
    
    private:
    Node* left;
    Node* right;
    Node* parent;
    string word;
    
    public:
    Node(string);
    Node &operator=(const Node& rhs);
    // string getname();
};








#endif