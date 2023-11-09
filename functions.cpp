#include <iostream>
#include "process.h"
#include "queue.h"
#include "functions.h"
#include <string.h>
using namespace std;

extern Queue entry;
extern Queue ready;
extern Queue running;
extern Queue blocked;
extern Queue exit_st;

void Add(string &name)
{
    ProcessPtr p = new Process;
    p->proc_name = name;
    p->state = "New";
    cout << "Process Name: " << p->proc_name << endl << "State: " << p->state << endl;
    entry.Enqueue(p);

}
void Step() {
    // Remove all processes that are in the exit state.
    while (exit_st.IsEmpty() != true) {
        ProcessPtr p = exit_st.Dequeue();
        cout << "process " << "\"" << p->proc_name << "\"" << "is banished to the void." << endl; 
    }
    // Advance at most 1 process in the New State into the ready state.
    if (entry.Queue_Size() >= 1) {
        ProcessPtr q = entry.Dequeue();
        q->state = "Ready";
        ready.Enqueue(q);
    }
}