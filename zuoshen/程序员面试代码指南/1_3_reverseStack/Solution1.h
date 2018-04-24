//
// Created by agile on 18-3-30.
//

#ifndef INC_1_3_REVERSESTACK_SOLUTION1_H
#define INC_1_3_REVERSESTACK_SOLUTION1_H

#include <stack>
#include <stdexcept>

using namespace std;

class Solution1 {
public:
    int getLastEmeOfStack(stack<int> &sta) {
        int result = sta.top();
        sta.pop();
        if (sta.empty())
            return result;
        else {
            int last = getLastEmeOfStack(sta);
            sta.push(result);
            return last;
        }
    }

    void reverse(stack<int> &sta) {
        if (sta.empty())
            return;
        int i = getLastEmeOfStack(sta);
        reverse(sta);
        sta.push(i);
    }

    void addStack(int a) {
        reverseStack.push(a);
    }

    stack<int> &getStack() {
        return reverseStack;
    }

    void printStack(stack<int> sta) {
        bool first = true;
        while (!sta.empty()) {
            if(first) {
                cout << sta.top();
                first = false;
            }
            else
                cout << " " <<sta.top();
            sta.pop();
        }
        cout << endl;
    }

private:
    stack<int> reverseStack;
};

#endif //INC_1_3_REVERSESTACK_SOLUTION1_H
