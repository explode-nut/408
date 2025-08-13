#include "./stack.h"
#include <stdio.h>

int test_push();
int test_pop();
int test_peak();

int main() {
    int r;
    int count = 0;
    r = test_push();
    if (r) count++;
    r = test_pop();
    if (r) count++;
    r = test_peak();
    if (r) count++;
    if (count == 0) {
        printf("------All test passed!------\n");
    } else {
        printf("test failed! %d/3 \n", count);
    }
    
    return 0;
}

int test_push() {
    printf("test push...\n");
    stack* s = creat();
    int t[] = {3, 6, 9, 12, 3};
    push(s, 3);
    push(s, 6);
    push(s, 9);
    push(s, 12);
    push(s, 3);

    for (int i = 0; i < s->length; i++) {
        if (s->element[i] != t[i]) {
            printf("test failed!\n");
            return 1;
        }
    }

    for (int i = 0; i < MAX_SIZE - 5; i++) {
        push(s, 3);
    }
    int r = push(s, 3);
    if (!r) {
        printf("test failed!\n");
        printf("栈已满但是仍然被插入!\n");
        return 1;
    }

    printf("test passed!\n");
    destroy(s);
    return 0;
}

int test_pop() {
    printf("test pop...\n");
    stack* s = creat();
    int r;
    r = pop(s);
    if (r != -1) {
        printf("test failed!\n");
        return 1;
    }

    push(s, 3);
    push(s, 6);
    push(s, 9);
    push(s, 12);
    push(s, 3);

    r = pop(s);
    r = pop(s);
    r = pop(s);
    if (r != 9) {
        printf("test failed!\n");
        printf("expected 9 but got %d\n", r);
        return 1;
    }

    printf("test passed!\n");
    destroy(s);
    return 0;
}

int test_peak() {
    printf("test peak...\n");
    stack* s = creat();
    push(s, 3);
    push(s, 6);
    push(s, 9);
    push(s, 12);
    
    if (peak(s) != 12) {
        printf("test failed!\n");
        return 1;
    }

    printf("test passed!\n");
    destroy(s);
    return 0;
}