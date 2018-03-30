/*
 *
对于一个int数组，请编写一个排序算法，对数组元素排序。
给定一个int数组A及数组的大小n，请返回排序后的数组。
测试样例：
[1,2,3,5,2,3],6
[1,2,2,3,3,5]

 */
#include <iostream>

using namespace std;

void printfSort(int *A, int n) {
    for (int i = 0; i < n - 1; i++)
        cout << A[i] << ' ';
    cout << A[n - 1] << endl;
}

//冒泡排序
class BubbleSort {
public:
    int *buttleSort(int *A, int n) {
        // write code here
        for (int i = n - 1; i >= 1; i--) {
            for (int j = 0; j < i; j++) {
                if (A[j] > A[j + 1]) {
                    int t = A[j];
                    A[j] = A[j + 1];
                    A[j + 1] = t;
                }
            }
        }
        return A;
    }
};

//选择排序
class SelectionSort {
public:
    int *selectionSort(int *A, int n) {
        // write code here
        for (int i = 0; i < n - 1; i++) {
            int min = i;
            for (int j = i + 1; j < n; j++) {
                if (A[j] < A[min])min = j;
            }
            int t = A[i];
            A[i] = A[min];
            A[min] = t;
        }
        return A;
    }
};

//插入排序
class InsertionSort {
public:
    int *insertionSort(int *A, int n) {
        // write code here
        for (int i = 1; i < n; i++) {
            int k = A[i];
            int j;
            for (j = i - 1; j >= 0; j--) {
                if (A[j] >= k)A[j + 1] = A[j];
                else break;
            }
            A[j + 1] = k;
        }
        return A;
    }
};

//归并排序
class MergeSort {
public:
    int *mergeSort(int *A, int n) {
        // write code here
        mergeSort1(A, 0, n - 1);
        return A;
    }

    void Merge(int *A, int low, int mid, int high) {
        int i = low;
        int j = mid + 1;
        int k = 0;
        int *B = new int[high - low + 1];

        while (i <= mid && j <= high) {
            if (A[i] <= A[j]) {
                B[k++] = A[i++];
            } else {
                B[k++] = A[j++];
            }
        }
        while (i <= mid) {
            B[k++] = A[i++];
        }
        while (j <= high) {
            B[k++] = A[j++];
        }
        for (k = 0, i = low; i <= high; i++, k++) {
            A[i] = B[k];
        }
    }

    void mergeSort1(int *A, int low, int high) {
        if (low >= high)return;
        int mid = (low + high) / 2;
        mergeSort1(A, low, mid);
        mergeSort1(A, mid + 1, high);
        Merge(A, low, mid, high);
    }
};

//快速排序
class QuickSort {
public:
    int *quickSort(int *A, int n) {
        // write code here
        qSort(A, 0, n - 1);
        return A;
    }

    int partion(int *A, int low, int high) {
        int div = low - 1;
        int t;
        for (int i = low; i < high; i++) {
            if (A[i] <= A[high]) {
                t = A[div + 1];
                A[div + 1] = A[i];
                A[i] = t;
                div++;
            }
        }
        t = A[div + 1];
        A[div + 1] = A[high];
        A[high] = t;
        return div + 1;
    }

    void qSort(int *A, int low, int high) {
        if (low >= high)return;
        int p = partion(A, low, high);
        qSort(A, low, p - 1);
        qSort(A, p + 1, high);
    }
};

//希尔排序
class ShellSort {
public:
    int *shellSort(int *A, int n) {
        // write code here
        int gap = n / 2;
        while (gap > 0) {
            for (int i = gap; i < n; i++) {
                for (int j = i - gap; j >= 0; j -= gap) {
                    if (A[j] > A[j + gap]) {
                        int t = A[j];
                        A[j] = A[j + gap];
                        A[j + gap] = t;
                    }
                }
            }
            gap = gap / 2;
        }
        return A;
    }
};

int main() {
    int A[13] = {54, 35, 48, 36, 27, 12, 44, 44, 8, 14, 26, 17, 28};
    BubbleSort bs;
    SelectionSort ss;
    InsertionSort is;
    MergeSort ms;
    QuickSort qs;
    ShellSort Ss;
//    printfSort(bs.buttleSort(A, 13), 13);
//    printfSort(ss.selectionSort(A, 13), 13);
//    printfSort(is.insertionSort(A, 13), 13);
//    printfSort(ms.mergeSort(A, 13), 13);
//    printfSort(qs.quickSort(A, 13), 13);
    printfSort(Ss.shellSort(A, 13), 13);
    return 0;
}