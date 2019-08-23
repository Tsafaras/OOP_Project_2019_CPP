#pragma once

#include <iostream>
#include "User.h"
using std::cout;
using std::endl;
using std::string;

#include "functions.h"

int main()
{
	User u2("kon", "kakak");
	User u1("anna", "alala");
	User u3("kapoios", "akda");
	User u4("kaneis", "ada");
	User u5("egw", "dapoka");
	User u6("esu", "dakpo");
	u1.friendship(u2);
	u3.friendship(u2);
	u3.friendship(u1);
	u1.AnswerR(u2);

	User::showUsers(u1);
	User::showUsers(u2);

	//showUsers(u1.notFriends());
	//cout << u1.getFriends().at(0).getUsername() ; ////crash
	u1.post(u2);
	//u1.post(u1);
	//u2.AnswerR(u1);

	//u1.getRequests();
	return 0;
}