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
    if (head == NULL) {
        cout << "Queue is empty" << endl;
        return NULL;
    }
    else if (head->next == NULL) {
        ProcessPtr dqProc = head->proc;
        head = NULL;
        return dqProc;
    }
    else {
        QNodePtr prev = NULL;
        QNodePtr current = head;
        while (current->next != NULL) {
            prev = current;
            current = current->next;
        }
        prev->next = NULL;
        ProcessPtr dqProc = current->proc;
        current = NULL;
        delete current;
        return dqProc;
    }
}

bool Queue::IsEmpty() {
    return (head == NULL);
}

void Queue::PrintQueue() {
    QNodePtr q = head;
    while (q != NULL) {
        ProcessPtr p = q->proc;
        cout << p->proc_name << endl;
        q = q->next;
    }
    cout << "End of List" << endl;
}

int Queue::Queue_Size() {
    int n = 0;
    QNodePtr p = head;
    if (head == NULL) {
        return n;
    }
    else {
        while (p != NULL) {
            n++;
            p = p->next;
        }
    }
    return n;
}
// returns true if string is in proc_name for processes of a queue
bool Queue::Search(string s) {
    QNodePtr q = head;
    if (head == NULL) {
        return false; // The queue is empty, so the string cannot be found.
    } else {
        while (q != NULL) {
            ProcessPtr p = q->proc;
            if (p->proc_name == s) {
                return true;
            }
            q = q->next;
        }
        return false; // The string was not found in any process names.
    }
}