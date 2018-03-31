#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class StrBlob {
public:
    typedef vector<string>::size_type size_type;

    StrBlob();

    StrBlob(initializer_list<string> il);

    size_type size() const { return data->size(); }

    bool empty() const { return data->empty(); }

    //添加和删除元素
    void push_back(const string &t) { data->push_back(t); }

    void pop_back();

    string &front();

    const string &front() const;

    string &back();

    const string &back() const;

private:
    shared_ptr<vector<string>> data;

    void check(size_type i, const string &msg) const;
};

StrBlob::StrBlob() : data(make_shared<vector<string>>()) {}

StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}

void StrBlob::check(size_type i, const string &msg) const {
    if (i >= data->size())
        throw out_of_range(msg);
}

string &StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}

const string &StrBlob::front() const {
    check(0, "front on empty StrBlob");
    return data->front();
}

string &StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}

const string &StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

int main() {
    StrBlob b1;
    {
        StrBlob b2 = {"a", "an", "the"};
        b1 = b2;
        b2.push_back("about");
        cout << b2.size() << endl;
    }
    cout << b1.size() << endl;
    cout << b1.front() << " " << b1.back() << endl;

    const StrBlob b3 = b1;
    cout << b3.front() << " " << b3.back() << endl;
    return 0;
}