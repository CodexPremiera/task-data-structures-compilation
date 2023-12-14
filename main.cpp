#include <iostream>
#include "source/program/program.h"

using namespace std;

int main() {
    Program* program = new Program();
    char operation;

    cout << "SELECT DATA STRUCTURE" << endl
            << "[l] List" << endl
            << "[s] Stack" << endl
            << "[q] Queue" << endl
            << "[d] Deque" << endl
            << "[t] Tree" << endl
            << "[h] Heap" << endl
            << "-----" << endl
            << "Enter choice: ";
    cin >> operation;

    cout << endl;
    switch (tolower(operation)) {
        case 'l':
            program->operateList();
            break;

        case 's':
            program->operateStack();
            break;

        case 'q':
            program->operateQueue();
            break;

        case 'd':
            program->operateDeque();
            break;

        case 't':
            program->operateTree();
            break;

        case 'h':
            program->operateHeap();
            break;

        default:
            cout << "Invalid operation! Try again;" << endl;
            break;
    }

    return 0;
}
