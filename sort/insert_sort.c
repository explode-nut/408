#include"./insert_sort.h"

void insert_sort(int arr[], int low, int high) {
    int n = low;
    while (n <= high) {
        for (int i = low + 1; i <= high; i++) {
            for (int j = i; j > low; j--) {
                if (arr[j] < arr[j-1]) {
                    int t = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = t;
                } else {
                    break;
                }
            }
        }
        n++;
    }
}