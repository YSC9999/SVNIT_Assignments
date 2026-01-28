#include<iostream>
using namespace std;
int precedence(char op){
    switch(op){
        case '^': return 3;
        case '*': 
        case '/': return 2;
        case '+': 
        case '-': return 1;
        default:  return 0;
    }
}
string infix_postfix(string infix){
    char stack[100];
    int Top = -1;
    string postfix;
    for(int i=0; i<infix.length(); i++){
        if(infix[i] == ' ') continue;
        if(isalpha(infix[i]) || isdigit(infix[i])){
            postfix += infix[i];
        }
        else if(infix[i] == '(')
            stack[++Top] = infix[i];

        else if(infix[i] == ')'){
            while(stack[Top] != '(')
                postfix += stack[Top--];
            Top -= 1;
        }
        else{
            if(Top == -1){
                stack[++Top] = infix[i];
                continue;
            }
            if(precedence(infix[i]) > precedence(stack[Top]))
                stack[++Top] = infix[i];

            else{
                while(Top >= 0 && stack[Top] != '(' && precedence(stack[Top]) >= precedence(infix[i])) {
                  postfix += stack[Top--];
              }
                stack[++Top] = infix[i];
            }
        }
    }
    while(Top >= 0) {
        if(stack[Top] != '(') {
            postfix += stack[Top];
        }
        Top--;
    }
    return postfix;
}
int main(){
    string infix;
    cout<< "Enter the infix expression: ";
    getline(cin, infix);
    cout<< "\nThe postfix expression is:\n"<< infix_postfix(infix);
return 0;
}