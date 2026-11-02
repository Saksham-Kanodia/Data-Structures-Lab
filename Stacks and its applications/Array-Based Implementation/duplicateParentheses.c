#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

int isDuplicate(Stack *s, char expr[]){

    for(int i=0; expr[i]!='\0'; i++){
        char ch = expr[i];

        if(ch != ')'){
            push(s,ch);
        }

        else{
            if(s->a[s->top]=='(') return 1;//Duplicate

            else{
                while(s->a[s->top]!='('){
                    pop(s);
                }
            }
            pop(s);
        }
    }

    while(s->top != -1){
    if(s->a[s->top] == '(')
        return 1;

    pop(s);
}

return 0;
}

int main(){

    Stack s;
    initStack(&s);

    char expr[MAX];
    printf("Enter an expression:- ");
    fgets(expr,MAX,stdin);
    expr[strcspn(expr,"\n")] = '\0';

    if(isDuplicate(&s,expr))
    printf("Duplicate parentheses found");

    else{
        printf("No duplicate parentheses");
    }

    return 0;
}
