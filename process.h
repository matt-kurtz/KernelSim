#include <iostream>
#include <string.h>
using namespace std;
#ifndef PROCESS_H
#define PROCESS_H
struct Process {
    string proc_name;
    string state;
    int device;
    int tick_count;

    //Process(const string& name, const string& st);
    Process() {;}
    ~Process();
    Process(string& name, string& st);
};
typedef Process* ProcessPtr;

#endif // PROCESS_H