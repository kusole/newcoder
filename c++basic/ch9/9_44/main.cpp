#include <iostream>
#include <string>
#include <vector>

using namespace std;

void repl_str(string &s, const string &oldval, const string &newval) {
    int p =0;
    while((p=s.find(oldval,p)) != string::npos){
        s.replace(p,oldval.size(),newval);
        p+=newval.size();
    }
}

int main() {
    string s="thu tho tho!";
    repl_str(s,"tho", "aaa");
    cout << s << endl;
    return 0;
}