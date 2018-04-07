#include <iostream>
#include "TextQuery.h"
int main() {
    ifstream in("../storyDatafile");
    if(!in) {
        throw runtime_error("file cant find!!!");
        return -1;
    }
    TextQuery textquery(in);
    QueryResult QR = textquery.query("her");
    print(cout,QR);
    in.close();
    return 0;
}