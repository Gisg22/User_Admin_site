#pragma once
#include "User.h"
class Admin :
    public User
{
    string department;
    int access_lvl = 0;
    string type;
public:
    Admin(int id, string lg, string pwd, string dep, int al, string type)
        :User(id, lg, pwd), department(dep), access_lvl(al), type(type) {}
    Admin(string login)
        :Admin(rand() % 8999 + 1000, login, GeneratePwd(), "it dev", 2, "front-end") {}
    Admin() {}
    void print() override {
        User::print();
        PRINT(department);
        PRINT(access_lvl);
        PRINT(type);
        contacts.print();
    }
};


