//
// Created by agile on 18-3-30.
//

#ifndef INC_1_1_GETMIN_SOLUTION1_H
#define INC_1_1_GETMIN_SOLUTION1_H

#include <stack>
#include <stdexcept>

using namespace std;

class Solution1 {
public:
    void push(int a) {
        stackData.push(a);
        if (!stackMin.empty()) {
            if (getMin() >= a) {
                stackMin.push(a);
            }
        } else {
            stackMin.push(a);
        }
    }

    int pop() {
        if (stackData.empty())
            throw runtime_error("stackData is empty");
        int popData = stackData.top();
        stackData.pop();
        if (popData == getMin()) {
            stackMin.pop();
        }
        return popData;
    }

    int getMin() {
        if (stackMin.empty())
            throw runtime_error("stackMin is empty");
        return stackMin.top();
    }

private:
    stack<int> stackData;
    stack<int> stackMin;
};

#endif //INC_1_1_GETMIN_SOLUTION1_H
