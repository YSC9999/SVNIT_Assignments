#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
typedef struct{
    char arr[MAX];
    int top;
} ss;
void push(ss *s, char ch){
    if (s->top == MAX - 1)
    {
        printf("ss Overflow\n");
        return;
    }
    s->arr[++s->top] = ch;
}
char pop(ss *s){
    if (s->top == -1)
    {
        printf("ss Underflow\n");
        return -1;
    }
    return s->arr[s->top--];
}
char peek(ss *s){
    return s->arr[s->top];
}
int precedence(char op){
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}
int isOperator(char ch){
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}
void infixToPostfix(char *infix, char *postfix){
    ss s;
    s.top = -1;
    int i = 0, j = 0;
    while (infix[i] != '\0'){
        char ch = infix[i];
        if (isalnum(ch)){
            postfix[j++] = ch;
        }
        else if (ch == '('){
            push(&s, ch);
        }
        else if (ch == ')'){
            while (s.top != -1 && peek(&s) != '('){
                postfix[j++] = pop(&s);
            }
            pop(&s); // Remove '('
        }
        else if (isOperator(ch)){
            while (s.top != -1 && precedence(peek(&s)) >= precedence(ch)){
                postfix[j++] = pop(&s);
            }
            push(&s, ch);
        }
        i++;
    }
    while (s.top != -1){
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}
int main(){
    char infix[MAX], postfix[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);
}