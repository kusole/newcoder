#include <iostream>
#include <list>
#include <fstream>
#include <deque>

using namespace std;

int main() {
    ifstream in("../data");
    if (!in) {
        cerr << "无法打开文件" << endl;
        return -1;
    }

    int aa;
    deque<int> deq1;
    deque<int> deq2;
    list<int> ls;

    while (in >> aa)
        ls.push_back(aa);

    for (auto it = ls.begin(); it != ls.end(); it++) {
        if ((*it) & 1)
            deq1.push_back(*it);
        else
            deq2.push_back(*it);
    }

    for (auto it = deq1.begin(); it != deq1.end(); it++)
        cout << ' ' << *it;
    cout << endl;
    for (auto it = deq2.begin(); it != deq2.end(); it++)
        cout << ' ' << *it;
    in.close();
    return 0;
}