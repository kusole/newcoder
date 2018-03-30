#include <iostream>
#include <string>

using namespace std;

int main() {
    string str, result;
    char tmp = 'y';
//    while(cin>>str){
//        result +=str;
//        cout << "是否继续"<<endl;
//        cin >> tmp;
//        if(tmp == 'y' || tmp == 'Y')
//            cout << "请输入下一字符串"<<endl;
//        else
//            break;
//    }

    while (cin >> str) {
        if (!result.size()) {
            result += str;
        } else {
            result = result + ' ' + str;
        }
    }
    cout << result << endl;
    return 0;
}