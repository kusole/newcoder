//
// Created by agile on 18-3-1.
//

#ifndef SALES_DATA_SALES_DATA_H
#define SALES_DATA_SALES_DATA_H

#include <string>
#include <iostream>

class Sales_data {
    friend Sales_data add(const Sales_data &, const Sales_data &);

    friend std::ostream &print(std::ostream &, const Sales_data &);
    friend std::istream &read(std::istream &, Sales_data &);
public:
    Sales_data() = default;

    Sales_data(const std::string &s) : bookNo(s) {}

    Sales_data(const std::string &s, unsigned n, double p) :
            bookNo(s), units_sold(n), revenue(p * n) {}

    Sales_data(std::istream &) {}

    std::string isbn() const { return bookNo; }//返回书编号
    Sales_data &combine(const Sales_data &);//添加相同书编号的书籍信息到一个对象


private:
    double avg_price() const;//平均价格

    std::string bookNo;//书编号
    unsigned units_sold = 0;//数量
    double revenue = 0.0;//总价
};

std::ostream &print(std::ostream &, const Sales_data &);

std::istream &read(std::istream &, Sales_data &);

Sales_data add(const Sales_data &, const Sales_data &);

#endif //SALES_DATA_SALES_DATA_H
