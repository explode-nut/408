#define MAX_LENGTH 15
typedef struct {
    int length; // 该序列的长度
    int data[MAX_LENGTH]; // 该序列的数据，最大20个
} sort_arr;

// file_path: 文件路径
// n: 待排序序列数量
sort_arr* read_sort_data(char* file_path, int* n);
// 释放read_sort_data分配的内存
void free_sort_data(sort_arr* i);
void print_sort_arr(sort_arr* arrs, int n);
