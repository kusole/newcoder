//
// Created by agile on 18-3-8.
//

#ifndef INC_7_11_SCREEN_H
#define INC_7_11_SCREEN_H

#include <iostream>
#include <string>

using std::string;
using std::cout;

class Screen {
private:
    unsigned height = 0;
    unsigned width = 0;
    unsigned cursor = 0;
    string contents;
public:
    Screen() = default;

    Screen(unsigned ht, unsigned wd) : height(ht), width(wd), contents(ht * wd, ' ') {}

    Screen(unsigned ht, unsigned wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}

    Screen &move(unsigned r, unsigned l);

    Screen &set(char c);

    Screen &display();
};

Screen &Screen::move(unsigned r, unsigned l) {
    cursor = r * width + l;
    return *this;
}

Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

Screen &Screen::display() {
    cout << contents;
    return *this;
}

#endif //INC_7_11_SCREEN_H
