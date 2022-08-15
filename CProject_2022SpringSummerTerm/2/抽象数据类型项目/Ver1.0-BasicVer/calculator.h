#ifndef __CALCULATOR__
#define __CALCULATOR__

#include <stdlib.h>
#include <stdio.h>

#define MAXN 1024
#define MAXNS 1024

static int printLog = 0;

// a customized class of value
// it can be an integer or a character
typedef struct MyGeneralElement{
    int type;
    int num; // 0
    char ch; // 1
} Ele;

// a customized stack based on array
// the element of the stack is another customized struct
typedef struct MyStack{
    int top;
    Ele arrary[MAXN];
} Stack;

// be used to push a number into the stack
void InsertNum(Stack * sta, int x);

// be used to push a char into the stack
void InsertChar(Stack * sta, char ch);

// be used to change the infix expression string to the postfix expression
Stack * toReversePolishExpression(char * str);

// be used to calculate the answer of the expression by dealing postfix expression
int dealReversePolishExpression(Stack * cur);

// be used to set the state of logger
void setLogStates(int x);

#endif