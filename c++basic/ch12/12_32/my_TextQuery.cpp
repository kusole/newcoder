//
// Created by AJGT on 2018/4/7.
//

#include "my_TextQuery.h"

#include <cstddef>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <utility>

using namespace std;

TextQuery::TextQuery(ifstream &is) : file(new vector<string>) {

}
