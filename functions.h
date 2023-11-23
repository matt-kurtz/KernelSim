#include "process.h"
#include "queue.h"
extern Queue* entry;
extern Queue* ready;
extern Queue* running;
extern Queue* blocked;
extern Queue* exit_st;
extern Queue* iod_0;
extern Queue* iod_1;
extern Queue* iod_2;
extern Queue* iod_3;

void Add(string &name);
//void _sim(); // can't use "exit" because we already have a queue named "exit"
void IOEvent(char num);
void query(string id, int queue_num);
void release();
void Step();
void wait(char num);