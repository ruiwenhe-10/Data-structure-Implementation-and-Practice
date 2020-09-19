#include "BBoard.h"
#include "User.h"
#include "Message.h"
#include "Topic.h"
#include "Reply.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

string un = "";
BBoard::BBoard()
: title("Jack's Amazing Bulletin Board"), currentUser(0)
{}

BBoard::BBoard(const string &ttl)
: title(ttl), currentUser(0)
{}

BBoard::~BBoard()
{
   for(unsigned i = 0; i < messageList.size(); i++)
   {
      if(messageList.at(i) != 0)
      {
         delete messageList.at(i);
      }
   }  
}
bool BBoard::loadUsers(const string &userfile)
{
   ifstream inf;  
   string a, b = "";
   inf.open(userfile.c_str());
   if(!inf.is_open())
   {
      return false;
   }
   inf >> a;
   while(a != "end")
   {
      inf >> b;
      User u(a,b);
      userList.push_back(u);
      inf >> a;
   }
   inf.close();
   return true;
}
bool BBoard::loadMessages(const string& datafile)
{
   ifstream inf;
   stringstream a;
   string author, subject, body, kid, next;
   unsigned id, cid, nummessages = 0;;
   Message *Top = 0, *Rep = 0;
   vector<string> kids;
   inf.open(datafile.c_str());
   if(!inf.is_open())
   {
      return false;
   }
   inf >> nummessages;
   if(nummessages == 0)
   {
      return true;
   }
	while(!inf.eof())
	{
      inf >> next;
		if(next == "<begin_topic>")
		{
			while(next != "<end>")
			{
				inf >> next;
				if(next == ":id:")
				{
					inf >> id;
				}
				else if(next == ":subject:")
				{
					inf.get();
					getline(inf, subject);
				}
				else if(next == ":from:")
				{
					inf >> author;
				}
				else if(next == ":children:")
				{
					getline(inf, next);
					kids.push_back(next);
				}
				else if(next ==":body:")
				{
				   body = "";
					inf.get();
					while(next != "<end>")
					{
					   getline(inf, next);
						if(next != "<end>")
						{
						   body += next;
						}
						inf >> next;
						if(next != "<end>")
						{
						   body += ("\n" + next);
						}
					}
					if(body.size() != 0 && body.at(body.size() - 1) == '\n')
					{
						body.erase(body.size() - 1);
					}
					kid = "0";
					kids.push_back(kid);
				}
			}
			Top = new Topic(author, subject, body, id);
			messageList.push_back(Top);
		}
		else if(next == "<begin_reply>")
		{
		   while(next != "<end>")
			{
				inf >> next;
				if(next == ":id:")
				{
					inf >> id;
				}
				else if(next == ":subject:")
				{
					inf.get();
					inf >> next;
					inf.get();
					getline(inf, subject);
				}
				else if(next == ":from:")
				{
					inf >> author;
				}
				else if(next == ":children:")
				{
					getline(inf, next);
					kids.push_back(next);
				}
				else if(next ==":body:")
				{
			   	body = "";
					inf.get();
					while(next != "<end>")
					{
						getline(inf, next);
						if(next != "<end>")
						{
						   body += next;  
						}
						inf >> next;
						if(next != "<end>")
						{
								body += ("\n" + next);
						}
					}
					if(body.size() != 0 && body.at(body.size() -1) == '\n')
					{
						body.erase(body.size() -1);
					}
					kid = "0";
					kids.push_back(kid);
				}
			}
			Rep = new Reply(author, subject, body, id);
			messageList.push_back(Rep);
			
		}
	}
   for(unsigned i = 0; i < kids.size(); i++)
	{
	   a << kids.at(i) << endl;
	}
	for(unsigned i = 0; i < nummessages; i++)
	{
		while(true)
		{
			a >> cid;
			if(cid == 0)
			{
			   break;
			}
			messageList.at(i)->addChild(messageList.at(cid - 1));
		}
	}
	inf.close();
	return true;
}
bool BBoard::saveMessages(const string& datefile)
{
   ofstream outF;
   outF.open(datefile.c_str());
   if(!outF.is_open())
   {
      return false;
   }
   outF << messageList.size() << endl;
   for(unsigned i = 0; i < messageList.size(); i++)
   {
      outF << messageList.at(i)->toFormattedString();
   }
   outF.close();
   return true;
}
void BBoard::login() 
{
   cout << "Welcome to " << title << endl;
   int counter = 0;
   do
   {
      cout << "Enter your username ('Q' or 'q' to quit): ";
      string pass = "";
      cin >> un;
      if((un == "q") || (un == "Q"))
      {
         cout << "Bye!" << endl;
         return;
      }
      cout << "Enter your password: ";
      cin >> pass;
      for(unsigned i = 0; i < userList.size(); i++)
      {
         if(userList.at(i).check(un,pass))
         {
            counter++;
            un = userList.at(i).getUsername();
            currentUser = &userList.at(i);
         }
      }
      if(counter != 0)
      {
         cout << "Welcome back " << un << '!' << endl;
         cout << endl;
      }
      if(counter == 0)
      {
         cout << "Invalid Username or Password!" << endl;
         cout << endl;
      }
   }
   while(counter == 0);
}
void BBoard::run()
{
   if(currentUser == 0)
   {
      return;
   }
   string line = "---------------------------------------------------------";
   string check = "";
   do
   {
      string letter = "";
      do
      {
         cout << "Menu" << endl;
         cout << "- Display Messages ('D' or 'd')" << endl;
         cout << "- Add New Topic ('N' or 'n')" << endl;
         cout << "- Add Reply to a Topic ('R' or 'r')" << endl;
         cout << "- Quit ('Q' or 'q')" << endl;
         cout << "Choose an action: ";
         cin >> letter;
         cout << endl;
      }
      while((letter != "D") && (letter != "d") && (letter != "N")
      && (letter != "n") && (letter != "R") && (letter != "r")
      && (letter != "Q") && (letter != "q"));
      if((letter == "D") || (letter == "d"))
      {
         if(messageList.size() == 0)
         {
            cout << endl;
            cout << "Nothing to Display." << endl;
         }
         else
         {
            for(unsigned i = 0; i < messageList.size(); i++)
            {
               if(!messageList.at(i)->isReply())
               {
                  cout << line << endl;
                  messageList.at(i)->print(0);
               }
            }
            cout << line << endl;
         }
      }
      if((letter == "N") || (letter == "n"))
      {
         addTopic();
      }
      if((letter == "R") || (letter == "r"))
      {
         addReply();
      }
      if((letter == "Q") || (letter == "q"))
      {
         cout << "Bye!" << endl;
         check == "done";
         return;
      }
   }
   while(check == "");
}
void BBoard::addTopic()
{
   string subject, body = "";
   cout << "Enter a subject: ";
   cin.ignore();
   getline(cin, subject);
   cout << "Enter a body: ";
   getline(cin,body);
   Topic *Tp = new Topic(un, subject, body, messageList.size() + 1);
   messageList.push_back(Tp);
   cout << "Topic Recorded!" << endl << endl;
}
void BBoard::addReply()
{
   int index = 0;
   string body, subject, temp = "";
   int num = 0;
   int size = messageList.size();
   if(messageList.size() == 0)
   {
      cout << "No messages to reply to!" << endl;
      cout << endl;
      return;
   }
   while(index == 0)
   {
      cout << "Enter Message ID (-1 for the menu): ";
      cin >> num;
      if(num == -1)
      {
         return;
      }
      else if((num == 0) || (num > size))
      {
         cout << "Invalid Message Id!" << endl << endl;
      }
      else
      {
         index = 1;
      }
   }
   subject = messageList.at(num - 1)->getSubject();
   cin.ignore();
   cout << "Enter body: ";
   getline(cin, body);
   Reply *Rp = new Reply(un, subject, body, size + 1);
   messageList.at(num - 1)->addChild(Rp);
   messageList.push_back(Rp);
   cout << endl;
}