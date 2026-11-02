#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

typedef struct{
    char a[MAX];
    int top;
}Stack;

void initStack(Stack *s){
    s->top = -1;
}

void push(Stack *s, char ch){
    if(s->top==MAX-1){
        printf("Stack is Empty");
        return;
    }

    s->a[++s->top]=ch;
}

char pop(Stack *s){
    if(s->top==-1){
        printf("Stack is Empty.");
        return '\0';
    }

    return s->a[s->top--];
}

bool checkPalindrome(Stack* org, char expr[]){

    char reverse[MAX]; int k=0;

    for(int i=0; expr[i]!='\0'; i++){
        push(org, expr[i]);
    }

    while(org->top!=-1){
        reverse[k++]=pop(org);
    }

    reverse[k]='\0';

    return strcmp(reverse, expr)==0;
}

int main(){
    
    Stack org;
    initStack(&org);

    char expr[MAX];
    printf("Enter an expression:- ");
    fgets(expr, MAX, stdin);
    expr[strcspn(expr, "\n")]= '\0';

    if(checkPalindrome(&org, expr)){
        printf("Palindrome");
    }
    else{
        printf("Not a palindrome");
    }

    return 0;
    
}