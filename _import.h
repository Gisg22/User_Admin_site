#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <vector>
using namespace std;
#define RUS SetConsoleCP(1251); SetConsoleOutputCP(1251); srand(time(NULL));
#define PRINT(x) cout<<(#x)<<" : "<<x<<endl;
#define INPUT(x) cout<<(#x)<<" : "; cin>>x; cin.ignore();
#define INPUT_GL(x) cout<<(#x)<<" : "; getline(cin,x);
#define LINE cout<<"-------------------------------"<<endl;

vector<string> split(string str, int d) {
    vector<string> v;
    while (str.find(d) != -1) {
        v.push_back(str.substr(0, str.find(d)));
        str.erase(0, str.find(d) + 1);
    }
    v.push_back(str);
    return v;
}
int CountInFile(string filename) {
    int counter = 0;
    char c;
    ifstream file;
    file.open(filename);
    while (!file.eof()) {
        file.get(c);
        if (c == '\n') counter++;
    }
    file.close();
    return counter - 1;
}
string GeneratePwd(int size = 10) {
    string new_pwd, s;
    s.append("qwertyuiopasdfghjklzxcvbnm");
    s.append("QWERTYUIOPASDFGHJKLZXCVBNM");
    s.append("1234567890");
    s.append("!@#$%^&*");
    for (int i = 0; i < size; i++) {
        new_pwd += s[rand() % s.length()];
    }
    return new_pwd;
}
