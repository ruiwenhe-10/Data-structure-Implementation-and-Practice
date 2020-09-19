#include<iostream>
#include<sstream>
#include "Message.h"

using namespace std;


// Constructor creates a new Message object with all data members initialized
//  to the empty string.
Message::Message()
    : author(""), subject(""), body(""), id(0)
{}

// Constructor creates a new Message object with data members author, subject,
//  body initialized to athr, sbjct, and body respectively
Message::Message(const string &athr, const string &sbjct, const string &body,
				unsigned id)
    : author(athr), subject(sbjct), body(body), id(id)
{}

Message::~Message() {
}

void Message::print(unsigned indentation) const {
	cout << "Message #" << id << ": " << subject << endl;
	cout << "from " << author << ": " << body << endl;
}


const string & Message::getSubject() const {
	return subject;
}

unsigned getID() const {
	return id;
}

void addChild(Message *child) {
	childList.pushback(child);
	return;
}
