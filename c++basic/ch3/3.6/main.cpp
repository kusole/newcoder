#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cout << "输入字符串" << endl;
    getline(cin, s);
    for (auto &c:s)
        c = 'x';
    cout << s << endl;
    return 0;
}