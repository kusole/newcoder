#include <iostream>
#include <fstream>
#include <list>

using namespace std;

int main() {
    ifstream in("../data");
    if (!in) {
        cerr << "无法打开文件" << endl;
        return -1;
    }
    list<string> ls;
    string str;
    while(in >> str)
        ls.push_back(str);

    for(list<string>::iterator it = ls.begin(); it != ls.end(); it++)
        cout << *it << endl;

    return 0;
}