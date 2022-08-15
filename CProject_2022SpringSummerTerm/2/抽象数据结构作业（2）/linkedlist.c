#include "linkedlist.h"

MyCL * CreateCL(int x){
    MyCL * cl;
    cl = (MyCL *)malloc(sizeof(MyCL));
    cl->val = x, cl->id = totPtrn, cl->next = NULL;
    totPtr[ totPtrn++ ] = cl;
    return cl;
}

void InsertElement(MyLL * l, int x){
    if(l->head == NULL){
        l->tail = l->head = CreateCL(x); 
    } else {
        l->tail->next = CreateCL(x);
        l->tail = l->tail->next;
    }
    return;
}

void Merge(MyLL * base, MyLL * u, MyLL * v){
    MyCL * lu, * lv;
    lu = u->head, lv = v->head;

    if(lu != NULL){
        base->head = lu, base->tail = lu;
        lu = lu->next;
    } else {
        base->head = lv, base->tail = v->tail;
        return; // u is empty so base is v
    }
    while(lu != NULL && lv != NULL){
        if(lu->val < lv->val){
            base->tail->next = lu, lu = lu->next;
        } else {
            base->tail->next = lv, lv = lv->next;
        }
        base->tail = base->tail->next;
        base->tail->next = NULL;
    }
    if(lu != NULL){
        base->tail->next = lu;
    } else {
        base->tail->next = lv;
    }
    return;
}

void PrintElements(MyLL * l){
    MyCL * p = l->head;
    while(p != NULL){
        printf("%d ", p->val);
        p = p->next;
    }
    printf("-1\n");
}

void freeAll(){
    int _;
    for(_ = 0;_ < totPtrn;++_){
        free(totPtr[_]);
    }
    return;
}