#include <iostream>
#include <string>

using namespace std;

int main() {
    string word, line;
    cout << "请选择输入方式　１ 读词语　２读行" << endl;
    char ch;
    cin >> ch;
    if (ch == '1') {
        cout << "请输入字符串" << endl;
        cin >> word;
        cout << word << endl;
        return 0;
    }
    cin.clear();
    cin.ignore();
    if (ch == '2') {
        cout << "请输入字符串" << endl;
        getline(cin, line);
        cout << line << endl;
        return 0;
    }
    cout << "您的输入有误" << endl;
    return -1;
}