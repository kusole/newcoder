//
// Created by agile on 18-3-8.
//

#ifndef INC_7_11_PERSON_H
#define INC_7_11_PERSON_H
#include <string>
#include <iostream>
using std::string;
using std::istream;
class Person{
    friend istream&operator>>(istream &is,Person &p);
public:
    Person()= default;
    Person(const string &name, const string &add):strName(name),strAddress(add){}
    Person(istream &is){is>>*this;}

    string getName()const {return strName;}
    string getAddress()const{return strAddress;}
private:
    string strName;
    string strAddress;
};
istream&operator>>(istream&is, Person &p){
    is>>p.strName>>p.strAddress;
    return is;
}
#endif //INC_7_11_PERSON_H
