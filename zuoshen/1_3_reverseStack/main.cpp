#include <iostream>
#include "Solution1.h"
using namespace std;

int main() {
    Solution1 A;
    A.addStack(1);
    A.addStack(2);
    A.addStack(3);
    A.addStack(4);
    A.addStack(5);

    A.printStack(A.getStack());

    A.reverse(A.getStack());

    A.printStack(A.getStack());

    return 0;
}