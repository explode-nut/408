#include"./merge_sort.h"
void merge_sort(int arr[], int low, int high) {
    if (low == high) {
        return;
    }

    int mid = (low + high) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}
void merge(int arr[], int low, int mid, int high) {
    int n = high - low + 1; // arr的n元素个数
    int tmp[n];
    for (int i = 0; i < n; i++) {
        tmp[i] = arr[low + i];
    }

    // 使用从0开始的下标不容易出错
    int i = 0; // 对应low 
    int j = mid - low + 1; // 对应mid+1
    for (int t = low; t <= high; t++) {
        // 先判断是否有一侧结束
        if (i > mid - low) {
            arr[t] = tmp[j++];
        } else if (j >= n) {
            arr[t] = tmp[i++];
        } else if (tmp[i] <= tmp[j]) {
            arr[t] = tmp[i++];
        } else if (tmp[i] > tmp[j]) {
            arr[t] = tmp[j++];
        }
    }

}