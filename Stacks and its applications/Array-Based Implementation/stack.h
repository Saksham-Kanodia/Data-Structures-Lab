#ifndef STACK_H
#define STACK_H
#include <stdio.h>

#define MAX 100
typedef struct{
    char a[MAX];
    int top;
}Stack;

void initStack(Stack *s){
    s->top =-1;
}

void push(Stack *s, char ele){
    if(s->top == MAX-1){
        printf("Stack is Full");
        return;
    }

    s->a[++s->top] =ele;
}

void pop(Stack *s){
    if(s->top == -1){
        printf("Stack is Empty");
        return;
    }

    s->top--;
}

#endif