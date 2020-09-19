#include <iostream>
#include "Message.h"
#include "Topic.h"
#include "Reply.h"
#include <sstream>

using namespace std;

Topic::Topic()
	: Message()
{}

Topic::Topic(const string &athr, const string &sbjct, const string &body,
			unsigned id)
	: Message(athr, sbjct, body, id)
{}

bool Topic::isReply() const
{
	return false;
}
