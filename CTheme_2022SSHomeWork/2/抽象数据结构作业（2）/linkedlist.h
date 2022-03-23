#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include <stdlib.h>
#include <stdio.h>

#define MAXN 1024

static void * totPtr[MAXN];
static int totPtrn = 0;

// the elements of the Linked List
typedef struct MyChainLink{
    struct MyChainLink * next;
    int id, val;
} MyCL;

// the linked list
typedef struct MyLinkedList{
    MyCL * head, * tail;
} MyLL;

// be used to create a new element of the linked list
MyCL * CreateCL(int x);

// be used to link a new element at the end of the list
void InsertElement(MyLL * l, int x);

// be used to merge the linked list u and linked list v and put into base
void Merge(MyLL * base, MyLL * u, MyLL * v);

// be used to print all the elements
void PrintElements(MyLL * l);

// be used to free all the pointer
void freeAll();

#endif