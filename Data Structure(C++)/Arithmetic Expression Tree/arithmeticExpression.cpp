#include <iostream>
#include <cstdlib>
#include <stack>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;


#include "arithmeticExpression.h"


arithmeticExpression::arithmeticExpression(const string &mystring) {
    infixExpression = mystring;
    root = 0;
}

void arithmeticExpression::buildTree() {
    string user = infix_to_postfix();
    stack<TreeNode*> nodes;
    char k = 'a';
    unsigned int i = 0;
    
    for (i = 0; i < user.size(); ++i) {
        TreeNode* temp = new TreeNode(user.at(i), k++);
        if (user.at(i) >= 97 && user.at(i) <= 122) {
            nodes.push(temp);
        }
        else {
            temp -> right = nodes.top();
            nodes.pop();
            temp -> left = nodes.top();
            nodes.pop();
            nodes.push(temp);
        }
    }
    root = nodes.top();
    return;
}


void arithmeticExpression::infix(TreeNode* subroot) {
    if ( subroot ) {
        if (subroot -> left != 0) {
            cout << "(";
        }
        infix(subroot->left);
        cout << subroot -> data;
        infix (subroot -> right);
        if (subroot -> right != 0) {
            cout << ")";
        }
    }
}

void arithmeticExpression::prefix(TreeNode* subroot) {
    if ( subroot ) {
        cout << subroot -> data;
        prefix(subroot->left);
        prefix(subroot -> right);
    }
}
void arithmeticExpression::postfix(TreeNode* subroot) {
    if ( subroot ) {
        postfix(subroot->left);
        postfix(subroot -> right);
        cout << subroot -> data;

    }
}
void arithmeticExpression::infix() {
    infix(root);
}

void arithmeticExpression::prefix() {
    prefix(root);
}

void arithmeticExpression::postfix() {
    postfix(root);
}




int arithmeticExpression::priority(char op){
    int priority = 0;
    if(op == '('){
        priority =  3;
    }
    else if(op == '*' || op == '/'){
        priority = 2;
    }
    else if(op == '+' || op == '-'){
        priority = 1;
    }
    return priority;
}

string arithmeticExpression::infix_to_postfix(){
    stack<char> s;
    ostringstream oss;
    char c;
    for(unsigned i = 0; i< infixExpression.size();++i){
        c = infixExpression.at(i);
        if(c == ' '){
            continue;
        }
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
            if( c == '('){
                s.push(c);
            }
            else if(c == ')'){
                while(s.top() != '('){
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority(c) <= priority(s.top())){
                    if(s.top() == '('){
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else{ //c is an operand
            oss << c;
        }
    }
    while(!s.empty()){
        oss << s.top();
        s.pop();
    }
    return oss.str();
}


void arithmeticExpression::visualizeTree(ofstream &outFS, TreeNode* subroot) {
    if (subroot == 0) {
        return;
    }
    else {
        
        if (subroot -> left) {
            outFS  << "key" << subroot -> key; 
            outFS   << "h";
           
           
            if (subroot -> data == '+') {
                outFS << "plus";
            }
            else if (subroot -> data == '-') {
                outFS << "minus";
            }
            else if(subroot -> data == '*'){
                outFS << "multi";
            }
            else if(subroot -> data == '/'){
                outFS << "div";
            }
            else {
                outFS << subroot -> data;
            }
            
            
            outFS << " -> "  << "key" << subroot -> left -> key << "h";
            
            
            
            if (subroot -> left -> data == '+') {
                outFS << "plus";
            }
            else if (subroot -> left -> data == '-') {
                outFS << "minus";
            }
            else if(subroot -> left -> data == '*'){
                outFS << "multi";
            }
            else if(subroot -> left -> data == '/'){
                outFS << "div";
            }
            else {
                outFS << subroot -> left -> data;
            }
            outFS  << ";" << endl;
        }
        if (subroot -> right) {
           
           
           
           outFS  << "key" << subroot -> key; 
            outFS   << "h";
            if (subroot -> data == '+') {
                outFS << "plus";
            }
            else if (subroot -> data == '-') {
                outFS << "minus";
            }
            else if(subroot -> data == '*'){
                outFS << "multi";
            }
            else if(subroot -> data == '/'){
                outFS << "div";
            }
            else {
                outFS <<subroot -> data;
            }
           
           
            outFS << " -> "  << "key" << subroot -> right -> key << "h";
            
            
            if (subroot -> right -> data == '+') {
                outFS << "plus";
            }
            else if (subroot -> right -> data == '-') {
                outFS << "minus";
            }
            else if(subroot -> right -> data == '*'){
                outFS << "multi";
            }
            else if(subroot -> right -> data == '/'){
                outFS << "div";
            }
            else {
                outFS <<subroot -> right -> data;
            }
            outFS  << ";" << endl;
        }
        visualizeTree(outFS, subroot -> left);
        visualizeTree(outFS, subroot -> right);
    }
    
}

void arithmeticExpression::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error opening "<< outputFilename<<endl;
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



