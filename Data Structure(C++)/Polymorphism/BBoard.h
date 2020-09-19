#ifndef BBOARD_H
#define BBOARD_H

#include<iostream>
#include<fstream>
#include<vector>
#include "User.h"
#include "Message.h"

using namespace std;
//This is the interface for the BBoard class

//Class BBoard for the bulletin board
class BBoard{
    private:
        string title;
        vector<User> userList;
        const User *currentUser;
        vector<Message *> messageList;
        void display() const;
		void addTopic();
		void addReply();
		const User * getUser(const string &name, const string &pw) const;
        
        
    public:
        BBoard();
        BBoard(const string &ttl);
		~BBoard();
        bool loadUsers(const string &userfile);
		bool loadMessages(const string& datafile);
		bool saveMessages(const string& datafile);
        void login();
        void run();
};


#endif 