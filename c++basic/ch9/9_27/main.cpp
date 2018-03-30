#include <iostream>
#include <forward_list>

using namespace std;

int main() {
    forward_list<int> ifls = {1, 2, 3, 4, 5, 6, 7, 8};
    auto prev = ifls.before_begin();
    auto curr = ifls.begin();
    while (curr != ifls.end()) {
        if (*curr & 1)
            curr = ifls.erase_after(prev);
        else {
            prev = curr;
            curr++;
        }
    }
    for (auto it = ifls.begin(); it != ifls.end(); it++)
        cout << *it << endl;
    cout << endl;
    return 0;
}