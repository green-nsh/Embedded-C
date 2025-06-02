#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int ElemType;
typedef struct
{
    ElemType* data;
    int       top;
} Stack;

// 1 initialize Stack
Stack* initStack()
{
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->data  = (ElemType*)malloc(sizeof(Stack) * MAXSIZE);
    s->top   = -1;

    return s;
}

// 2 is empty
bool isEmpty(Stack* s)
{
    if (s->top == -1) {
        printf("stack is empty\n");
        return true;
    }
    printf("stack is not empty\n");
    return false;
}

// 3 push element
bool push(Stack* s, ElemType element)
{
    if (s->top == MAXSIZE - 1) {
        printf("the stack is full\n");
        return false;
    }
    s->top++;
    s->data[s->top] = element;

    return true;
}

// 4 pop element
bool pop(Stack* s, ElemType* element)
{
    if (s->top == -1) {
        printf("The stack is empty\n");
        return false;
    }
    *element = s->data[s->top];
    s->top--;
    return true;
}

// 5 get top element
ElemType* getTop(Stack* s)
{
    if (s->top == -1) {
        printf("The stack is empty\n");
        return false;
    }
    return &s->data[s->top];
}

int main()
{
    Stack* stack = initStack();
    isEmpty(stack);

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);

    printf("top: %d\n", *getTop(stack));

    ElemType e;
    pop(stack, &e);
    printf("pop: %d\n", e);

    pop(stack, &e);
    printf("pop: %d\n", e);

    pop(stack, &e);
    printf("pop: %d\n", e);

    pop(stack, &e);
    printf("pop: %d\n", e);

    pop(stack, &e);
    printf("pop: %d\n", e);
    return 0;
}