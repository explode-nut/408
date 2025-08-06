#include<stdio.h>
#include<stdlib.h>

int* read_arr_length(char* file_path);

int** read_data(char* file_path) {
    int n = read_arr_num(file_path);
    int* arr_length = read_arr_length(file_path);
    FILE* file = fopen(file_path, "r");

    // 分配内存
    int** res = malloc(n * sizeof(int*));
    if (res == NULL) {
        fprintf(stderr, "分配指针数组失败\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        res[i] = (int*)malloc(arr_length[i] * sizeof(int));
        if (res[i] == NULL) {
            fprintf(stderr, "分配第%d行内存失败\n", i);
            // 清理已分配的内存
            for (int j = 0; j < arr_length[i]; j++) {
                free(res[j]);
            }
            free(res);
            return 1;
        }
    }

    // 把前面的读完
    int t;
    fscanf(file, "%d", &t);
    for (int i = 0; i < n; i++) fscanf(file, "%d", &t);
    // 读取n行排序序列
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < arr_length[i]; j++) {
            fscanf(file, "%d", &res[i][j]);
        }
    }

    fclose(file);
    free(arr_length);
    return res;
}

// 读取排序序列个数n
int read_arr_num(char* file_path) {
    FILE* file = fopen(file_path, "r");
    if (!file) return -1;

    int num;
    if (fscanf(file, "%d", &num) != 1) {
        fclose(file);
        fprintf(stderr, "读取n失败\n");
        return NULL;
    }

    fclose(file);
    return num;
}

// 释放n行data内存
void free_data(int** data, int n) {
    // 遍历并释放每一行
    for (int i = 0; i < n; i++) {
        free(data[i]);
    }
    // 释放指针数组本身
    free(data);
}

// 输出排序序列
void print_arr(char* file_path, int** data, int n) {
    int* arr_length = read_arr_length(file_path);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < arr_length[i]; j++) {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }
    free(arr_length);
}



// 帮助函数：
// 读取n个排序序列的长度
int* read_arr_length(char* file_path) {
    FILE* file = fopen(file_path, "r");
    if (file == NULL) {
        perror("无法打开文件");
        return NULL;
    }

    int n = read_arr_num(file_path);
    if (n == NULL) {
        fclose(file);
        return NULL;
    }

    int* res = malloc(sizeof(int) * n);
    if (res == NULL) {
        fprintf(stderr, "内存分配失败\n");
        fclose(file);
        return NULL;
    }

    // 把前面的读完
    int t;
    fscanf(file, "%d", &t);
    for (int i = 0; i < n; i++) {
        if (fscanf(file, "%d", &res[i]) != 1) {
            fprintf(stderr, "读取第 %d 个整数失败\n", i);
            free(res);
            fclose(file);
            return NULL;
        }
    }

    fclose(file);
    return res;
}