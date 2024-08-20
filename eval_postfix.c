#include<stdio.h>
#include<string.h>
#define MAXSTACK 100
#define MAXEXP 100
int stack[MAXSTACK];
char exp[MAXEXP];
int top = -1;
char t;
int eval();
void push (int x){
    stack[++top] = x;
}
int pop(){
    return stack[top--];
}
int eval(){
    char t ;
    char symbol;
    int op1,op2;
    int n= 0;
    t = exp[n++];
    while(t!='\0'){
        if(t!='+' && t!='-' && t!='*' && t!='/' && t!='%'){
            push(t-'0');
        }
        else{
            op2 = pop();
            op1 = pop();
            switch(t){
                case '+' : push(op1 + op2); break;
                case '-' : push(op1 - op2); break ;
                case '*' : push(op1 * op2); break ;
                case '/' : push(op1 / op2); break ;
                case '%' : push(op1 % op2); break ;
            }
        }
        t = exp[n++];
    }
    return pop();
}
int main(){
    printf("enter the expression : \n");
    gets(exp);
    printf("Result of evaluation: %d\n", eval());
    return 0;
}
