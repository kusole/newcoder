#include <iostream>
#include <string>

using namespace std;

int main() {
    string s,result;
    getline(cin, s);
//    for (auto c:s) {
//        if (!ispunct(c))
//            cout << c;
//    }
//    cout << endl;g
    for(decltype(s.size()) i =0;i<s.size();i++){
        if(!ispunct(s[i]))
            result += s[i];
    }
    cout << result <<endl;
    return 0;
}