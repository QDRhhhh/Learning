#include "calculator.h"

// -------------------------------------------------------
// some utils interface that needn't to be expose

// change a number(string) to the one with double type
// TODO: There are ready-made libraries.
double StrtoNum(char * num){
    double ret = 0;
    int offset = 0;
    char * p = num;
    while(*p != '\0'){
        if(*p == '.'){ 
            offset = 1;
            ++p;
            continue;
        }
        ret = ret * 10 + (*p) - '0';
        if(offset) offset *= 10;
        ++p;
    }
    if(!offset) offset = 1;
    return ret / offset;
}

// calculate a short binary arithmetic expressions like "u opt v"
double calShortExpr(double u, double v, char opt){
    if(printLog) printf("[INFO] calculating \t[%lf %c %lf]\n",u,opt,v);
    if(opt == '+') return u+v;
    if(opt == '-') return u-v;
    if(opt == '*') return u*v;
    if(opt == '/') return u/v;
    if(opt == '^') return _pow(u,v);
    // it's supported to add new binary operator, but remember update
    // both `calShortExpr()` & `cmpGeq()` & 'isValidOption()'
}

// ( */ +- ) 
// return x.priority >= y.priority
int cmpGeq(char x, char y){
    if(x == '^') return 1;
    if(y == '^') return 0;
    if(x == '*') return 1; 
    if(x == '/') return 1; 
    if(x == '+' && !cmpGeq(y, '*') ) return 1; 
    if(x == '-' && !cmpGeq(y, '*') ) return 1; 
    return 0;
}

// judge whether the option is valid or not
int isValidOption(char x){
    return x == '+' || x == '-' || x == '*' || x == '/' || x == '^';
}

// judge whether the func exists
// a function is like funcName(arg) (well, multiple args is not support here)
// and return the func id
int isValidFunc(char * p){
    char *pp = p;
    while(*p != '\0' && *p != '(') ++p;

    int len = 0;
    char subStr[MAXNS];
    for(;pp != p;++pp) subStr[ len++ ] = *pp;
    subStr[len] = '\0';

    // Not elegant.
    if(printLog) printf("[INFO] finding func \t[%s]\n", subStr);

    return isFuncExist(subStr);
}

// find the next '(...)'
char * findPair(char * p){
    int del = 0, hasPair = 0;
    while(*p != '\0'){
        if(*p == '(') ++del, hasPair = 1;
        else if(*p == ')') --del;
        if(del == 0 && hasPair) return p;
        ++p;
    }

    // Not elegant.
    if(printLog) printf("[FATAL] Parentheses do not match!");
    exit(0);
}

// be used to push a number into the stack
void InsertNum(Stack * sta, double x){
    if(printLog) printf("[INFO] insert Num \t[ %lf ] at \t[ %d ]\n", x, sta->top);
    sta->arrary[ sta->top ].type = 0;
    sta->arrary[ sta->top ].num = x;
    ++sta->top;
}

// be used to push a char into the stack
void InsertChar(Stack * sta, char ch){
    if(printLog) printf("[INFO] insert Char \t[ %c ]\t[ %d ] at \t[ %d ]\n", ch, ch, sta->top);
    sta->arrary[ sta->top ].type = 1;
    sta->arrary[ sta->top ].ch = ch;
    ++sta->top;
}

// be used to change the infix expression string to the postfix expression
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
            while( ('0' <= *p && *p <= '9') || *p == '.' ){
                num[ ++tail ] = *p;
                ++p;
            }
            double x = StrtoNum(num);
            InsertNum(ret, x);
        } else {
            if( isValidOption(*p) ){
                while(optStack.top > 0 && cmpGeq(optStack.arrary[ optStack.top-1 ].ch, *p)){
                    InsertChar(ret, optStack.arrary[ optStack.top-1 ].ch);
                    --optStack.top;
                }
                InsertChar(&optStack, *p);
                ++p;
            } else if( *p == '(' ) {
                char * pp = p+1;
                p = findPair(p);                
                int len = 0;

                char subStr[MAXNS];
                for(;pp != p;++pp) subStr[ len++ ] = *pp;
                subStr[len] = '\0';
                
                double ans = calExpr(subStr);
                
                InsertNum(ret, ans);
                ++p;
            } else if( 1 ) {
                int fid = isValidFunc(p);
                if( fid == -1 ) goto __Invalid_Sign_exitLable__;
                while(*p != '(' && *p != '\0') ++p;
                char * pp = p+1;
                p = findPair(p);
                int len = 0;

                char subStr[MAXNS];
                for(;pp != p;++pp) subStr[ len++ ] = *pp;
                subStr[len] = '\0';

                double ans = calExpr(subStr);
                InsertNum(ret, useFuncById(fid, ans));
                ++p;
            } else {
                __Invalid_Sign_exitLable__: 
                // Not elegant
                printf("[FATAL] Invalid Syntax!\n");
                exit(0);
            }
        }
    }
    while(optStack.top > 0){
        InsertChar(ret, optStack.arrary[ optStack.top-1 ].ch);
        --optStack.top;
    }
    return ret;
}

// be used to calculate the answer of the expression by dealing postfix expression
double dealReversePolishExpression(Stack * cur){
    double stack[MAXN];
    int top = 0, i;

    // deal the stack as an array
    for(i = 0;i < cur->top;++i){
        if(cur->arrary[i].type == 0){ // is number
            stack[ top++ ] = cur->arrary[i].num;
        } else {
            double u, v;
            v = stack[ --top ] , u = stack[ --top ];
            stack[ top++ ] = calShortExpr(u,v,cur->arrary[i].ch);
        }
    }

    return stack[0];
}


// -------------------------------------------------------
// the definition of the interface explored in .h file

double calExpr(char * expr){
    initMyFunc();
    Stack * subRPE = toReversePolishExpression(expr);
    double ret = dealReversePolishExpression(subRPE);
    free(subRPE);
    return ret;
}

void setLogStates(int x){
    if(x) printf("[INFO] Will print logs\n");
    else printf("[INFO] Won't print logs\n");
    printLog = x;
}