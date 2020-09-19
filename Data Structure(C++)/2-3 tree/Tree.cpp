#include <iostream>
#include <string>
#include <fstream>
#include<cstdlib>
#include "Tree.h"

Tree::Tree( )
{
    root = 0;
}

Tree::~Tree( )
{
    //calls deconstructor helper function
    clean(root);
}

void Tree::insert(const string &data)
{
    if(root == 0)
    {
        root = new Node(data);
        
        return;
    }
    Node *cur = root;
    while(cur)
    {
        //if cur has no children
        if(cur->left == 0 && cur->middle == 0 && cur->right == 0)
        {
            if(cur->large.empty() )
            {
                if(data > cur->small)
                {
                    cur->large = data;
                }
                else
                {   
                    cur->large = cur->small;
                    cur->small = data;
                }
            }
            else
            {
                split(cur, data, 0, 0);
            }
            
            return;
        }
        //else cur has children
        else
        {
            if(data < cur->small)
            {
                cur = cur->left;
            }
            else if( !(cur->large.empty() ) )
            {
                if(data < cur->large)
                {
                    cur = cur->middle;
                }
                else if(data > cur->large)
                {
                    cur = cur->right;
                }
            }
            else if(data > cur->large)
            {
                cur = cur->right;
            }
        }
    }
}


void Tree::split(Node* cur, const string &word, Node* leftchild, Node* rightchild) {

    Node* leftnode;
    Node* rightnode;
    string middleval;
 
    if(cur->small < word && word < cur->large) {
        middleval = word;
        leftnode = new Node(cur->small);
        rightnode = new Node(cur->large);
    }
    if(word < cur->small && cur->small < cur-> large) {
        middleval = cur->small;
        leftnode = new Node(word);
        rightnode = new Node(cur->large);
    }
    if(cur->small < cur-> large && cur->large < word) {
        middleval = cur->large;
        leftnode = new Node(cur->small);
        rightnode = new Node(word);
    }
    if(cur->parent == 0) {
        root = new Node(middleval);
        root->left = leftnode;
        leftnode->parent = root;
        root->right = rightnode;
        rightnode->parent = root;
        
    }
    else if(cur->parent->large == "") {
        if(cur->parent->small < middleval) {
            cur->parent->large = middleval;
        }
        else {
            cur->parent->large = cur->parent->small;
            cur->parent->small = middleval;
        }
        if(leftnode->small < cur->parent->small) {      //split from left
            cur->parent->left = leftnode;
            cur->parent->middle = rightnode;
        }
        else {                                          //split from right
            cur->parent->right = rightnode;
            cur->parent->middle = leftnode;
        }
        leftnode->parent = cur->parent;
        rightnode->parent = cur->parent;
    }
    else {                          //node is full
            split(cur->parent, middleval, leftnode, rightnode);
    }
    if(cur->left == 0 && cur->right == 0 && cur->middle == 0) {
            return;
    }
    else {
            if(leftchild->small < leftnode->small) {
                leftnode->left = leftchild;
                leftchild->parent = leftnode;
                leftnode->right = rightchild;
                rightchild->parent = leftnode;
                rightnode->left = cur->middle;
                rightnode->left->parent = rightnode;
                rightnode->right = cur->right;
                rightnode->right->parent = rightnode;
            }
            else if(rightchild->small > rightnode->small) {
                leftnode->left = cur->left;
                leftnode->left->parent = leftnode;
                leftnode->right = cur->middle;
                leftnode->right->parent = leftnode;
                rightnode->left = leftchild;
                rightnode->left->parent = rightnode;
                rightnode->right = rightchild;
                rightnode->right->parent = rightnode;
            }
            else {
                leftnode->left = cur->left;
                leftnode->left->parent = leftnode;
                leftnode->right = leftchild;
                leftnode->right->parent = leftnode;
                rightnode->left = rightchild;
                rightnode->left->parent = rightnode;
                rightnode->right = cur->right;
                rightnode->right->parent = rightnode;
            }
        }
    
    delete cur;
}

void Tree::preOrder( ) const {
    preOrder(root);
    cout << endl;
}

void Tree::inOrder( ) const {
    inOrder(root);
    cout << endl;
}

void Tree::postOrder( ) const {
    postOrder(root);
    cout << endl;
}

void Tree::preOrder(Node *cur) const {
    if(cur != 0) {
        if(cur->large.empty()) {
            cout << cur->small << ", ";
            preOrder(cur->left);
            preOrder(cur->right);
        }
        else {
            cout << cur->small << ", ";
            preOrder(cur->left);
            cout << cur->large << ", ";
            preOrder(cur->middle);
            preOrder(cur->right);
        }
    }
}

void Tree::inOrder(Node *cur) const {
    if(cur != 0) {
        if(cur->large.empty() ) {
            inOrder(cur->left);
            cout << cur->small << ", ";
            inOrder(cur->right);
        }
        else {
            inOrder(cur->left);
            cout << cur->small << ", ";
            inOrder(cur->middle);
            cout << cur->large << ", ";
            inOrder(cur->right);
        }
    }
}

void Tree::postOrder(Node *cur) const {
    if(cur != 0)  {
        if(cur->large.empty())   {
            postOrder(cur->left);
            postOrder(cur->right);
            cout << cur->small << ", ";
        }
        else {
            postOrder(cur->left);
            postOrder(cur->middle);
            cout << cur->small << ", ";
            postOrder(cur->right);
            cout << cur->large << ", ";
        }
    }
}

bool Tree::search(const string & word) const {
    if(search(root, word)) {
        return true;
    }
    else {
        return false;
    }
}


Node* Tree::search(Node* subroot, const string & word) const {
    if (subroot != 0) {
    if (subroot->large != "") {
        if (subroot->small == word || subroot->large == word) {
            return subroot;
        }
        else {
            if(word < subroot->small) {
                return search(subroot->left, word);
            }
            else if(word < subroot->large) {
                return search(subroot->middle, word);
            }
            else {
                return search(subroot->right, word);
            }
        }
    }
    else if (subroot->large == "") {
        if(subroot->small == word) {
            return subroot;
        }
        else {
            if(word < subroot->small) {
                return search(subroot->left, word);
            }
            else {
                return search(subroot->right, word);
            }
        }
        
    }
    }
    return 0;
}

void Tree::remove(const string &data)   {
    if( !(search(data)) )  {
        return;
    }
    Node *cur = search(root, data);
    Node *swap = cur;
    
    //find successor or itself if none
    //initial movement from node
    if(cur->middle != 0 && cur->small == data) {
        swap = cur->middle;
    }
    else if(cur->right != 0) {   
        swap = cur->right;
    }
    
    //find inorder successor
    
    while(swap->left != 0 || swap->middle != 0 || swap->right != 0) {
        swap = swap->left;
        
    }
    
    if(cur->small == data) {
        cur->small = swap->small;
        //if node to delete is a 2-node, restore
        if(swap->large.empty() ) {
            swap->small.clear();
            restore(swap, 0);
        }
        else {
            swap->small = swap->large;
            swap->large.clear();
        }
    }
    else  {
        if(cur != swap) {
            cur->large = swap->small;
            //if node to delete is a 2-node, restore
            if(swap->large.empty() ) {
                swap->small.clear();
                restore(swap, 0);
            }
            else {
                swap->small = swap->large;
                swap->large.clear();
            }
        }
        else {
            swap->large.clear();
        }
    }
}

void Tree::restore(Node *cur, Node *child)  {
    if(cur == root) {
        if(cur->left != 0 || cur->right != 0)   {
            root = child;
        }
        else    {
            root = 0;
        }
        delete cur;
        
        return;
    }
    //if node to delete has no 3-node siblings (merge)
    if(cur->parent->left->large.size() == 0 && cur->parent->middle->large.size() == 0 && cur->parent->right->large.size() == 0) {
        
        //if node is parent's left child
        if(cur->parent->left == cur)  {  
            cur = cur->parent;
            cur->left->small = cur->small;
            if(cur->large.empty()) {
                cur->left->large = cur->right->small;
                cur->small.clear();
                if(child != 0) {
                    cur->left->left = child;
                    child->parent = cur->left;
                    cur->left->middle = cur->right->left;
                    cur->left->middle->parent = cur->left;
                    cur->left->right = cur->right->right;
                    cur->left->right->parent = cur->left;
                }
                delete cur->right;
                cur->right = 0;
                restore(cur, cur->left);
            }
            else {
                cur->left->large = cur->middle->small;
                cur->small = cur->large;
                cur->large.clear();
                if(child != 0) {
                    cur->left->left = child;
                    child->parent = cur->left;
                    cur->left->middle = cur->middle->left;
                    cur->left->middle->parent = cur->left;
                    cur->left->right = cur->middle->right;
                    cur->left->right->parent = cur->left;
                }
                delete cur->middle;
                cur->middle = 0;
            }
        }
        //else if node is parent's right child
        else if(cur->parent->right == cur) {
            cur = cur->parent;
            if(cur->large.empty() ) {
                cur->left->large = cur->small;
                cur->small.clear();
                delete cur->right;
                cur->right = 0;
                if(child != 0) {
                    cur->left->middle = cur->left->right;
                    cur->left->middle->parent = cur->left;
                    cur->left->right = child;
                    child->parent = cur->left;
                }
                restore(cur, cur->left);
            }
            else {
                cur->right->large = cur->large;
                cur->large.clear();
                cur->right->small = cur->middle->small;
                if(child != 0)
                {
                    cur->right->right = child;
                    child->parent = cur->right;
                    cur->right->middle = cur->middle->right;
                    cur->right->middle->parent = cur->right;
                    cur->right->left = cur->middle->left;
                    cur->right->left->parent = cur->right;
                }
                delete cur->middle;
                cur->middle = 0;
            }
        }
        //else node is parent's middle child
        else {
            cur = cur->parent;
            cur->left->large = cur->small;
            cur->small = cur->large;
            cur->large.clear();
            if(child != 0)  {
                cur->left->middle = cur->left->right;
                cur->left->middle->parent = cur->left;
                cur->left->right = child;
                child->parent = cur->left;
            }
            delete cur->middle;
            cur->middle = 0;
        }
    }
    //else node to delete has 3-node siblings (redistribute)
    // cout << "test3" << endl;
    else  {
        // cout << "test3" << endl;
        //if node is parent's left child
        if(cur->parent->left == cur) {
            cur = cur->parent;
            cur->left->small = cur->small;
            if(cur->large.empty() )  {
                cur->small = cur->right->small;
                cur->right->small = cur->right->large;
                cur->right->large.clear();
                if(child != 0)
                {
                    cur->left->left = child;
                    child->parent = cur->left;
                    cur->left->right = cur->right->left;
                    cur->left->right->parent = cur->left;
                    cur->right->left = cur->right->middle;
                    cur->right->left->parent = cur->right;
                    cur->right->middle = 0;
                }
            }
            else    {
                cur->small = cur->middle->small;
                if(cur->middle->large.empty() ) {
                    cur->middle->small = cur->large;
                    cur->large = cur->right->small;
                    cur->right->small = cur->right->large;
                    cur->right->large.clear();
                    if(child != 0)  {
                        cur->left->left = child;
                        child->parent = cur->left;
                        cur->left->right = cur->middle->left;
                        cur->left->right->parent = cur->left;
                        cur->middle->left = cur->middle->right;
                        cur->middle->left->parent = cur->middle;
                        cur->middle->right = cur->right->left;
                        cur->middle->right->parent = cur->middle;
                        cur->right->left = cur->right->middle;
                        cur->right->left->parent = cur->right;
                        cur->right->middle = 0;
                    }
                }
                else    {
                    cur->middle->small = cur->middle->large;
                    cur->middle->large.clear();
                    if(child != 0)
                    {
                        cur->left->left = child;
                        child->parent = cur->left;
                        cur->left->right = cur->middle->left;
                        cur->left->right->parent = cur->left;
                        cur->middle->left = cur->middle->right;
                        cur->middle->left->parent = cur->middle;
                        cur->middle->right = cur->right->left;
                        cur->middle->right->parent = cur->middle;
                        cur->right->left = cur->right->middle;
                        cur->right->left->parent = cur->right;
                        cur->right->middle = 0;
                    }
                }
            }
        }
        //else if node is parent's right child
        else if(cur->parent->right == cur)  {
            cur = cur->parent;
            if(cur->large.empty() ) {
                cur->right->small = cur->small;
                cur->small = cur->left->large;
                cur->left->large.clear();
                if(child != 0)  {
                    cur->right->right = child;
                    child->parent = cur->right;
                    cur->right->left = cur->left->right;
                    cur->right->left->parent = cur->right;
                    cur->left->right = cur->left->middle;
                    cur->left->right->parent = cur->left;
                    cur->left->middle = 0;
                }
            }
            else     {
                cur->right->small = cur->large;
                if(cur->middle->large.empty() )  {
                    cur->large = cur->middle->small;
                    cur->middle->small = cur->small;
                    cur->small = cur->left->large;
                    cur->left->large.clear();
                    if(child != 0) {
                        cur->right->right = child;
                        child->parent = cur->right;
                        cur->right->left = cur->middle->right;
                        cur->right->left->parent = cur->right;
                        cur->middle->right = cur->middle->left;
                        cur->middle->right->parent = cur->middle;
                        cur->middle->left = cur->left->right;
                        cur->middle->left->parent = cur->middle;
                        cur->left->right = cur->left->middle;
                        cur->left->right->parent = cur->left;
                        cur->left->middle = 0;
                    }
                }
                else {
                    cur->large = cur->middle->large;
                    cur->middle->large.clear();
                    if(child != 0)  {
                        cur->right->right = child;
                        child->parent = cur->right;
                        cur->right->left = cur->middle->right;
                        cur->right->left->parent = cur->right;
                        cur->middle->right = cur->middle->middle;
                        cur->middle->right->parent = cur->middle;
                        cur->middle->middle = 0;
                    }
                }
            }
        }
        //else node is parent's middle child
        else    {
            cur = cur->parent;
            if(cur->right->large.empty() )  {
                cur->middle->small = cur->small;
                cur->small = cur->left->large;
                cur->left->large.clear();
                if(child != 0)   {
                    cur->middle->right = child;
                    child->parent = cur->middle;
                    cur->middle->left = cur->left->right;
                    cur->middle->left->parent = cur->middle;
                    cur->left->right = cur->left->middle;
                    cur->left->right->parent = cur->left;
                    cur->left->middle = 0;
                }
            }
            else    {
                cur->middle->small = cur->large;
                cur->large = cur->right->small;
                cur->right->small = cur->right->large;
                cur->right->large.clear();
                if(child != 0)  {
                    cur->middle->left = child;
                    child->parent = cur->middle;
                    cur->middle->right = cur->right->left;
                    cur->middle->right->parent = cur->middle;
                    cur->right->left = cur->right->middle;
                    cur->right->left->parent = cur->right;
                    cur->right->middle = 0;
                }
            }
        }
    }
}

void Tree::clean(Node *cur) {
    if(cur != 0) {
        if(cur->large.empty() ){
            clean(cur->left);
            clean(cur->right);
            delete cur;
        }
        else    {
            clean(cur->left);
            clean(cur->middle);
            clean(cur->right);
            delete cur;
        }
    }
}
