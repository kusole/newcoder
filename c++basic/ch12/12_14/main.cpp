#include <iostream>
#include <memory>

using namespace std;
struct destination {
};
struct connection {
};

connection connect(destination *pd) {
    cout << "打开链接" << endl;
    return connection();
}

void disconnect(connection c) {
    cout << "关闭链接" << endl;
}

//未使用shared_ptr
void f(destination &d) {
    cout << "直接管理connect" << endl;
    connection c = connect(&d);

    cout << endl;
}

void end_connection(connection *p) { disconnect(*p); }

//使用shared_ptr
void f1(destination &d) {
    cout << "用shared_ptr管理connect" << endl;
    connection c = connect(&d);
    shared_ptr<connection> p(&c, end_connection);

    cout << endl;
}

int main() {
    destination d;
    f(d);
    f1(d);
    return 0;
}