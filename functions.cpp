#include <iostream>
#include "process.h"
#include "queue.h"
#include "functions.h"
#include <string.h>
using namespace std;

extern Queue* entry;
extern Queue* ready;
extern Queue* running;
extern Queue* blocked;
extern Queue* exit_st;
extern Queue* iod_0;
extern Queue* iod_1;
extern Queue* iod_2;
extern Queue* iod_3;

void Add(string &name)
{
    if (entry->Search(name) == true || ready->Search(name) == true || running->Search(name) == true || blocked->Search(name) == true || exit_st->Search(name) == true || iod_0->Search(name) == true || iod_1->Search(name) == true || iod_2->Search(name) == true || iod_3->Search(name) == true) {
        cout << "Process named " << "\"" << name << "\"" << " is already being hosted." << endl;
    }
    else {
        ProcessPtr p = new Process;
        p->proc_name = name;
        p->state = "New";
        //cout << "Process Name: " << p->proc_name << endl << "State: " << p->state << endl;
        entry->Enqueue(*p);
    }
}
void Step() {
    if (entry->IsEmpty() && ready->IsEmpty() && running->IsEmpty() && blocked->IsEmpty()
    && exit_st->IsEmpty() && iod_0->IsEmpty() && iod_1->IsEmpty() && iod_2->IsEmpty() && iod_3->IsEmpty()) {
        cout << "Nothing in simulation. Add a process to continue." << endl;
    }
    // Remove all processes that are in the exit state.
    while (exit_st->IsEmpty() != true) {
        ProcessPtr p = exit_st->Dequeue();
        cout << "Process " << "\"" << p->proc_name << "\"" << "is banished to the void." << endl; 
    }
    // Advance at most 1 process in the New State into the ready state.
    if (entry->Queue_Size() >= 1) {
        ProcessPtr q = entry->Dequeue();
        cout << "Process " << "\"" << q->proc_name << "\"" << " moved from " << q->state << " to ";
        q->state = "Ready";
        cout << q->state << endl;
        ready->Enqueue(*q);
    }
    // Advance at most 1 process from each I/O device in the Blocked state into the ready state
    // CHECK TICK REQUIREMENT

    // Remove Process from Running State and put into Ready
    if (running->IsEmpty() == false) {
        ProcessPtr p = running->Dequeue();
        cout << "Process " << "\"" << p->proc_name << "\"" << " moved from " << p->state << " to ";
        p->state = "Ready";
        cout << p->state << endl;
        ready->Enqueue(*p);
    }
    // If any processes are in the Ready state, dispatch a process to the processor
    // by advancing it from the Ready state to the running state.
    if (ready->IsEmpty() != true) {
        ProcessPtr p = ready->Dequeue();
        cout << "Process " << "\"" << p->proc_name << "\"" << " moved from " << p->state << " to ";
        p->state = "Running";
        cout << p->state << endl;
        running->Enqueue(*p);
    }


}

void wait(char num) {
    ProcessPtr p;
    if (running->IsEmpty() == false) {
        switch (num) {
            case '0':
                p = running->Dequeue();
                p->state = "Blocked";
                p->device = 0;
                iod_0->Enqueue(*p);
                break;
            case '1':
                p = running->Dequeue();
                p->state = "Blocked";
                p->device = 1;
                iod_1->Enqueue(*p);
                break;
            case '2':
                p = running->Dequeue();
                p->state = "Blocked";
                p->device = 2;
                iod_2->Enqueue(*p);
                break;
            case '3':
                p = running->Dequeue();
                p->state = "Blocked";
                p->device = 3;
                iod_3->Enqueue(*p);
                break;
            default:
                cout << "Error with wait command. Check second arg" << endl;
        }
    }
    else {
        cout << "No processes running" << endl;
    }
}

void IOEvent(char num) {
    ProcessPtr p;
    switch (num) {
            case '0':
                if (iod_0->IsEmpty() == true) {
                    cout << "No processes waiting on device 0." << endl;
                }
                else {
                    while (iod_0->IsEmpty() != true) {
                        p = iod_0->Dequeue();
                        p->state = "Ready";
                        ready->Enqueue(*p);
                    }
                }
                break;
            case '1':
                if (iod_1->IsEmpty() == true) {
                    cout << "No processes waiting on device 1." << endl;
                }
                else {
                    while (iod_1->IsEmpty() != true) {
                        p = iod_1->Dequeue();
                        p->state = "Ready";
                        ready->Enqueue(*p);
                    }
                }
                break;
            case '2':
                if (iod_2->IsEmpty() == true) {
                    cout << "No processes waiting on device 2." << endl;
                }
                else {
                    while (iod_2->IsEmpty() != true) {
                        p = iod_2->Dequeue();
                        p->state = "Ready";
                        ready->Enqueue(*p);
                    }
                }
                break;
            case '3':
                if (iod_3->IsEmpty() == true) {
                    cout << "No processes waiting on device 3." << endl;
                }
                else {
                    while (iod_3->IsEmpty() != true) {
                        p = iod_3->Dequeue();
                        p->state = "Ready";
                        ready->Enqueue(*p);
                    }
                }
                break;
            default:
                cout << "Error with IO-event command. Check second arg" << endl;
            }
}

void query(string id, int queue_num) {
    ProcessPtr p;
    switch(queue_num) {
        case 1:
            p = entry->SearchRetProc(id);
            cout << "***" << endl << "    id: " << "\"" << p->proc_name << "\"" << endl << "    state: " << "\"" << p->state << "\"" << endl;
            if (p->state == "Blocked"){
                cout << "       waiting on device " << p->device << " since tick " << /* add tick num here << */ endl;
            }
            cout << "***" << endl;
            break;
        case 2:
            p = ready->SearchRetProc(id);
            cout << "***" << endl << "    id: " << "\"" << p->proc_name << "\"" << endl << "    state: " << "\"" << p->state << "\"" << endl;
            if (p->state == "Blocked"){
                cout << "       waiting on device " << p->device << " since tick " << /* add tick num here << */ endl;
            }
            cout << "***" << endl;
            break;
        case 3:
            p = running->SearchRetProc(id);
            cout << "***" << endl << "    id: " << "\"" << p->proc_name << "\"" << endl << "    state: " << "\"" << p->state << "\"" << endl;
            if (p->state == "Blocked"){
                cout << "       waiting on device " << p->device << " since tick " << /* add tick num here << */ endl;
            }
            cout << "***" << endl;
            break;
        case 4:
            p = blocked->SearchRetProc(id);
            cout << "***" << endl << "    id: " << "\"" << p->proc_name << "\"" << endl << "    state: " << "\"" << p->state << "\"" << endl;
            if (p->state == "Blocked"){
                cout << "       waiting on device " << p->device << " since tick " << /* add tick num here << */ endl;
            }
            cout << "***" << endl;
            break;
        case 5:
            p = exit_st->SearchRetProc(id);
            cout << "***" << endl << "    id: " << "\"" << p->proc_name << "\"" << endl << "    state: " << "\"" << p->state << "\"" << endl;
            if (p->state == "Blocked"){
                cout << "       waiting on device " << p->device << " since tick " << /* add tick num here << */ endl;
            }
            cout << "***" << endl;
            break;
        case 6:
            p = iod_0->SearchRetProc(id);
            cout << "***" << endl << "    id: " << "\"" << p->proc_name << "\"" << endl << "    state: " << "\"" << p->state << "\"" << endl;
            if (p->state == "Blocked"){
                cout << "       waiting on device " << p->device << " since tick " << /* add tick num here << */ endl;
            }
            cout << "***" << endl;
            break;
        case 7:
            p = iod_1->SearchRetProc(id);
            cout << "***" << endl << "    id: " << "\"" << p->proc_name << "\"" << endl << "    state: " << "\"" << p->state << "\"" << endl;
            if (p->state == "Blocked"){
                cout << "       waiting on device " << p->device << " since tick " << /* add tick num here << */ endl;
            }
            cout << "***" << endl;
            break;
        case 8:
            p = iod_2->SearchRetProc(id);
            cout << "***" << endl << "    id: " << "\"" << p->proc_name << "\"" << endl << "    state: " << "\"" << p->state << "\"" << endl;
            if (p->state == "Blocked"){
                cout << "       waiting on device " << p->device << " since tick " << /* add tick num here << */ endl;
            }
            cout << "***" << endl;
        case 9:
            p = iod_3->SearchRetProc(id);
            cout << "***" << endl << "    id: " << "\"" << p->proc_name << "\"" << endl << "    state: " << "\"" << p->state << "\"" << endl;
            if (p->state == "Blocked"){
                cout << "       waiting on device " << p->device << " since tick " << /* add tick num here << */ endl;
            }
            cout << "***" << endl;
            break;
        case 10:
            entry->PrintAllProcs();
            ready->PrintAllProcs();
            running->PrintAllProcs();
            blocked->PrintAllProcs();
            exit_st->PrintAllProcs();
            iod_0->PrintAllProcs();
            iod_1->PrintAllProcs();
            iod_2->PrintAllProcs();
            iod_3->PrintAllProcs();
            break;
        default:
            cout << "Error..." << endl;
            break;
    }
}
