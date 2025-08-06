#include<stdio.h>
#include "./quick_sort.h"
#include "../utils.h"

int main() {
    int** data = read_data("./quick_sort/data.txt");
    int n = read_arr_num("./quick_sort/data.txt");

    printf("排序前:\n");
    print_arr("./quick_sort/data.txt", data, n);

    free_data(data, n);
    return 0;
}