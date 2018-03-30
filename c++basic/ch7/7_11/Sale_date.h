//
// Created by agile on 18-3-8.
//

#ifndef INC_7_11_SALE_DATE_H
#define INC_7_11_SALE_DATE_H

#include <string>
#include <iostream>

using std::istream
using std::ostream
using std::string

class Sale_data {
    friend ostream &operator<<(ostream &os, Sale_data &s);

    friend istream &read(istream &is, Sale_data &s);

public:
    Sale_data() = default;

    Sale_data(const string &book) : bookNO(book) {}

    Sale_data(const string &book, const unsigned num, const double sellp, const double salep);

    Sale_data(istream &is);

private:
    string bookNO = 0;
    unsigned unit_sold = 0;
    double sellingprice = 0.0;
    double saleprice = 0.0;
    double discount = 0.0;
};

Sale_data::Sale_data(const string &book, const unsigned num, const double sellp, const double salep) {
    bookNO = book;
    unit_sold = num;
    sellingprice = sellp;
    saleprice = salep;
    if (saleprice != 0)
        discount = saleprice / sellingprice;
}

istream &read(istream &is, Sale_data &s) {
    is >> s.bookNO >> s.unit_sold >> s.sellingprice >> s.saleprice;
    if (s.saleprice != 0)
        s.discount = s.saleprice / s.sellingprice;
    return is;
}

Sale_data::Sale_data(istream &is) {
    read(is, *this);
}

ostream &operator<<(ostream &os, Sale_data &s) {
    os << s.bookNO << " " << s.sellingprice << " " << s.saleprice << " " << s.unit_sold << " " << s.discount << "\n";
    return os;
}

#endif //INC_7_11_SALE_DATE_H
