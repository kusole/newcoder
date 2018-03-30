#include <iostream>
#include "Sales_data.h"
using namespace std;
int main() {
    Sales_data data1;
    Sales_data data2("123456");
    Sales_data data3("1123456",100,128,109);
    Sales_data data4(std::cin);

    cout << "aaa"<<endl;
    //cout << data1 <<"\n"<<data2<<"\n"<<data3<<"\n"<<data4<<"\n";
    data1.operator<<(cout);

    return 0;
}