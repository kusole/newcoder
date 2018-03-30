//
// Created by agile on 18-3-16.
//

#ifndef INC_9_51_DATE_H
#define INC_9_51_DATE_H
#include <iostream>
#include <string>
using namespace std;
class date{
    friend ostream&operator<<(ostream &, const date&);

public:
    date()= default;
    date(string &s);
    unsigned y() const{return year;}
    unsigned m() const{return month;}
    unsigned d() const{return day;}

private:
    unsigned year, month, day;
};

ostream& operator<<(ostream & out, const date &d){
    out << d.y() << "年"<< d.m()<<"月"<<d.d()<<"日"<< endl;
    return out;
}

#endif //INC_9_51_DATE_H
