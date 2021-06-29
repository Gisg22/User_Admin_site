#pragma once
#include "User.h"
class Customer :
	public User
{
	string subscribe_type;
	int cash;
public:
	Customer(int id, string lg, string pwd, string subscribe_type, int cash)
		:User(id, lg, pwd), subscribe_type(subscribe_type), cash(cash) {}
	Customer(string login)
		:Customer(rand() % 8999 + 1000, login, GeneratePwd(), "none", 0) {}
	Customer() {}
	void print() override {
		User::print();
		PRINT(subscribe_type);
		PRINT(cash);
		contacts.print();
	}
};



