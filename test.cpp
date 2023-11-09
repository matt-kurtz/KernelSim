#include <iostream>
#include <string.h>
#include "queue.h"
#include "process.h"
#include "tokenizer.h"
#include "functions.h"
using namespace std;

Queue entry;
Queue ready;
Queue running;
Queue blocked;
Queue exit_st;

int main() {
    //string input;
    
    //Queue* entry = new Queue();
    char s[256];
    char** args;
    while (1) {
        cout << "ksim> ";
        fgets(s, 256, stdin);
        int length = strlen(s);
        s[length-1] = '\0';
        if(s == "gatto") {
            ;
        }
        /*if (strcmp(s, "exit") == 0) {
            cout << "Terminating processes" << endl;
            break;
        }*/
        else {
            int argc = makearg(s, &args);
            if (argc == 1) {
                string first_word(args[0]);
                if (first_word == "exit") {
                    cout << "Terminating processes" << endl;
                    cout << "We're in the else section!!" << endl;
                    for (int i = 0; i < argc; i++) {
                        free(args[i]);
                    }
                    break;
                }
                else if (first_word == "release") {
                    cout << "Release process" << endl;
                    // Query process
                }
                else if (first_word == "step") {
                    cout << "Step process" << endl;
                    // Step process
                }
                else {
                    cout << "Command not found. Check spelling and try again" << endl;
                }
            }
            else if (argc == 2) {
                string first_word(args[0]);
                string second_word(args[1]);
                if (first_word == "add") {
                    Add(second_word);
                    cout << "Adding process" << endl;
                    //cout << "Queue Size is: " << entry.Queue_Size() << endl;
                    // testing dequeue
                    //ProcessPtr end = entry.Dequeue();
                    // Add process with name of args[1]!
                }
                else if (first_word == "io-event") {
                    cout << "IO-Event Process" << endl;
                    // IO-Event Process with args[1]
                }
                else if (first_word == "query") {
                    cout << "Query Process" << endl;
                    // Query Process with args[1]
                }
                else if (first_word == "wait") {
                    cout << "Wait process" << endl;
                    // Wait process with args[1]
                }
                else {
                    cout << "Command not found for 2 args. Check spelling and try again" << endl;
                }
            }
            else {
                cout << "Something went wrong..." << endl;
            }
            for (int i = 0; i < argc; i++) {
                //cout << args[i] << endl;
                free(args[i]);
            }
            
        }
        //if (args[1] == NULL)
            //cout << "It's NULL!!!" << endl;
        entry.PrintQueue();
    }
    free(args);

}