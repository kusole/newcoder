#include <iostream>
#include "Solution1.h"

using namespace std;

int main() {
    Solution1 A;
    A.push(1);
    A.push(2);
    A.push(3);
    A.push(4);
    A.push(5);

    cout << A.pop();
    cout << A.pop();
    cout << A.pop();
    cout << A.pop();

    A.push(6);
    A.push(7);
    A.push(8);
    A.push(9);
    A.push(10);

    cout << A.pop();

    cout << A.pop();
    cout << A.pop();
    cout << A.pop();
    cout << A.pop();
    cout << A.pop();

    return 0;
}