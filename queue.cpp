#include <iostream>
#include <string.h>
#include "queue.h"
#include "process.h"

void Queue::Enqueue(ProcessPtr p) {
    QNodePtr q = new QueueNode;
    q->proc = p; // this is probably wrong
    q->next = NULL;

    if (head == NULL) {
        head = q;
    }
    else {
        q->next = head;
        head = q;
    }
}

ProcessPtr Queue::Dequeue() {
    QNodePtr q = head;
    
    if ( head == NULL ) {
        cout << "Queue is empty" << endl;
    }
    else {
        head = head->next;
        return (q->proc);
    }
}

bool Queue::IsEmpty() {
    return (head == NULL);
}

void Queue::PrintQueue() {
    QNodePtr q = head;
    ProcessPtr p = (q->proc);

    if (q == NULL) {
        cout << "Empty Queue" << endl;
    }

    while (q != NULL) {
        cout << p->proc_name << endl;
        q = q->next;
        p = (q->proc);
    }
    cout << "End of List" << endl;
}
