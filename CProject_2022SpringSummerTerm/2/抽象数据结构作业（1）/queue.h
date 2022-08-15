#ifndef __QUEUE_USING_RING_BUFFER__
#define __QUEUE_USING_RING_BUFFER__

#include <stdio.h>
#include <stdlib.h>

#define MAXN 1024
#define MAXNQ 16

// set 1 when you want to print logs
static int PrintLog = 0;

static void * totPtr[MAXN];
static int totPtrn = 0;

/* 
 * the size of the queue is (tailPtr-headPtr+MAXNQ)%MAXNQ
 * the capacity of the queue is MAXNQ
 * be full when size is full
 */
typedef struct MyQueue{
    void * buffer[ MAXNQ+1 ];
    int id, headPtr, tailPtr;
} MyQ;

// be used to create a new MyQueue object
MyQ * NewQueue();

// be used to free all the memory of the queue ( including elements linked to it )
void FreeQueue(MyQ * q);

// be used to insert an object at the end of the queue
void Enqueue(MyQ * q, void * obj);

// be used to pop the object at the head of the queue and return the popped object
void * Dequeue(MyQ * q);

// be used to calculate the size of the queue
int SizeofQueue(MyQ * q);

// be used to free all the queue noted in the totPtr[]
void FreeAll();

// run while something went wrong
void Panic(const char * msg);

// be used to print logs
void Log(const char * msg, int x);

// be used to set PrintLog
void setPrintLog(int x);

#endif