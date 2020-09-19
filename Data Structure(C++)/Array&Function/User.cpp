#include <string>
#include <vector>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;


// string username;
// string password;

#include "User.h"

User::User() {
}

User::User(const string& uname, const string& pass) {
    username = uname;
    password = pass;
}

string User::getUsername() const {
    return username;
}

bool User::check(const string &uname, const string &pass) const {
    bool match = false;
    if (uname == "" || pass == "") {
    }
    else {
        if (uname == username && pass == password) {
            match = true;
        }
    }
    return match;
}

bool User::setPassword(const string &oldpass, const string &newpass) {
    bool change = false;
    if ((oldpass != "") && (oldpass == password)) {
        password = newpass;
        change = true;
    }
    else {
    }
    return change;
}




// int main() {
//     unsigned i = 0;
//     bool ifmatch = false;
//     vector<User> userList;
//     string file = "file.txt";
//     string userName;
//     string passWord;
//     ifstream inFS;
//     inFS.open(file.c_str());
//     if (!inFS.is_open()) {
//         cout << "Error opening" << file << endl;
//         exit(1);
//     }
    
//     while (inFS >> userName >> passWord) {
        
//         cout << userName << " " << passWord << endl;
//         User a(userName, passWord);
//         userList.push_back(a);
//      }
//      cout << endl;
//      cout << "Enter username" << endl;
//      cin >> userName;
//      cout << "Enter password" << endl;
//      cin >> passWord;
//      for (i = 0; i < userList.size(); ++i) {
//          if (userList.at(i).check(userName, passWord)) {
//              cout << "matched!" << endl;
//          }
//          else {
//              cout << "failed!" << endl;
//          } 
//      }
//      for (i = 0; i < userList.size(); ++i) {
//         cout << userList.at(i).getUsername() << " ";
//      }
//      cout << endl;
    
    
    
    
    
    
    
    
//     inFS.close();
//     return 0;
// }