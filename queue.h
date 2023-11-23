#include <iostream>
#include "process.h"
using namespace std;
#ifndef QUEUE_H
#define QUEUE_H


class Queue {
    private:
        struct QueueNode {
            ProcessPtr proc;
            QueueNode* next;
        };
        typedef QueueNode* QNodePtr;
        QNodePtr head;
    public:
        Queue() { head = NULL; }
        ~Queue();
        void Enqueue(ProcessPtr p);
        //ProcessPtr Dequeue();
        ProcessPtr Dequeue();
        bool IsEmpty();
        void PrintQueue();
        int Queue_Size();
        bool Search(string s);
        ProcessPtr SearchRetProc(string s);
        void PrintAllProcs();

};
#endif // QUEUE_H