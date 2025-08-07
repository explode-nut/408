#include<stdio.h>
#include"./quick_sort.h"
#include"./utils.h"

int main() {
    int n;
    sort_arr* arrs = read_sort_data("./data/quick_sort_data", &n);

    printf("排序前:\n");
    print_sort_arr(arrs, n);

    free_sort_data(arrs);

    return 0;
}