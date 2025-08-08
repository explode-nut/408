#include<stdio.h>
#include<stdlib.h>
#include"./utils.h"

sort_arr* read_sort_data(char* file_path, int* n) {
    FILE* file;
    sort_arr* res;
    if ((file = fopen(file_path, "r")) == NULL) {
        printf("找不到指定文件。\n");
        return NULL;
    }

    if (fscanf(file, "%d", n) == EOF) {
        printf("读取待排序序列数n失败。\n");
        fclose(file);
        return NULL;
    }

    if ((res = malloc(sizeof(sort_arr) * (*n))) == NULL) {
        printf("分配sort_arr数组内存失败。\n");
        fclose(file);
        return NULL;
    }

    for (int i = 0; i < *n; i++) {
        if (fscanf(file, "%d", &res[i].length) == EOF) {
            printf("读取待排序序列长度失败。\n");
            fclose(file);
            free(res);
            return NULL;
        }
        if (res[i].length > MAX_LENGTH) {
            printf("测试数据有误，第%d个序列长度不合法。\n", i + 1);
            fclose(file);
            free(res);
            return NULL;
        }
    }

    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < res[i].length; j++) {
            if (fscanf(file, "%d", &res[i].data[j]) == EOF) {
                printf("读取待排序序列失败。\n");
                fclose(file);
                free(res);
                return NULL;
            }
        }
    }

    fclose(file);
    return res;
}

void free_sort_data(sort_arr* i) {
    free(i);
}

void print_sort_arr(sort_arr* arrs, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < arrs[i].length; j++) {
            printf("%d ", arrs[i].data[j]);
        }
        printf("\n");
    }
}
