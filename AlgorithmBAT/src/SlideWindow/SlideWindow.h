//
// Created by AJGT on 2018/4/7.
//

#ifndef SLIDEWINDOW_SLIDEWINDOW_H
#define SLIDEWINDOW_SLIDEWINDOW_H

#include <iostream>
#include <deque>
#include <vector>

using namespace std;

class SlideWindow {
public:
    vector<int> slide(vector<int> arr, int n, int w) {
        // write code here
        deque<int> qmax;
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (qmax.empty()) {
                qmax.push_back(i);
            } else {
                while (!qmax.empty()) {
                    if (arr[i] >= arr[qmax.back()]){
                        qmax.pop_back();
                    }
                    else break;
                }
                qmax.push_back(i);
                if(i-w == qmax.front())qmax.pop_front();
            }
            if(i-w+1>=0) result.push_back(arr[qmax.front()]);
        }
        return result;
    }
};

#endif //SLIDEWINDOW_SLIDEWINDOW_H
