#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <stdexcept>
#include <sstream>

using namespace std;

void word_transform(ifstream &map_file, ifstream &input);

map<string, string> buildMap(ifstream &map_file);

string &transform(string &word, map<string, string> &trans_map);

class A{
    int a;
    virtual void func(){};
    virtual void func1(){};
};

int main() {
//    ifstream map_file("../map_file");
//    if (!map_file)
//        throw runtime_error("no transformation file");
//    ifstream input("../input_file");
//    if (!input)
//        throw runtime_error("no input file");
//    word_transform(map_file, input);
    A a;
    int c;
    cout << sizeof(int) + sizeof(void*)<<endl;
    cout << sizeof(a);

    return 0;
}

//void word_transform(ifstream &map_file, ifstream &input) {
//    auto trans_map = buildMap(map_file);
//    cout << "here is our transformation map:\n\n";
//    for (auto entry:trans_map) {
//        cout << "key: " << entry.first << "\tvalue: " << entry.second << endl;
//    }
//    cout << "\n\n";
//
//    string text;
//    while (getline(input, text)) {
//        istringstream stream(text);
//        string word;
//        bool firstword = true;
//        while (stream >> word) {
//            if (firstword)
//                firstword = false;
//            else
//                cout << ' ';
//            cout << transform(word, trans_map);
//        }
//        cout << endl;
//    }
//}
//
//map<string, string> buildMap(ifstream &map_file) {
//    map<string, string> trans_map;
//    string key;
//    string value;
//    while (map_file >> key && getline(map_file, value)) {
//        if (value.size() > 1)
//            trans_map[key] = value.substr(1);
//        else
//            throw runtime_error("no rule for " + key);
//    }
//    return trans_map;
//};
//
//string &transform(string &word, map<string, string> &trans_map){
//    auto map_it = trans_map.find(word);
//    if(map_it != trans_map.cend())
//        return map_it->second;
//    else
//        return word;
//}