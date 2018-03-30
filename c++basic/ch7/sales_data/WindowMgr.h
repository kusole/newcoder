//
// Created by agile on 18-3-1.
//

#ifndef SALES_DATA_WINDOWMGR_H
#define SALES_DATA_WINDOWMGR_H

#include <vector>
#include <string>
#include <iostream>
#include "Screen.h"

class Window_mgr {
public:
    using ScreenIndex =std::vector<Screen>::size_type;

    void clear(ScreenIndex);

    ScreenIndex addScreen(const Screen &);

private:
    std::vector<Screen> screens{Screen(24, 80, ' ')};

};

void Window_mgr::clear(ScreenIndex i) {
    Screen &s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}

Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s) {
    screens.push_back(s);
    return screens.size() - 1;
}

#endif //SALES_DATA_WINDOWMGR_H
