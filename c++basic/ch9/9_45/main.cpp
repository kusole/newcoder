#include <iostream>
#include <string>
#include <vector>

using namespace std;

void name_string(string &s, const string &pre, const string &suf) {
    s.insert(s.begin(), 1, ' ');
    s.insert(s.begin(), pre.begin(), pre.end());
    s.append(" ");
    s.append(suf.begin(), suf.end());
}

int main() {
    string s = "james bond";
    name_string(s, "Mr.", "II");
    cout << s << endl;
    return 0;
}