#include "calculator.h"

// -------------------------------------------------------

// some utils interface that needn't to be expose

// change a number of string type to the one of integer type
int StrtoNum(char * num){
    int ret = 0;
    char * p = num;
    while(*p != '\0'){
        ret = ret * 10 + (*p) - '0';
        ++p;
    }
    return ret;
}

// calculate a binary arithmetic expressions like "u opt v"
int calExpr(int u, int v, char opt){
    if(opt == '+') return u+v;
    if(opt == '-') return u-v;
    if(opt == '*') return u*v;
    if(opt == '/') return u/v;
}

// ( */ +- ) 
// return x.priority >= y.priority
int cmpGeq(char x, char y){
    if(x == '*') return 1; 
    if(x == '/') return 1; 
    if(x == '+' && !cmpGeq(y, '*') ) return 1; 
    if(x == '-' && !cmpGeq(y, '*') ) return 1; 
    return 0;
}

// judge whether the option is valid or not
int isValidOption(char x){
    return x == '+' || x == '-' || x == '*' || x == '/';
}

// -------------------------------------------------------

// the definition of the interface explored in .h file

void InsertNum(Stack * sta, int x){
    if(printLog) printf("[INFO] insert Num \t[ %d ]\n", x);
    sta->arrary[ sta->top ].type = 0;
    sta->arrary[ sta->top ].num = x;
    ++sta->top;
}

void InsertChar(Stack * sta, char ch){
    if(printLog) printf("[INFO] insert Char \t[ %c ]\t[ %d ]\n", ch, ch);
    sta->arrary[ sta->top ].type = 1;
    sta->arrary[ sta->top ].ch = ch;
    ++sta->top;
}

Stack * toReversePolishExpression(char * str){
    Stack optStack, *ret = (Stack *)malloc(sizeof(Stack));
    optStack.top = 0, ret->top = 0;

    char * p = str;
    while(*p != '\0'){
        if(*p == '\0'){
            break;
        }else if('0' <= *p && *p <= '9'){
            char num[MAXNS] = {};
            int tail = -1;
            while( '0' <= *p && *p <= '9' ){
                num[ ++tail ] = *p;
                ++p;
            }
            int x = StrtoNum(num);
            InsertNum(ret, x);
        } else {
            if(*p == '(') {
                InsertChar(&optStack, '(');
                ++p;
            } else if(*p == ')') {
                while(optStack.arrary[ optStack.top-1 ].ch != '('){
                    InsertChar(ret, optStack.arrary[ optStack.top-1 ].ch);
                    --optStack.top;
                }
                --optStack.top;
                ++p;
            } else if( isValidOption(*p) ){
                while(optStack.top > 0 && cmpGeq(optStack.arrary[ optStack.top-1 ].ch, *p)){
                    InsertChar(ret, optStack.arrary[ optStack.top-1 ].ch);
                    --optStack.top;
                }
                InsertChar(&optStack, *p);
                ++p;
            } else {
                //TODO: invalid syntax
            }
        }
    }
    while(optStack.top > 0){
        InsertChar(ret, optStack.arrary[ optStack.top-1 ].ch);
        --optStack.top;
    }
    return ret;
}

int dealReversePolishExpression(Stack * cur){
    int stack[MAXN], top = 0, i;

    // deal the stack as an array
    for(i = 0;i < cur->top;++i){
        if(cur->arrary[i].type == 0){ // is number
            stack[ top++ ] = cur->arrary[i].num;
        } else {
            int u, v;
            v = stack[ --top ] , u = stack[ --top ];
            stack[ top++ ] = calExpr(u,v,cur->arrary[i].ch);
        }
    }
    return stack[0];
}

void setLogStates(int x){
    if(x) printf("[INFO] Will print logs\n");
    else printf("[INFO] Won't print logs\n");
    printLog = x;
}