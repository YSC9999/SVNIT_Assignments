#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h> 
#include <string.h>
#define MAX 100
typedef struct
{
    int arr[MAX];
    int top;
} ss;

void push(ss *s, int val)
{
    if (s->top == MAX - 1)
    {
        printf("ss Overflow\n");
        return;
    }
    s->arr[++s->top] = val;
}
int pop(ss *s)
{
    if (s->top == -1)
    {
        printf("ss Underflow\n");
        exit(1);
    }
    return s->arr[s->top--];
}

int evaluatePostfix(char *postfix)
{
    ss s;
    s.top = -1;
    char *token = strtok(postfix, " ");

    while (token)
    {
        if (isdigit(token[0]))
        {
            push(&s, atoi(token));
        }
        else
        {
            int val2 = pop(&s);
            int val1 = pop(&s);
            switch (token[0])
            {
            case '+':
                push(&s, val1 + val2);
                break;
            case '-':
                push(&s, val1 - val2);
                break;
            case '*':
                push(&s, val1 * val2);
                break;
            case '/':
                push(&s, val1 / val2);
                break;
            }
        }
        token = strtok(NULL, " ");
    }
    return pop(&s);
}

int main()
{
    char postfix[MAX];
    printf("Enter a postfix expression: ");
    fgets(postfix, MAX, stdin);
    postfix[strcspn(postfix, "\n")] = 0;
}