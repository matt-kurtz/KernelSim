#include <iostream>
#include "process.h"
using namespace std;

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
        void Enqueue(ProcessPtr p);
        ProcessPtr Dequeue();
        bool IsEmpty();
        void PrintQueue();
};
