#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "stack.h"

bool checkMatchingParentheses(char val1, char val2){
    if((val1=='(' && val2== ')')|| (val1=='{' && val2 =='}') || (val1 == '[' && val2 == ']'))
    return true;

    return false;
}

int matchingParentheses(Stack *s, char expr[]){

    for(int i=0; expr[i]!='\0'; i++){
        char ch = expr[i];
        
        if(ch != ')' && ch != '}' && ch != ']'){
            push(s,ch);
        }

        else{
            if(checkMatchingParentheses(s->a[s->top], ch)){
                pop(s);
            }
            else
            return 0;
        }
    }

    return (s->top ==-1);
}

int main(){
    Stack s;
    initStack(&s);

    char expr[MAX];
    printf("Enter an expression:- ");
    fgets(expr, MAX, stdin);
    expr[strcspn(expr, "\n")] = '\0';

    if(matchingParentheses(&s, expr))
        printf("The expression is valid.");
    else
        printf("The expression is invalid.");

    return 0;

}