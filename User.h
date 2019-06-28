#ifndef __USER_H_INCLUDED
#define __USER_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>

class Message;

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::pair;
using std::getline;
using std::cin;

class User {
private:
	string username, email;
	vector<User> friends, sent, received;
	vector<Message*> messages;
public:
	User() {};
	//~User() {cout << username << " deleted" << endl;};
	User(const string, const string);

	//-------------SET COMPARE, NEEDED TO ORDER-----------
	friend bool operator<(const User, const User);
	friend bool operator==(const User, const User);
	friend bool operator!=(const User, const User);

	//------------METHODS--------------
	void friendship(User);
	void AnswerR(User);
	vector<User> notFriends();
	User select(vector<User>, int);
	void post(User);

	//-----------Setters-----------------
	void setUsername(const string&);
	void setEmail(const string&);

	//-----------Getters-----------------
	string getUsername()const;
	string getEmail()const;
	vector<User> getFriends()const;
	vector<User> getSent()const;
	vector<User> getReceived()const;
};

#endif //__USER_H_INCLUDED