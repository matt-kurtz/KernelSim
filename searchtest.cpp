#include <iostream>
#include "process.h"
#include "queue.h"
using namespace std;

int main() {
    Queue* test = new Queue();
    ProcessPtr p = new Process;
    p->proc_name = "P1";
    p->state = "Ready";
    test->Enqueue(*p);
    p = NULL;
    p = new Process;
    p->proc_name = "P2";
    p->state = "Running";
    test->Enqueue(*p);
    p = NULL;
    ProcessPtr yeet = test->SearchRetProc("P2");
    cout << yeet->proc_name << endl;
    cout << yeet->state << endl;


    delete test;
}