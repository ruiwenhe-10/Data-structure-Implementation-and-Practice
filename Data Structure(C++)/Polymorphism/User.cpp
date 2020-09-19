#include<iostream>

#include "User.h"


using namespace std;


// Default constructor to create an empty string for username and password
User::User()
    : username(""), password("")
{}

// Constructors assigns data members username and password to parameters
User::User(const string& uname, const string& pass)
    : username(uname), password(pass)
{}

// Accessor function returns the username data member of the User object
string User::getUsername() const
{
    return username;
}

// Accessor function checks to see whether the parameter uname matches with
//  the username data member, and pass matches with password data member
bool User::check(const string& uname, const string& pass) const
{
    if(uname == "" || pass == "")
        return false;
    
    if(uname == username && pass == password)
        return true;
        
    return false;
}

// Accessor function assigns newpass parameter to password datamember, 
//    essentially creating a new password.
void User::setPassword(const string &newpass)
{
    password = newpass;
}