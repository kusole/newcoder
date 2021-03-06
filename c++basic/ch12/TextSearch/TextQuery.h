//
// Created by lt on 18-4-1.
//

#ifndef TEXTSEARCH_TEXTQUERY_H
#define TEXTSEARCH_TEXTQUERY_H

#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <memory>

using namespace std;

using line_no = vector<string>::size_type;

class QueryResult {
    friend ostream& print(ostream&, const QueryResult&);
public:
    QueryResult(string s,
                shared_ptr<set<line_no>> p,
                shared_ptr<vector<string>> f) :
            sought(s), lines(p), file(f) {}

private:
    string sought;//待查询的单词
    shared_ptr<set<line_no>> lines;//出现的行号
    shared_ptr<vector<string>> file;//输入的文件
};

class TextQuery {
public:

    TextQuery(ifstream &is);

    QueryResult query(const string &) const;


private:
    shared_ptr<vector<string>> file;
    map<string, shared_ptr<set<line_no>>> wm;
};

TextQuery::TextQuery(ifstream &is) : file(new vector<string>) {
    string text;
    while (getline(is, text)) {
        file->push_back(text);
        int n = file->size() - 1;
        istringstream line(text);
        string word;
        while (line >> word) {
            auto &lines = wm[word];
            if (!lines) {
                lines.reset(new set<line_no>);
            }
            lines->insert(n);
        }
    }
}
QueryResult TextQuery::query(const string &sought) const {
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(sought);
    if(loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}
ostream& print(ostream &os,const QueryResult& qr){
    os<< qr.sought<< " occurs " << qr.lines->size() << " " << "times" << endl;
    for(auto num:*qr.lines){
        os<<"\t(line " << num+1 << ") " << *(qr.file->begin()+num) << endl;
    }
    return os;
}

#endif //TEXTSEARCH_TEXTQUERY_H
