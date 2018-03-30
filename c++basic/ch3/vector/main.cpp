#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<unsigned> socres(11, 0);
    unsigned grades;
    while (cin >> grades) {
        if (grades <= 100) {
            ++socres[grades / 10];
        }
    }
    for(auto i:socres){
        cout << i << endl;
    }
    return 0;
}