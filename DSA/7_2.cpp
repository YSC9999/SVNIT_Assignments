#include<iostream>
#include <string>
using namespace std;

int evaluate_postfix(string exp){
    int stack[100];
    int Top = -1;
    for(int i=0; i<exp.length(); i++){
        if(isdigit(exp[i])){
            stack[++Top] = exp[i] - '0';
        }

        else{
            int b = stack[Top--];
            int a = stack[Top--];
            int val;
            switch(exp[i]){ 
                case '^':   val = a ^ b;
                            break;
                case '*':   val = a * b;
                            break;
                case '/':   val = a / b;
                            break;
                case '+':   val = a + b;
                            break;
                case '-':   val = a - b;
                            break;
            }
            stack[++Top] = val;
        }
    }
    return stack[Top];
}
 
int main(){
    string postfix;
    cout<<"Enter the postfix expression: ";
    cin>>postfix;
    cout<<"The value of the expression is "<<evaluate_postfix(postfix);

return 0;
}