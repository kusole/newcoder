//
// Created by AJGT on 2018/4/7.
//

#ifndef INC_12_32_MY_STRBLOB_H
#define INC_12_32_MY_STRBLOB_H

#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class StrBlobPtr;

class StrBlob {
    friend class StrBlobPtr;

public:
    typedef vector<string>::size_type size_type;

    StrBlob();

    StrBlob(initializer_list<string> il);

    StrBlob(vector<string> *strs);

    size_type size() const { return data->size(); }

    bool empty() const { return data->empty(); }

    //添加和删除元素
    void push_back(const string &t) { data->push_back(t); }

    void pop_back();

    string &front();

    const string &front() const;

    string &back();

    const string &back() const;

    StrBlobPtr begin();

    StrBlobPtr begin() const;

    StrBlobPtr end();

    StrBlobPtr end() const;

private:
    shared_ptr<vector<string>> data;

    void check(size_type i, const string &msg) const;
};

inline StrBlob::StrBlob() : data(make_shared<vector<string>>()) {}

inline StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}

inline StrBlob::StrBlob(vector<string> *strs) : data(strs) {}

inline void StrBlob::check(size_type i, const string &msg) const {
    if (i >= data->size())
        throw out_of_range(msg);
}

inline string &StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}

inline const string &StrBlob::front() const {
    check(0, "front on empty StrBlob");
    return data->front();
}

inline string &StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}

inline const string &StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return data->back();
}

inline void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}






#endif //INC_12_32_MY_STRBLOB_H
