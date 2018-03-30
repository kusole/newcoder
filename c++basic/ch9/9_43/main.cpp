#include <iostream>
#include <string>
#include <vector>

using namespace std;

void replace_str(string &s, const string &oldval, const string &newval) {
    if (!oldval.size())return;

    auto s_p = s.begin();
    while (s_p <= s.end() - 1) {
        auto s_ptmp = s_p;
        auto old_p = oldval.begin();
        while(old_p != oldval.end() && *old_p == * s_ptmp){
            old_p++;
            s_ptmp++;
        }
        if(old_p == oldval.end()){
            s_p = s.erase(s_p,s_ptmp);
            if(newval.size()){
                auto new_p = newval.end()-1;
                while(new_p >= newval.begin()){
                    s_p = s.insert(s_p,1,*new_p);
                    new_p--;
                }
            }
            s_p+=newval.size();
        }
        else{
            s_p++;
        }
    }
}

int main() {
    string s="thu thru tho!";
    replace_str(s,"tho", "through");
    cout << s << endl;
    return 0;
}