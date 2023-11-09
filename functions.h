#include "process.h"
#include "queue.h"
extern Queue entry;
extern Queue ready;
extern Queue running;
extern Queue blocked;
extern Queue exit_st;
void Add(string &name);
//void _sim(); // can't use "exit" because we already have a queue named "exit"
void IOEvent();
void query();
void release();
void step();
void wait();