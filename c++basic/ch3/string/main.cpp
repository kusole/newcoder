#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string word;
//    while(cin>> word){
//        cout<<word<<endl;
//    }
    string line;
//    while(getline(cin, line)){
//        cout << line << endl;
//        cout << line.length() << endl;
//        cout << line.empty() << endl;
//        cout << line.size() << endl;
//    }

//    string str(10,'c');
//    string s1 = str;
//    string s2 = s1 + str;
//    s1+=s2;

//    string str("some string");
//    for (auto c : str){
//        cout << c << endl;
//    }

//    string s("hello world!!!");
//    decltype(s.size()) punct_cnt=0;
//    for(auto c:s){
//        if(ispunct(c))
//            ++punct_cnt;
//    }
//    cout << punct_cnt
//         << " punctuation characters in " << s << endl;

//    string s("Hello World!!!");
//    for (auto &c : s){
//        c = toupper(c);
//    }
//    cout << s << endl;

//    string s("some string");
//    if(!s.empty())
//        s[0]=toupper(s[0]);
//    cout << s << endl;

//    string s("some string");
//    for(decltype(s.size()) index = 0; index != s.size() && !isspace(s[index]); ++index)
//        s[index]= toupper(s[index]);
//    cout <<s << endl;

    const string hexdigits = "0123456789ABCDEF";
    string result;
    string::size_type n;
    while (cin >> n) {
        if (n < hexdigits.size()) {
            result += hexdigits[n];
        }
    }
    cout << result << endl;

    return 0;
}