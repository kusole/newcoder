#include <iostream>

using namespace std;

void printfSort(int *A, int n) {
    for (int i = 0; i < n - 1; i++)
        cout << A[i] << ' ';
    cout << A[n - 1] << endl;
}

class CountingSort {
public:
    int *countingSort(int *A, int n) {
        // write code here
        int i, j, num = 0;
        int max = 0, min = 0;
        for (int i = 1; i < n; i++) {
            if (A[i] > A[max])max = i;
            if (A[i] < A[min])min = i;
        }
        int countmax = A[max];
        int countmin = A[min];
        int countarray[countmax - countmin + 1];
        for (i = 0; i < countmax - countmin + 1; i++) {
            countarray[i]=0;
        }
        for (i = 0; i < n; i++) {
            countarray[A[i]  - countmin]++;
        }
        for (i = 0; i < countmax - countmin + 1; i++) {
            if (countarray[i] > 0) {
                for (j = 0; j < countarray[i]; j++) {
                    A[num++] = i  + countmin;
                }
            }
        }
        return A;
    }
};

int main() {
    int A[6] = {1,2,3,5,2,3};
    CountingSort cs;
    printfSort(cs.countingSort(A, 6), 6);
    return 0;
}