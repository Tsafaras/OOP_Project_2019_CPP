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
static bool contains(User u1, User u2, vector<User> const & v1, vector<User> const & v2)
{
	bool flag1 = false;
	bool flag2 = false;
	int i = 0;
	for (i; i < u1.getFriends().size(); i++)
	{
		cout << "dadada" << endl;
		if (u1.getFriends().at(i).getUsername() == u2.getUsername() )
		{
			cout << "grwgrw" << endl;
			flag1 = true;
		}
	}

	for (int j=0; j < u2.getFriends().size(); j++)
	{
		cout << "grwgrw" << endl;
		if (u2.getFriends().at(j).getUsername() == u1.getUsername())
		{
			cout << "gdadarwgrw" << endl;
			flag2 = true;
		}
	}

	return flag1 && flag2;
}

//u1 deletes u2 from his v1 and u2 deletes u1 from his v2
//static void remove(User u1, User u2, vector<User> v1, vector<User> v2)
//{
//	v1.erase(position(v1, u2).second);
//	v2.erase(position(v2, u1).second);
//}

//adds u2 to u1's v1 and u1 to u2's v2


//handles friend request answers
//static void handle(User u1, User u2, const bool x)
//{
	//if (x) //acceptance of friend request
		//add(u1, u2, u1.getFriends(), u2.getFriends());

	//remove(u1, u2, u1.getReceived(), u2.getSent());
//}

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



#endif // !__FUNCTIONS_H_INCLUDED