#pragma once
#include "Contacts.h"
class User
{
protected:
	int id = 0;
	string login;
	string password;
	Contacts contacts;
public:
	User(int id, string login, string password)
		:id(id), login(login), password(password) {}
	User(string login) :User(rand() % 8999 + 1000, login, GeneratePwd()) {}
	User() {}
	virtual void print() {
		PRINT(id);
		PRINT(login);
		PRINT(password);
	}
	int getId() { return id; }
	void setContact(Contacts c) {
		contacts = c;
	}
};

