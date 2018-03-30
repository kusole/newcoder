#include <iostream>
#include <forward_list>
using namespace std;

void insertList(forward_list<string> & fls, string &a, string &b){
    auto prev = fls.before_begin();
    auto curr = fls.begin();
    bool inserted = false;
    while(curr != fls.end()){
        if(*curr == a){
            curr = fls.insert_after(curr,b);
            inserted = true;
        }else{
            prev = curr;
            curr ++;
        }
    }
    if(!inserted)
        fls.insert_after(prev, b);
}

int main() {
    forward_list<string> fls={"aaa","bbb","ccc","ccc","ddd"};
    string a("ccc");
    string b("ccf");
    insertList(fls, a, b);
    for(auto it = fls.begin(); it != fls.end(); it++)
        cout << *it << endl;
    return 0;
}