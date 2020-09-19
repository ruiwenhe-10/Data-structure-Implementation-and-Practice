#include <string>
#include <vector>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

#include "Message.h"
#include "User.h"
#include "BBoard.h"


// class BBoard {
//  private:
//     string title;
//     vector<User> userList;
//     User currentUser;
//     vector<Message> messageList;


BBoard::BBoard() {
    User a;
    title = "hello world";
    userList.resize(0);
    messageList.resize(0);
}

BBoard::BBoard(const string &title) {
    User a;
    this->title = title;
    userList.resize(0);
    messageList.resize(0);
}
  

bool BBoard::loadUsers(const string &file) {
    bool open = true;
    string userName;
    string passWord;
    ifstream inFS;
    inFS.open(file.c_str());
    if (!inFS.is_open()) {
        open = false; 
    }
    while (inFS >> userName >> passWord) {
        User a(userName, passWord);
        userList.push_back(a);
    }
    inFS.close();
    return open;
}

bool BBoard::login() {
    string userName = "cde";
    string userPass = "abc";
    char b;
    bool ifmatch = false;
    cout << "Welcome to " << title << endl;
    cout << "Enter your username ('Q' or 'q' to quit): ";
    cin >> userName;
    cout << endl;
    b = static_cast<char>(toupper(userName.at(0)));
    while (b != 'Q') {
    cout << "Enter your password: ";
    cin >> userPass;  
    cout << endl;
        for (unsigned i = 0; i < userList.size(); ++i) {
            if(userList.at(i).check(userName, userPass)) {
                ifmatch = true;
            }
        }
        if(ifmatch) {
            User a(userName, userPass);
            currentUser = a;
            cout << "Welcome back " << userName << '!' << endl << endl;
            b = 'Q';
        }
        else {
        cout << "Invalid Username or Password!" << endl << endl;
        cout << "Enter your username ('Q' or 'q' to quit): ";
        cin >> userName;
        cout << endl;
        b = static_cast<char>(toupper(userName.at(0)));
        }
    }
    if(!ifmatch) {
    cout << "Bye!" << endl;
    }
    else {
    }
    return ifmatch;
}

void BBoard::run() {
    string sub;
    string bod;
    char option = 'a';
    cout << "Menu" << endl << "- Display Messages ('D' or 'd')" << endl << "- Add New Message ('N' or 'n')" << endl << "- Quit ('Q' or 'q')" << endl << "Choose an action: "; 
    cin >> option;
    cout << endl;
    option = static_cast<char>(toupper(option)); 
    while (option != 'Q') {
        if (option == 'd' || option =='D'){
            if (messageList.size() != 0) {
                cout << "---------------------------------------------------------" << endl;
                for (unsigned i = 0; i < messageList.size(); ++i){
                    cout << "Message #" << i + 1 << ": ";
                    messageList.at(i).display();
                    cout << "---------------------------------------------------------" << endl;
                }
                cout << endl;
            }
            else {
                cout << "Nothing to Display." << endl << endl;
            }
        }
        else if (option == 'n' || option =='N') {
            cout << "Enter Subject: ";
            cin.ignore();
            getline(cin, sub);
            cout << endl;
            cout << "Enter Body: ";
            getline(cin, bod);
            cout << endl;
            cout << "Message Recorded!" << endl << endl;
            Message a(currentUser.getUsername(), sub, bod);
            messageList.push_back(a);
        }
    cout << "Menu" << endl << "- Display Messages ('D' or 'd')" << endl << "- Add New Message ('N' or 'n')" << endl << "- Quit ('Q' or 'q')" << endl << "Choose an action: ";
    cin >> option;
    cout << endl;
    option = static_cast<char>(toupper(option)); 
    }
    if (option == 'Q') {
        cout << "Bye!" << endl;
    }
    return;
}