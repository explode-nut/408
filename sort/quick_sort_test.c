#include<stdio.h>
#include"./quick_sort.h"
#include"./utils.h"

int main() {
    int n;
    sort_arr* arrs = read_sort_data("./data/quick_sort_data", &n);

    printf("排序前:\n");
    print_sort_arr(arrs, n);

    for (int i = 0; i < n; i++) {
        quick_sort(arrs[i].data, 0, arrs[i].length - 1);
    }

    printf("排序后:\n");
    print_sort_arr(arrs, n);

    free_sort_data(arrs);

    return 0;
}