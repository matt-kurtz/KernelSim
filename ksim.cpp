#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "queue.h"
#include "process.h"
#include "tokenizer.h"
#include "functions.h"
using namespace std;

    Queue* entry = new Queue();
    Queue* ready = new Queue();
    Queue* running = new Queue();
    Queue* blocked = new Queue();
    Queue* exit_st = new Queue();
    Queue* iod_0 = new Queue();
    Queue* iod_1 = new Queue();
    Queue* iod_2 = new Queue();
    Queue* iod_3 = new Queue();

    int tick = 0;

int main() {
    char s[256];
    char** args;

    while (1) {
        cout << "ksim-" << setw(9) << setfill('0') << tick << "> ";
        fgets(s, 256, stdin);
        int length = strlen(s);
        s[length-1] = '\0';

        int argc = makearg(s, &args);
        if (argc == 1) {
            string first_word(args[0]);
            if (first_word == "exit") {
                for (int i = 0; i < argc; i++) {
                    free(args[i]);
                }
                free(args);
                break;
            }
            else if (first_word == "release") {
                release();
            }
            else if (first_word == "step") {
                Step();
            }
            else if (first_word == "query") {
                query("", 10);
            }
            else if (first_word == "add") {
                cout << "Opcode \"add\" requires 1 operand." << endl;
            }
            else if (first_word == "wait") {
                cout << "Opcode \"wait\" requires 1 operand in range [0-3]." << endl;
            }
            else if (first_word == "io-event") {
                cout << "Opcode \"io-event\" requires 1 operand in range [0-3]." << endl;
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
            }
            else if (first_word == "io-event") {
                if (*args[1] != '0' && *args[1] != '1' && *args[1] != '2' && *args[1] != '3')
                    cout << "Second argument should be in the range [0-3]" << endl;
                else { 
                    IOEvent(*args[1]);
                }    
            }
            else if (first_word == "query") {
                if (second_word == "all") {
                    query("", 10);
                }
                else if (entry->Search(second_word) == true) {
                    query(second_word, 1);
                }
                else if (ready->Search(second_word) == true) {
                    query(second_word, 2);
                }
                else if (running->Search(second_word) == true) {
                    query(second_word, 3);
                }
                else if (blocked->Search(second_word) == true) {
                    query(second_word, 4);
                }
                else if (exit_st->Search(second_word) == true) {
                    query(second_word, 5);
                }
                else if (iod_0->Search(second_word) == true) {
                    query(second_word, 6);
                }
                else if (iod_1->Search(second_word) == true) {
                    query(second_word, 7);
                }
                else if (iod_2->Search(second_word) == true) {
                    query(second_word, 8);
                }
                else if (iod_3->Search(second_word) == true) {
                    query(second_word, 9);
                }
                else {
                    cout << "Process " << "\"" << second_word << "\"" << " not found." << endl;
                }
            }
            else if (first_word == "wait") {
                if (*args[1] != '0' && *args[1] != '1' && *args[1] != '2' && *args[1] != '3')
                    cout << "Second argument should be in the range [0-3]" << endl;
                else {
                    wait(*args[1]);
                }
                
            }
            else {
                cout << "Command not found for 2 args. Check spelling and try again" << endl;
            }
        }
        else {
            cout << "0 args or more than 2 args. Make sure you have 1 and/or 2 args." << endl;
        }
        for (int i = 0; i < argc; i++) {
            free(args[i]);
        }
        free(args);
    }
    delete entry;
    delete ready;
    delete running;
    delete blocked;
    delete exit_st;
    delete iod_0;
    delete iod_1;
    delete iod_2;
    delete iod_3;
}