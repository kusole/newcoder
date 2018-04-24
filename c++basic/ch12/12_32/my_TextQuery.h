//
// Created by AJGT on 2018/4/7.
//

#ifndef INC_12_32_MY_TEXTQUERY_H
#define INC_12_32_MY_TEXTQUERY_H

#include <memory>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include "my_QueryResult.h"

class QueryResult;

class TextQuery {
public:
    using line_no = vector<string>::size_type;

    TextQuery(ifstream &);

    QueryResult query(const string &) const;

    void display_map();

private:
    StrBlob file;
    map<string, shared_ptr<set<line_no>>> wm;

    static std::string cleanup_str(const string &);

};

#endif //INC_12_32_MY_TEXTQUERY_H
