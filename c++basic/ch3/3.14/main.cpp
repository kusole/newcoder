#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int a;
    vector<int> v1;
    while (cin >> a) {
        v1.push_back(a);
    }
    for (auto men:v1)
        cout << men << " ";
    cout << endl;
    return 0;
}