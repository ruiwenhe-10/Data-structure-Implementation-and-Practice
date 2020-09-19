#ifndef USER_H
#define USER_H

#include<iostream>
#include<string>

using namespace std;

// User class interface for User objects

class User{
    private:
        string username;
        string password;
        
    public:
        User();
        User(const string& uname, const string& pass);
        string getUsername() const;
        bool check(const string &uname, const string &pass) const;
        void setPassword(const string &newpass);
};

#endif