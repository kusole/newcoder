//
// Created by AJGT on 2018/4/7.
//

#ifndef INC_12_32_MY_QUERYRESULT_H
#define INC_12_32_MY_QUERYRESULT_H

#include <memory>
#include <string>
#include <vector>
#include <set>
#include <iostream>
#include "my_StrBlob.h"

using namespace std;

class QueryResult {
    friend ostream &print(ostream &, const QueryResult &);

public:
    typedef vector<string>::size_type line_no;
    typedef set<line_no>::const_iterator line_it;

    QueryResult(string &s, shared_ptr<set<line_no>> p, StrBlob f) : sought(s), lines(p), file(f) {}

    set<line_no>::size_type size() const { return lines->size(); }

    line_it begin() const { return lines->begin(); }

    line_it end() const { return lines->end(); }

    StrBlob get_file() { return file; }

private:
    string sought;
    shared_ptr<set<line_no >> lines;
    StrBlob file;
};

ostream &print(ostream &, const QueryResult &);

#endif //INC_12_32_MY_QUERYRESULT_H
