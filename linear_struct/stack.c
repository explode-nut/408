#include "./stack.h"
#include <stdlib.h>
#include <stdio.h>

stack* creat() {
    stack* res = malloc(sizeof(stack));
    res->length = 0;
    return res;
}

void destroy(stack* s) {
    free(s);
}

int push(stack* s, int e) {
    if (s->length >= MAX_SIZE) {
        return 1;
    }
    s->element[s->length] = e;
    s->length++;
    return 0;
}

int pop(stack* s) {
    if (s->length <= 0) {
        return -1;
    }
    int res = s->element[s->length-1];
    s->length--;
    return res;
}

int peak(stack* s){
    return s->element[s->length-1];
}

void print_stack(stack* s) {
    int n = s->length;
    printf("栈顶->\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", s->element[i]);
    }
    printf("\n");
}
