#ifndef __CALCULATOR__
#define __CALCULATOR__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "myFunction.h"

#define MAXN 1024
#define MAXNS 1024

static int printLog = 0;

// a customized class of value
// it can be an number or a character
typedef struct MyGeneralElement{
    // TODO: maybe 'ch' can be set as negative if 'negative 
    // number is seen as minus and a positive number
    int type;
    double num; // 0
    char ch; // 1
} Ele;

// a customized stack based on array (preferably pointers)
// the element of the stack is another customized struct
typedef struct MyStack{
    int top;
    Ele arrary[MAXN];
} Stack;

// // be used to push a number into the stack
// void InsertNum(Stack * sta, double x);

// // be used to push a char into the stack
// void InsertChar(Stack * sta, char ch);

// // be used to change the infix expression string to the postfix expression
// Stack * toReversePolishExpression(char * str);

// // be used to calculate the answer of the expression by dealing postfix expression
// double dealReversePolishExpression(Stack * cur);

// be used to calculate the answer of the expression
double calExpr(char * expr);

// be used to set the state of logger
// TODO: it's more elegant to make 'logger' a single library 
void setLogStates(int x);

#endif