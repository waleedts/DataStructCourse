#include <iostream>
#include <fstream>
#include <string>
#include "./Header/TList.h"
#include "./Header/MList.h"

using namespace std;

int main() {
    ifstream in;
    string st = "File.txt";
    TList s;
    cout << "Please Enter File Name:";
    cin >> st;
    in.open(st, ios::in);
    if (in.fail()) {
        cerr << "Error Opening file" << endl;
        exit(-1);
    }
    in >> s;
    in.close();
    MList m;
    while (!s.empty()) {
        m.insert(s.pop());
    }
    cout << m;
    return 0;
}