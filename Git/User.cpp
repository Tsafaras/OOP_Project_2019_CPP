#include "User.h"
#include "Network.h"

//-----------Constructor-----------------
User::User(const string name, const string mail)
{
	username = name;
	email = mail;
	//Network::getInstance().registerUser(*this);
	Network::registerUser(*this);
}

//-----------Is that the same user?-----------------
bool operator==(const User a, const User b) { return a.username == b.username; }

bool operator!=(const User a, const User b) { return !(a == b); }

//-------------SET COMPARE, NEEDED TO ORDER-----------
bool operator<(const User u1, const User u2) { return u1.username < u2.username; }

//-------------------METHODS-----------------------
void User::friendship(User u)
{
	bool x = Network::usersAreFriends(*this, u);
	switch (!x)
	{
	case true:	//add friend
		sent.push_back(u);
		u.received.push_back(*this);

		cout << "Friend request has been sent to " << u.username << endl;
		break;
	case false:	//delete friend
		//remove(*this, u, friends, u.friends);
		cout << "User " << u.username << " is not your friend anymore." << endl;
		break;
	}
}

void User::AnswerR(User u)
{
	if (!contains(*this, u, received, u.sent)) {
		cout << "Would you like " << u.username << " to be your friend?" << endl;
		char ch;
		do
		{
			cout << "Enter 'Y' to accept, 'N' to decline, 'O' to exit." << endl;
			std::cin >> ch;
		} while (!(ch == 'Y' || ch == 'N' || ch == 'O'));


		switch (ch)
		{
		case 'Y':
			friends.push_back(u);
			u.friends.push_back(*this);
			break;
		case 'N':
			//remove(*this, u, sent, u.received);
			break;
		default:
			break;
		}
	}
}

vector<User> User::notFriends()
{
	vector<User> net_user = Network::getUsers();
	net_user = diff(*this, net_user);
	return net_user;
}

User User::select(vector<User> v, int pos) { return v.at(pos); }

void User::post(User u)
{
	cout << "posting";
	if (username == u.username || Network::usersAreFriends(*this, u))
	{
		string post;
		cout << "What would you like to post?" << endl;
		getline(cin, post);
	}
}

//-----------Setters-----------------
void User::setUsername(const string& name) { username = name; }

void User::setEmail(const string& mail) { email = mail; }

//-----------Getters-----------------
string User::getUsername() const { return username; }

string User::getEmail() const { return email; }

vector<User> User::getFriends() const { return friends; }

vector<User> User::getSent() const { return sent; }

vector<User> User::getReceived() const { return received; }

 void User::showUsers(User u)
{
	int i = 0;
	for (i; i < u.friends.size(); i++)
	{
		cout << '[' << i << "]: " << u.friends.at(i).getUsername() << endl;
	}
}
