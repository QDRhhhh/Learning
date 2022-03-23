#include "queue.h"

#define next(x) ((x) == MAXNQ ? 0 : (x)+1)

MyQ * NewQueue(){
    
    if(totPtrn == MAXN)
        Panic("Cna't create new queue for there is no rest memory!");

    MyQ * ret = (void *)malloc(sizeof(MyQ));
    ret->id = totPtrn;
    totPtr[ totPtrn++ ] = (void *)ret;
    ret->headPtr = ret->tailPtr = 0;
    return ret;
}

void FreeQueue(MyQ * q){
    totPtr[ q->id ] = NULL;
    free(q);
}

void Enqueue(MyQ * q, void * obj){

    if(SizeofQueue(q) == MAXNQ) 
        Panic("Can't insert while the queue is full!");
    
    q->buffer[ q->tailPtr ] = obj;
    q->tailPtr = next(q->tailPtr);

    Log("insert ", *(int*)obj);
    Log("   pos ", q->tailPtr);
    Log("  size ", SizeofQueue(q));

    return;
}

void * Dequeue(MyQ * q){
    
    if(SizeofQueue(q) == 0) 
        Panic("Can't pop while the queue is empty!");
    void * ret = q->buffer[ q->headPtr ];
    q->headPtr = next( q->headPtr );

    Log(" pop ", *(int*)ret);
    Log(" pos ", q->headPtr);
    Log("size ", SizeofQueue(q));

    return ret;
}

int SizeofQueue(MyQ * q){
    return (q->tailPtr - q->headPtr + MAXNQ+1)%(MAXNQ+1);
}

void FreeAll(){
    int i = 0;
    for(;i < totPtrn;++i){
        if(totPtr[i] != NULL) // maybe useless
            FreeQueue( (void *)(totPtr[i]) );
    }
}

void Panic(const char * msg){
    printf("[FATAL] %s\n", msg);
    FreeAll();
    exit(0);
}

void Log(const char * msg, int x){
    if(PrintLog)
        printf("\t [INFO] %s %d\n", msg, x);
}

void setPrintLog(int x){
    PrintLog = x; 
}