#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstdlib>


using namespace std;

#include "AVLTree.h"
#include "Node.h"

AVLTree::AVLTree() {
    root = 0;
}


int AVLTree::balanceFactor(Node* node) {
    int leftHeight = -1;
    if (node->left != 0) {
      leftHeight = height(node->left->word);
    }
   int rightHeight = -1;
   if (node->right != 0) {
      rightHeight = height(node->right->word);
   }
   return leftHeight - rightHeight;
}

void AVLTree::printBalanceFactors() {
   inOrder(root); 
   cout << endl;
}

void AVLTree::insert(const string &key) {
    if(root == 0) {
        Node* temp = new Node(key);
        root = temp;
    }
    else {
        insert(key, root);
    }
}

void AVLTree::insert(const string &key, Node* subroot) {
    Node* temp = new Node(key);
    Node* cur = subroot;
   while (cur != 0) {
    if(search(key, root)) {
        return;
    }
    if (key < cur->word) {
        if (cur->left == 0) {
          cur->left = temp;
          temp->parent = cur;
          cur = 0;
        }
        else {
          cur = cur->left;
        }
     }
     else {
        if (cur->right == 0) {
          cur->right = temp;
          temp->parent = cur;
          cur = 0;
        }
        else{
          cur = cur->right;
        }
     }
   
   }
   temp->left = 0;
   temp->right = 0;
   
   Node* node = temp->parent;
   while (node != 0) {
      AVLTreeRebalance(node);
      node = node->parent;
   }
}

void AVLTree::AVLTreeRebalance(Node* node) {
   if (balanceFactor(node) == -2) {
      if (balanceFactor(node->right) == 1) {    // Double rotation case.
         AVLTreeRotateRight(node->right);
      }
    AVLTreeRotateLeft(node);
   }
   else if (balanceFactor(node) == 2) {
      if (balanceFactor(node->left) == -1) {    // Double rotation case.
         AVLTreeRotateLeft(node->left);
      }
    AVLTreeRotateRight(node);
   }        
   return;
}

void AVLTree::AVLTreeRotateRight(Node* node) {
    Node* leftRightChild = node->left->right;
   if (node->parent != 0) {
        AVLTreeReplaceChild(node->parent, node, node->left);
   }
   else { // node is root
        root = node->left;
        root->parent = 0;
   }
   AVLTreeSetChild(node->left, "right", node);
   AVLTreeSetChild(node, "left", leftRightChild);
}

void AVLTree::AVLTreeRotateLeft(Node* node) {
    Node* rightLeftChild = node->right->left;
    if (node->parent != 0) {
        AVLTreeReplaceChild(node->parent, node, node->right);
    }
    else {
        root = node->right;
        root->parent = 0;
    }
    AVLTreeSetChild(node->right, "left", node);
    AVLTreeSetChild(node, "right", rightLeftChild);
}
    
    
void AVLTree::AVLTreeReplaceChild(Node* parent, Node* currentChild, Node* newChild) {
    if (parent->left == currentChild) {
      AVLTreeSetChild(parent, "left", newChild);
    }
    else if (parent->right == currentChild) {
      AVLTreeSetChild(parent, "right", newChild);
    }
}

void AVLTree::AVLTreeSetChild(Node* parent, string whichChild, Node* child) {
    if (whichChild == "left") {
      parent->left = child;
    }
   else {
      parent->right = child;
   }
   if (child != 0) {
      child->parent = parent;
   }
}


void AVLTree::inOrder(Node* subroot) {
    if(subroot) {
        inOrder(subroot->left);
        cout << subroot->word << "(" << balanceFactor(subroot) << "), " ;   //Fix count problem
        inOrder(subroot->right);
    }
}

int AVLTree::height(const string &data) const {
    Node *current = search(data, root);
    Node *currentLeft = current;
    Node *currentRight = current;
    int lcount = 0;
    int rcount = 0;
    
    if(current->left != 0) {
        currentLeft = currentLeft->left;
        lcount++;
        lcount = lcount + height(currentLeft->word);
    }
    if(current->right != 0) {
        currentRight = currentRight->right;
        rcount++;
        rcount = rcount + height(currentRight->word);
    }
    if(lcount >= rcount) {
        return lcount;
    }
    else {
        return rcount;
    }
}





void AVLTree::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error"<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}

void AVLTree::visualizeTree(ofstream & outFS, Node *n){
    if(n){
        if(n->left){
            visualizeTree(outFS,n->left);
            outFS <<"\"" <<n->word << balanceFactor(n)  <<"\"" <<" -> " <<"\"" << n->left->word<<balanceFactor(n->left) <<"\"" <<";"<<endl;    
        }

        if(n->right){
            visualizeTree(outFS,n->right);
            outFS <<"\"" <<n->word << balanceFactor(n) <<"\"" <<" -> " <<"\"" <<n->right->word<<balanceFactor(n->right)<<"\"" <<";"<<endl;    
        }
    }
}

bool AVLTree::search(const string &key) const {
    if(search(key, root)) {
        return true;
    }
    else {
        return false;
    }
}

Node* AVLTree::search(const string &key, Node* subroot) const {
    if (subroot) {
        if (subroot->word == key) {
            return subroot;
        }
        else {
            if (key < subroot->word) {
            return search(key, subroot->left);
            }
            else {
            return search(key, subroot->right);
            }
        }
    }
    else {
        return 0;
    }
    
}