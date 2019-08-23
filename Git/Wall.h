#ifndef __WALL_H_INCLUDED
#define __WALL_H_INCLUDED

#include "User.h"
#include "functions.h"

#include <string>
#include <iostream>
#include <vector>
using std::string;
using std::cout;
using std::endl;
using std::vector;

class User;
class ReplyMessage;

class Message {
private:
	string message, username;
	int likes;
	vector<ReplyMessage> Replies;
	vector<User> LikedBy;
	time_t timestamp;
public:
	Message(const string user, const string msg)
	{
		username = user;
		message = msg;
		timestamp = getTime();
	}

	void addReply(ReplyMessage a) { Replies.push_back(a); }

	void setLike(User& u)
	{
		if (position(LikedBy, u).first)
		{
			LikedBy.push_back(u);
			likes++;
		}
		else
			cout << "You have already liked this post." << endl;
	}

	vector<ReplyMessage> getReplies() const { return Replies; }

	int getLikes() const { return likes; }

	string getMessage() const { return message; }
};

class ReplyMessage : public Message {
public:
	ReplyMessage(const string user, const string reply)
		: Message(user, reply) {}
};

class Wall {
private:
public:
	//Wall(const User&);

	static void showWall(vector<Message> v)
	{
		int pos = 0;
		vector<Message>::iterator it;
		vector<ReplyMessage>::iterator rep;

		for (it = v.begin(); it != v.end(); it++)
		{
			cout << "[" << pos << "] " << (*it).getMessage() << endl;
			pos++;
			for (rep = (*it).getReplies().begin(); rep != (*it).getReplies().end(); rep++)
			{
				int reply = 0;
				cout << "[" << reply << "]" << (*rep).getMessage() << endl;
				reply++;
			}
		}
	}
};

#endif // !__WALL_H_INCLUDED