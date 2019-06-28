#ifndef __FUNCTIONS_H_INCLUDED
#define __FUNCTIONS_H_INCLUDED

class User;
class Message;

#include <vector>
#include <algorithm>
#include <iterator>

using std::find;
using std::make_pair;
using std::sort;
using std::set_difference;
using std::inserter;
using std::vector;

typedef pair<bool, vector<User>::iterator> _pos;

#include <chrono>
#include <ctime>
using std::chrono::system_clock;
using std::time_t;
using std::ctime;

static time_t getTime() {
	system_clock::time_point timestamp = system_clock::now();
	time_t date = system_clock::to_time_t(timestamp);
	return date;
}

//finds position of u in a given friendlist (someone else's)
static _pos position(vector<User> s, User u)
{
	_pos result;
	result.first = false;
	auto pos = find(s.begin(), s.end(), u);
	if (pos != s.end())
	{
		result.first = true;
		result.second = pos;
	}
	return result;
}

//checks to see if u1's friendlist contains u2 and vice versa
static bool contains(const User u1, const User u2, const vector<User> v1, const vector<User> v2)
{
	return position(v1, u2).first && position(v2, u1).first;
}

//u1 deletes u2 from his v1 and u2 deletes u1 from his v2
static void remove(User u1, User u2, vector<User>& v1, vector<User>& v2)
{
	//v1.erase(position(v1, u2).second);
	//v2.erase(position(v2, u1).second);
}

//adds u2 to u1's v1 and u1 to u2's v2
static void add(User u1, User u2, vector<User> v1, vector<User> v2)
{
	v1.push_back(u2);
	v2.push_back(u1);
	cout << "You are now friends with: " << u2.getUsername() << "!" << endl;
}

//handles friend request answers
static void handle(User u1, User u2, const bool x)
{
	if (x) //acceptance of friend request
		add(u1, u2, u1.getFriends(), u2.getFriends());

	//remove(u1, u2, u1.getReceived(), u2.getSent());
}

//shows the users who aren't u's friends
static vector<User> diff(User u, vector<User> net_users)
{
	vector<User> my_friends, diff;

	my_friends = u.getFriends();
	sort(my_friends.begin(), my_friends.end());

	sort(net_users.begin(), net_users.end());

	set_difference(my_friends.begin(), my_friends.end(), net_users.begin(), net_users.end(),
		inserter(diff, diff.begin()));

	return diff;
}

//prints contents of vector "v", displaying position and username
static void showUsers(vector<User> v)
{
	cout << "showingUsers";
	int pos = 0;
	vector<User>::iterator it;

	for (it = v.begin(); it != v.end(); it++)
	{
		cout << "[" << pos << "] " << (*it).getUsername() << endl;
		pos++;
	}
}


#endif // !__FUNCTIONS_H_INCLUDED