#include <stdio.h>
#define SIZE 5

int stack[SIZE], top = -1;

void push(int x) {
    if(top == SIZE - 1)
        printf("Stack Overflow\n");
    else {
        stack[++top] = x;
        printf("Pushed %d\n", x);
    }
}

void pop() {
    if(top == -1)
        printf("Stack Underflow\n");
    else
        printf("Popped %d\n", stack[top--]);
}

int main() {
    push(10);
    push(20);
    pop();
    push(30);
    pop();
    return 0;
}

