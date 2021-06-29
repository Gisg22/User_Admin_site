#include "Admin.h"
#include "Customer.h"

void read_users(vector<unique_ptr<User>>& v) {
	string temp;
	vector<string>p;
	ifstream file("users.csv");
	for (int i = 0; i < CountInFile("users.csv"); i++) {
		getline(file, temp);
		p = split(temp, ';');
		if (p[0] == "admin")
			v.push_back(unique_ptr<User>(new Admin(
				stoi(p[1]), p[2], p[3], p[4], stoi(p[5]), p[6]
			)));
		else v.push_back(unique_ptr<User>(new Customer(
			stoi(p[1]), p[2], p[3], p[4], stoi(p[5])
		)));
	}
	file.close();
}
void read_contacts(vector<unique_ptr<User>>& v) {
	string temp;
	vector<string>p;
	int n = CountInFile("contact.csv");
	ifstream file("contact.csv");
	for (int i = 0; i < n; i++) {
		getline(file, temp);
		p = split(temp, ';');
		for (auto& item : v) {
			if (stoi(p[0]) == item->getId()) {
				item->setContact(Contacts(
					stoi(p[0]), p[1], p[2], p[3]
				));
			}
		}
	}
	file.close();
}
int main() {
	vector<unique_ptr<User>> users;
	read_users(users);
	read_contacts(users);
	for (auto& item : users) item->print();
	return 0;
}