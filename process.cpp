#include "process.h"
#include <string.h>
#include <iostream>
using namespace std;

/*Process::Process(const string& name, const string& st) : proc_name(name), state(st) {
    cout << "Process initialized" << endl;
}
*/

Process::Process(string& name, string& st) : proc_name(name), state(st) {
    cout << "Process initialized" << endl;
}
