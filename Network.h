#ifndef __NETWORK_H_INCLUDED
#define __NETWORK_H_INCLUDED

#include <iostream>
#include <vector>
#include "functions.h"

using std::vector;

class User;

class Network {
private:
	Network() {};
	vector<User> ListofUsers;
public:
	//------Singleton Stuff-----
	static Network& getInstance()
	{
		static Network  instance;
		return instance;
	}

	Network(Network const&) = delete;
	void operator=(Network const&) = delete;

	//------------Methods--------
	static void registerUser(User& u)
	{
		Network net;
		//Network::ListofUsers.push_back(u);
		net.ListofUsers.push_back(u);
	}

	static bool usersAreFriends(User& u1, User& u2)
	{
		if (u1 == u2)
			return false;
		else
			return contains(u1, u2, u1.getFriends(), u2.getFriends());
	}

	//-----------Getter------------
	static vector<User> getUsers()
	{
		Network net;
		return net.ListofUsers;
	}
};

#endif // !__NETWORK_H_INCLUDED

