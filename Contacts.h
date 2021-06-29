#pragma once
#include "_import.h"
class Contacts
{
	int user_id = 0;
	string phone;
	string email;
	string address;
public:
	Contacts(int id, string phone, string email, string address)
		:user_id(id), phone(phone), email(email), address(address) {}
	Contacts() {}
	void print() {
		cout << "Contacts:\n\t"; PRINT(phone);
		cout << "\t"; PRINT(email);
		cout << "\t"; PRINT(address);
	}
};


