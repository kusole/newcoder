//
// Created by agile on 18-3-1.
//

#ifndef SALES_DATA_SCREEN_H
#define SALES_DATA_SCREEN_H

#include <string>
#include <iostream>

class Screen {
public:
    typedef std::string::size_type pos;

    Screen() = default;

    Screen(pos ht, pos wd, char c) : height(ht), width(wd),
                                     contents(ht * wd, c) {}
    friend class Window_mgr;
    char get() const {
        return contents[cursor];
    } //得到光标处的字符
    inline char get(pos r, pos c) const;//得到指定位置的字符
    Screen &clear(char = bkground);

private:
    static const char bkground = ' ';
public:
    Screen &move(pos r, pos c);//移动光标

    Screen &set(char);

    Screen &set(pos, pos, char);

    Screen &display(std::ostream &os) {
        do_display(os);
        return *this;
    }

    const Screen &display(std::ostream &os) const {
        do_display(os);
        return *this;
    }

private:
    pos cursor = 0; //鼠标位置
    pos height = 0, width = 0;//屏幕的宽高
    std::string contents; //屏幕的内容
    void do_display(std::ostream &os) const {
        os << contents;
    }

};

Screen &Screen::clear(char c) {
    contents = std::string(height * width, c);
    return *this;
}

Screen &Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}

char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}

Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

Screen &Screen::set(pos r, pos c, char ch) {
    contents[r * width + c] = ch;
    return *this;
}

#endif //SALES_DATA_SCREEN_H
