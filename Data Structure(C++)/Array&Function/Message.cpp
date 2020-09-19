#include <string>
#include <iostream>

using namespace std;

#include "Message.h"


// string author;
// 	string subject;
// 	string body;


Message::Message() {
    author = "";
    subject = "";
    body = "";
}

Message::Message(const string &athr, const string &sbjct, const string &body) {
    author = athr;
    subject = sbjct;
    this->body = body;
}
//
	// subject
	// from author: body
	
void Message::display() const {
    cout << subject << endl;
    cout << "from " << author << ": " << body << endl;
    return;
}
