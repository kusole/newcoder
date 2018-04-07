#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<int> *new_vector(void) {
    return new(nothrow)vector<int>;
}

void read_ints(vector<int> *pv) {
    int v;
    ifstream in("../data.txt");
    if (!in)
        throw runtime_error("no input file!!!");

    while (in >> v) {
        pv->push_back(v);
    }
}

void print_ints(vector<int> *pv) {
    for (const auto &v: *pv)
        cout << v << " ";
    cout << endl;
}

int main() {
    vector<int> *pv = new_vector();
    if(!pv){
        cout << "内存不足" << endl;
        return -1;
    }
    read_ints(pv);
    print_ints(pv);
    return 0;
}