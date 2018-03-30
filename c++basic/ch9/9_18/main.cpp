#include <iostream>
#include <deque>
#include <fstream>
using namespace std;

int main() {
    ifstream in("../data");
    if (!in) {
        cerr << "无法打开文件" << endl;
        return -1;
    }

    string str;
    deque<string> deq;
    while(in>>str){
        deq.push_back(str);
    }
    in.close();

    for(deque<string>::iterator it = deq.begin(); it!=deq.end(); it++)
        cout << *it << endl;

    return 0;
}