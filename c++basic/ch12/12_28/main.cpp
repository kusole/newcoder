#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>

#include <cstdlib>

using namespace std;

using line_no=vector<string>::size_type;

vector<string> file;
map<string, set<line_no>> wm;

string cleanup_str(const string &word) {
    string ret;
    for (auto it = word.begin(); it != word.end(); ++it)
        if (!ispunct(*it))
            ret += tolower(*it);
    return ret;
}

void input_text(ifstream &is) {
    string text;
    while (getline(is, text)) {
        file.push_back(text);
        int n = file.size() - 1;
        istringstream line(text);
        string word;
        while (line >> word) {
            wm[cleanup_str(word)].insert(n);
        }
    }
}

ostream &query_and_print(const string &sought, ostream &os) {
    auto loc = wm.find(sought);
    if (loc == wm.end())
        os << sought << " occurs 0 times" << endl;
    else {
        auto lines = loc->second;
        os << sought << " occurs " << lines.size() << " time(s)" << endl;
        for(auto num : lines){
            os << "\tthe " << num + 1 << "th line: " << *(file.begin()+num) << endl;
        }
    }
    return os;
}

void runQueries(ifstream &infile){
    input_text(infile);
    while(true){
        cout << "enter word to look for, or q to quit: "<<endl;
        string s;
        if(!(cin >> s) || s == "q")break;
        query_and_print(s, cout) << endl;
    }
}


int main() {
    ifstream infile("../storyDatafile");
    if(!infile){
        throw runtime_error("cant open the input file");
    }
    runQueries(infile);
    return 0;
}