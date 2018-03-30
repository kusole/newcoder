#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
struct PersonInfo {
    string name;
    vector<string> phone;
};

string format(const string &s) { return s; }

bool valid(const string &s) {
    return true;
}

int main() {
    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    ifstream in("../data");
    if(!in){
        cerr<<"无法打开文件"<<endl;
        return -1;
    }
    while(getline(in,line)){
        PersonInfo info;
        record.clear();
        record.str(line);
        record>>info.name;
        while(record>>word)
            info.phone.push_back(word);
        people.push_back(info);
    }


    ostringstream os;
    for(const auto &entry:people){

    }
    return 0;
}