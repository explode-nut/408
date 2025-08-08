#include "./quick_sort.h"

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1, j = high;

    while (i <= j) {
        while (i < high && arr[i] <= pivot) i++;
        while (j > low && arr[j] > pivot) j--;
        if (i >= j) break;
        swap(&arr[i], &arr[j]);
    }
    swap(&arr[low], &arr[j]);

    return j;
}

void quick_sort(int arr[], int low, int high) {
    if (low >= high) {
        return;
    }

    int mid = partition(arr, low, high);
    quick_sort(arr, low, mid - 1);
    quick_sort(arr, mid + 1, high);
}