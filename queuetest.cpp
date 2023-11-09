#include <iostream>
#include "process.h"
#include "queue.h"
#include "tokenizer.h"
#include <string.h>
using namespace std;

int main() {
    Queue test;
    ProcessPtr p = new Process;
    p->proc_name = "Test";
    p->state = "Ready";
    test.Enqueue(p);
    p = new Process;
    p->proc_name = "Test";
    p->state = "Ready";

    if (test.Search("dai") == true) {
        cout << "Name is already present, choose another." << endl;
    }
    else if (test.Search("dai") == false){
        cout << "Name's not present." << endl;
    }
    return 0;
}