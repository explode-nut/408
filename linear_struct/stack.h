#define MAX_SIZE 20
typedef struct {
    int element[MAX_SIZE];
    int length;
} stack;

stack* creat();
void destroy(stack* s);
int push(stack* s, int e);
int pop(stack* s);
int peak(stack* s); // 返回栈顶元素
void print_stack(stack* s);
