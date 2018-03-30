//
// Created by agile on 18-3-7.
//

#ifndef INC_7_11_SALES_DATA_H
#define INC_7_11_SALES_DATA_H

#include <string>
#include <arpa/nameser.h>
#include "iostream"
using std::ostream;
using std::ostream;

class Sales_data {
public:
    Sales_data() = default;
    ostream& operator<<(ostream& out);
    Sales_data(const std::string &book) : bookNo(book) {}

    Sales_data(const std::string &book, const unsigned num, const double sellp, const double salep);
    void output(ostream& out)
    {
        out<<bookNo<<" "<<sellingprice<<" "<<saleprice<<" "<<discount;
    }
    Sales_data(std::istream &is);

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double sellingprice = 0;
    double saleprice = 0.0;
    double discount = 0.0;
};

Sales_data::Sales_data(const std::string &book, const unsigned num, const double sellp, const double salep) {
    bookNo = book;
    units_sold = num;
    sellingprice = sellp;
    saleprice = salep;
    if (saleprice != 0)
        discount = saleprice / sellingprice;
}
ostream& Sales_data::operator<<(ostream& out)
{
    /*
    s.output(out);
    return out;
     */
    out<<bookNo<<" "<<sellingprice<<" "<<saleprice<<" "<<discount;
    return out;
}
Sales_data::Sales_data(std::istream &is) {
    is >> bookNo;
}



#endif //INC_7_11_SALES_DATA_H
