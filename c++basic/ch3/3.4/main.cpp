#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
//    if (s1 == s2)
//        cout << "=" << endl;
//    else if (s1 > s2)
//        cout << ">" << endl;
//    else
//        cout << "<" << endl;
    auto len1 = s1.size();
    auto len2 = s2.size();
    if (len1 == len2)
        cout << "=" << endl;
    else if (len1 >len2)
        cout << ">" << endl;
    else
        cout << "<" << endl;
    return 0;
}