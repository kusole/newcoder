//
// Created by agile on 18-3-30.
//

#ifndef INC_1_2_TWOSTACKQUEUE_SOLUTION1_H
#define INC_1_2_TWOSTACKQUEUE_SOLUTION1_H

#include <stack>
#include <stdexcept>

using namespace std;

class Solution1 {
public:
    void push(int a) {
        stackPush.push(a);
    }

    int pop() {
        if(stackPop.empty()&&stackPush.empty())
            throw runtime_error("队列中无数据！！！");
        if (stackPop.empty()) {
            while (!stackPush.empty()) {
                stackPop.push(stackPush.top());
                stackPush.pop();
            }
        }
        int tmp = stackPop.top();
        stackPop.pop();
        return tmp;
    }

private:
    stack<int> stackPush;
    stack<int> stackPop;
};

#endif //INC_1_2_TWOSTACKQUEUE_SOLUTION1_H
