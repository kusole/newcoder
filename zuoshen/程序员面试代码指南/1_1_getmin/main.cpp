#include <iostream>
#include "Solution1.h"
#include "Solution2.h"

using namespace std;

int main() {
    Solution2 A;
    A.push(3);
    cout << A.getMin();
    A.push(4);
    cout << A.getMin();
    A.push(5);
    cout << A.getMin();
    A.push(1);
    cout << A.getMin();
    A.push(2);
    cout << A.getMin();
    A.push(1);
    cout << A.getMin();
    cout << endl;
    A.pop();
    cout << A.getMin();
    A.pop();
    cout << A.getMin();
    A.pop();
    cout << A.getMin();
    return 0;
}