#ifndef MESSAGE_H
#define MESSAGE_H

#include<iostream>
#include<string>
#include<vector>

using namespace std;

// Interface for Message class

class Message{
    protected:
        string author;
        string subject;
        string body;
		unsigned id;
		vector<Message *> childList;
        
    public:
        Message();
        Message(const string &athr, const string &sbjct, const string &body,
        		unsigned id);
		virtual ~Message();
		virtual bool isReply() const = 0;
		virtual string toFormattedString() const = 0;
		void print(unsigned indentation) const;
		const string & getSubject() const;
		unsigned getID() const;
		void addChild(Message *child);
};


#endif