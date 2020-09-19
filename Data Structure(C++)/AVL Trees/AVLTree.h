#ifndef AVLTREE_H
#define AVLTREE_H


using namespace std;


#include "AVLTree.h"
#include "Node.h"


class AVLTree {
    
    private:
    Node* root;
    
    private:
    void inOrder(Node *);
    void visualizeTree(ofstream &, Node *);
    Node* search(const string &, Node *) const;
    void insert(const string &, Node *);
    void AVLTreeRotateLeft(Node*);
    void AVLTreeRotateRight(Node*);
    void AVLTreeSetChild(Node* parent, string whichChild, Node* child);
    void AVLTreeReplaceChild(Node* parent, Node* currentChild, Node* newChild);
    
    public:
    AVLTree();
    void insert(const string &); //Insert an item to the binary search tree and 
                                //perform rotation if necessary.
    int balanceFactor(Node*);    //Return the balance factor of a given node.
    
    void printBalanceFactors();  //Traverse and print the tree in inorder notation. 
                                //Print the string followed by its 
                                //balance factor in parentheses followed by a , and one space.
    void visualizeTree(const string &); // Generate dotty file and visualize the 
                                        //tree using dotty program. Call this function before and after rotation.
    int height(const string &) const;
    bool search(const string &) const;
    void AVLTreeRebalance(Node*);
};
























#endif