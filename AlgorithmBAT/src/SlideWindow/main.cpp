#include "SlideWindow.h"

using namespace std;

int main() {
    SlideWindow S;
    vector<int> arr{4, 3, 5, 4, 3, 3, 6, 7};
    vector<int> result;
    result = S.slide(arr, arr.size(), 3);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << endl;
    return 0;
}