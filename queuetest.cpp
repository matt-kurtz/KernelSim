#include <iostream>
#include "process.h"
#include "queue.h"
#include "tokenizer.h"
#include <string.h>
using namespace std;

int main() {
    Queue* test = new Queue();
    ProcessPtr p = new Process;
    p->proc_name = "Test";
    p->state = "Ready";
    test->Enqueue(*p);
    test->PrintQueue();
    p = new Process;
    p->proc_name = "dai";
    p->state = "Ready";
    test->Enqueue(*p);
    test->PrintQueue();
    if (test->Search("what's") == true) {
        cout << "Name is already present, choose another." << endl;
    }
    else if (test->Search("what's") == false){
        cout << "Name's not present." << endl;
    }
    delete test;
    return 0;
}