#include <iostream>
#include <string.h>
#include "queue.h"
#include "process.h"
using namespace std;

int main() {
    //Process p("Test", "Ready");
    /*string name, st;
    ProcessPtr ptr = NULL;
    cout << "Name: ";
    cin >> name;
    cout << "State: ";
    cin >> st;
    Process p(name, st);
    ptr = &p;
    cout << "name is: " << ptr->proc_name << endl << "state is: " << ptr->state << endl;*/

    ProcessPtr test = new Process;
    test->proc_name = "Test";
    test->state = "Ready";

    Queue q;
    q.Enqueue(test);
    ProcessPtr out = q.Dequeue();
    cout << "Did this work? Let's see..." << endl;
    cout << "Proc: " << out->proc_name << endl;
    cout << "State: " << out->state << endl;

}