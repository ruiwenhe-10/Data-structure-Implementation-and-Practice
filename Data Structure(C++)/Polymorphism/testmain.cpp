#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include <cstdlib>

using namespace std;

class User {
 private:
  string username;
  string password;

 public:
  //creates a user with empty name and password.
  User();

  // creates a user with given username and password.
  User(const string& uname, const string& pass);

  //returns the username
  string getUsername() const;

  // returns true if the stored username/password matches with the
  // parameters. Otherwise returns false.
  // Note that, even though a User with empty name and password is 
  // actually a valid User object (it is the default User), this 
  // function must still return false if given a empty uname string.
  bool check(const string &uname, const string &pass) const;

  // sets a new password.
  // This function should only set the new password if the current (old) 
  // password is passed in. Also, a default User cannot have its 
  // password changed. 
  // returns true if password changed, false if not.
  bool setPassword(const string &oldpass, const string &newpass);
};

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





int main() {
   bool open = true;
    string userName;
    string passWord;
    string file;
    ifstream inFS;
    vector<User> userList;
    cout << "enter file ";
    cin >> file;
    cout << endl;
    inFS.open(file.c_str());
    if (!inFS.is_open()) {
        open = false; 
    }
    else {
    }
    while (inFS >> userName >> passWord) {
        User a(userName, passWord);
        userList.push_back(a);
    }
    if(open) {
        cout << "right" << endl;
    }
    else {
        cout << "wrong" << endl;
    }
    inFS.close();
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}