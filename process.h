#include <iostream>
#include <string.h>
using namespace std;
#ifndef PROCESS_H
#define PROCESS_H
struct Process {
    string proc_name;
    string state;

    //Process(const string& name, const string& st);
    Process() {;}
    Process(string& name, string& st);
};
typedef Process* ProcessPtr;

#endif // PROCESS_H