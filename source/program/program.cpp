//
// Created by Florabel Comandao on 12/14/2023.
//

#include "program.h"

using namespace std;

/* ==================== PRIVATE METHODS ==================== */

int* Program::makePreorderArray() {
    const int array[] = {40, 20, 10, 30, 60, 50, 70};
    const int size = sizeof(array) / sizeof(int);

    int* preorderArray = static_cast<int*>( calloc(size, sizeof(int)) );

    for (int count = 0; count < size; count++)
        preorderArray[count] = array[count];

    return preorderArray;
}

int* Program::makePostorderArray() {
    const int array[] = {10, 30, 20, 50, 70, 60, 40};
    const int size = sizeof(array) / sizeof(int);

    int* postorderArray = static_cast<int*>( calloc(size, sizeof(int)) );

    for (int count = 0; count < size; count++)
        postorderArray[count] = array[count];

    return postorderArray;
}



/* ==================== PUBLIC METHODS ==================== */

Program::Program() {
    this->list = nullptr;
    this->stack = new IntStack();
    this->queue = new IntQueue();
    this->deque = new IntDeque();

    this->binaryTree = new BinaryTree();
    this->binarySearchTree = new BinarySearchTree();
}


void Program::operateList() {
    int element, position, count, size;

    char operation;
    cout << "SELECT LIST TYPE" << endl
         << "[a] Array List" << endl
         << "[s] Singly Linked List" << endl
         << "[d] Doubly Linked List" << endl
         << "-----" << endl;

    do {
        cout << "Enter choice: ";
        cin >> operation;
        switch (tolower(operation)) {
            case 'a':
                cout << endl << "ARRAY LIST OPERATIONS" << endl;
                this->list = new IntArrayList();
                break;

            case 's':
                cout << endl << "SINGLY LINKED-LIST OPERATIONS" << endl;
                this->list = new IntSinglyList();
                break;

            case 'd':
                cout << endl << "DOUBLY LINKED-LIST OPERATIONS" << endl;
                this->list = new IntDoublyList();
                break;

            default:
                cout << "Please select between the choice." << endl << endl;
                break;
        }
    } while (!list);

    do {
        cout << "Operation: ";
        cin >> operation;

        switch (operation) {
            case 'g':
                cin >> position;
                try {
                    element = list->getElementAt(position);
                    cout << "Element at position #" << position << " is " << element << endl;
                } catch (const exception& exception) {
                    cout << exception.what() << endl;
                }
                break;
            case 's':
                size = list->getSize();
                cout << "The list has " << size << " elements." << endl;
                break;


            case '+':
                cin >> element;
                list->add(element);
                break;
            case 'a':
                cin >> operation >> element;
                switch (operation) {
                    case 'f':
                        list->addFirst(element);
                        break;
                    case 'l':
                        list->addLast(element);
                        break;
                    case 'a':
                        cin >> position;
                        list->addAt(element, position);
                        break;
                    case 's':
                        list->addSorted(element);
                        break;
                    default:
                        cout << "Invalid operation! Try again;" << endl;
                        break;
                }
                break;

            case '-':
                cin >> element;
                try {
                    position = list->remove(element);
                    cout << "Element " << element << " [position #" << position << "] is removed." << endl;
                } catch (const exception& exception) {
                    cout << exception.what() << endl;
                }
                break;

            case 'r':
                cin >> operation;
                switch (operation) {
                    case 'f':
                        try {
                            element = list->removeFirst();
                            cout << "First element" << " [" << element << "] is removed." << endl;
                        } catch (const exception& exception) {
                            cout << exception.what() << endl;
                        }
                        break;

                    case 'l':
                        try {
                            element = list->removeLast();
                            cout << "Last element" << " [" << element << "] is removed." << endl;
                        } catch (const exception& exception) {
                            cout << exception.what() << endl;
                        }
                        break;

                    case 'a':
                        cin >> position;
                        try {
                            element = list->removeAt(position);
                            cout << "Position #" << position << " [element " << element << "] is removed." << endl;
                        } catch (const exception& exception) {
                            cout << exception.what() << endl;
                        }
                        break;

                    case 'e':
                        cin >> element;
                        try {
                            position = list->remove(element);
                            cout << "Element " << element << " [position #" << position << "] is removed." << endl;
                        } catch (const exception& exception) {
                            cout << exception.what() << endl;
                        }
                        break;

                    case 'r':
                        cin >> element;
                        count = list->removeAll(element);
                        cout << count << " occurrences of element " << element << " are removed." << endl;
                        break;

                    default:
                        cout << "Invalid operation! Try again;" << endl;
                        break;
                }
                break;

            case 'p':
                list->print();
                break;

            case 'x':
                cout << "exiting...";
                break;

            default:
                cout << "Invalid operation! Try again;" << endl;
                break;
        }

    } while (operation != 'x');
}

void Program::operateStack() {
    char operation;
    int element, count;

    cout << "THE STACK OPERATIONS" << endl;
    do {
        cout << "Operation: ";
        cin >> operation;

        switch (operation) {
            case 's':
                if (stack->isEmpty())
                    cout << "The stack is empty." << endl;
                count = stack->getSize();
                cout << "The stack has " << count << " elements." << endl;
                break;

            case 'f':
            case 't':
                element = stack->top();
                cout << "The top element is " << element << endl;
                break;


            case '+':
                cin >> element;
                stack->push(element);
                break;

            case '-':
                try {
                    element = stack->pop();
                    cout << "The top element [" << element << "] is popped." << endl;
                } catch (const exception& exception) {
                    cout << "Nothing is popped." << endl;
                }

                break;

            case 'p':
                stack->print();
                break;

            case 'x':
                cout << "exiting...";
                break;

            default:
                cout << "Invalid operation! Try again;" << endl;
                break;
        }

    } while (operation != 'x');
}

void Program::operateQueue() {
    char operation;
    int element, count;

    cout << "THE QUEUE OPERATIONS" << endl;
    do {
        cout << "Operation: ";
        cin >> operation;

        switch (operation) {
            case 's':
                if (queue->isEmpty())
                    cout << "The queue is empty." << endl;
                count = queue->getSize();
                cout << "The queue has " << count << " elements." << endl;
                break;

            case 'f':
                element = queue->first();
                cout << "The first element is " << element << endl;
                break;


            case '+':
            case 'e':
                cin >> element;
                queue->enqueue(element);
                break;

            case '-':
            case 'd':
                element = queue->dequeue();
                cout << "The first element [" << element << "] is dequeued." << endl;
                break;

            case 'p':
                queue->print();
                break;

            case 'x':
                cout << "exiting...";
                break;

            default:
                cout << "Invalid operation! Try again;" << endl;
                break;
        }

    } while (operation != 'x');
}

void Program::operateDeque() {
    char operation;
    int element, count;

    cout << "THE DEQUE OPERATIONS" << endl;
    do {
        cout << "Operation: ";
        cin >> operation;

        switch (operation) {
            case 's':
                if (deque->isEmpty())
                    cout << "The deque is empty." << endl;
                count = deque->getSize();
                cout << "The deque has " << count << " elements." << endl;
                break;

            case 'f':
                try {
                    element = deque->first();
                    cout << "The first element is " << element << endl;
                } catch (const exception& exception) {
                    cout << "The deque is empty." << endl;
                }
                break;

            case 'l':
                try {
                    element = deque->last();
                    cout << "The last element is " << element << endl;
                } catch (const exception& exception) {
                    cout << "The deque is empty." << endl;
                }
                break;

            case '+':
                cin >> element;
                deque->addLast(element);
                break;
            case 'a':
                cin >> operation >> element;
                switch (operation) {
                    case 'l':
                        deque->addLast(element);
                        break;
                    case 'f':
                        deque->addFirst(element);
                        break;
                    default:
                        break;
                }
                break;

            case '-':
                try {
                    element = deque->removeFirst();
                    cout << "The first element [" << element << "] is removed." << endl;
                } catch (const exception& exception) {
                    cout << "The deque is empty." << endl;
                }

                break;
            case 'r':
                cin >> operation >> element;
                switch (operation) {
                    case 'l':
                        try {
                            element = deque->removeLast();
                            cout << "The last element [" << element << "] is removed." << endl;
                        } catch (const exception& exception) {
                            cout << "The deque is empty." << endl;
                        }
                        break;
                    case 'f':
                        try {
                            element = deque->removeFirst();
                            cout << "The first element [" << element << "] is removed." << endl;
                        } catch (const exception& exception) {
                            cout << "The deque is empty." << endl;
                        }
                        break;
                    default:
                        break;
                }
                break;

            case 'p':
                deque->print();
                break;

            case 'x':
                cout << "exiting...";
                break;

            default:
                cout << "Invalid operation! Try again;" << endl;
                break;
        }

    } while (operation != 'x');
}


void Program::operateTree() {
    char operation;
    bool hasSelected = false;
    cout << "SELECT TREE TYPE" << endl
         << "[b] Binary Tree" << endl
         << "[s] Binary Search Tree" << endl
         << "-----" << endl;

    do {
        cout << "Enter choice: ";
        cin >> operation;
        switch (tolower(operation)) {
            case 'b':
                cout << endl << "BINARY TREE OPERATIONS" << endl;
                this->operateBinaryTree();
                hasSelected = true;
                break;

            case 's':
                cout << endl << "BINARY SEARCH TREE OPERATIONS" << endl;
                this->operateBinarySearchTree();
                hasSelected = true;
                break;

            default:
                cout << "Please select between the choice." << endl << endl;
                break;
        }
    } while (!hasSelected);
}

void Program::operateBinaryTree() {
    binaryTree->addRoot(1);
    binaryTree->addLeft(2, 1);
    binaryTree->addRight(3, 1);

    binaryTree->addLeft(4, 2);
    binaryTree->addRight(5, 2);
    binaryTree->addLeft(6, 3);
    binaryTree->addRight(7, 3);
    
    char operation;
    int element, parent, position, count, size;
    Node* targetNode;

    do {
        cout << "Operation: ";
        cin >> operation;

        switch (operation) {
            case 'g':
                cin >> operation ;
                switch (operation) {
                    case 'n':
                        cin >> element;
                        targetNode = binaryTree->getNodeByElement(element);

                        if (targetNode)
                            cout << "Element " << element << " is found in the binaryTree." << endl;
                        else
                            cout << "Element " << element << " is not found in the binaryTree." << endl;
                        break;

                    case 'l':
                        cin >> element;
                        targetNode = binaryTree->getLeft(element);

                        if (targetNode)
                            cout << "Left child of " << element << " is " << targetNode->element << endl;
                        else
                            cout << "Element " << element << " has no left child" << endl;
                        break;

                    case 'r':
                        cin >> element;
                        targetNode = binaryTree->getRight(element);

                        if (targetNode)
                            cout << "Right child of " << element << " is " << targetNode->element << endl;
                        else
                            cout << "Element " << element << " has no right child" << endl;
                        break;

                    case 's':
                        cin >> element;
                        targetNode = binaryTree->getSibling(element);

                        if (targetNode)
                            cout << "Sibling node of " << element << " is " << targetNode->element << endl;
                        else
                            cout << "Element " << element << " has no sibling node" << endl;
                        break;

                    case 'c':
                        count = binaryTree->getSize();
                        cout << "The binaryTree has " << count << " elements." << endl;
                        break;
                    case 'd':
                        cin >> element;
                        count = binaryTree->getDepth(element);
                        cout << "Node of " << element << " has a depth of " << count << endl;
                        break;
                    case 'h':
                        cin >> element;
                        count = binaryTree->getHeight(element);
                        cout << "Node of " << element << " has a height of " << count << endl;
                        break;

                    default:
                        cout << "Invalid operation! Try again;" << endl;
                        break;
                }

                break;


            case '+':
            case 'a':
                cin >> operation >> element;
                switch (operation) {
                    case 'R':
                        binaryTree->addRoot(element);
                        break;
                    case 'l':
                        cin >> parent;
                        binaryTree->addLeft(element, parent);
                        break;
                    case 'r':
                        cin >> parent;
                        binaryTree->addRight(element, parent);
                        break;
                    default:
                        cout << "Invalid operation! Try again;" << endl;
                        break;
                }
                break;

            case '-':
                cin >> element;
                try {
                    binaryTree->remove(element);
                    cout << "Element " << element << " is removed." << endl;
                } catch (const exception& exception) {
                    cout << "Element " << element << " is not removed." << endl;
                }
                break;
            case 'r':
                cin >> operation;
                switch (operation) {
                    case 'e':
                        cin >> element;
                        try {
                            binaryTree->remove(element);
                            cout << "Element " << element << " is removed." << endl;
                        } catch (const exception& exception) {
                            cout << "Element " << element << " is not removed." << endl;
                        }
                        break;
                    case 'A':
                        binaryTree->clearTree();
                        break;
                    default:
                        cout << "Invalid operation! Try again;" << endl;
                        break;
                }
                break;

            case 'p':
                cin >> operation;
                switch (operation) {
                    case 'r':
                        binaryTree->preorderTraversal();
                        break;
                    case 'o':
                        binaryTree->postorderTraversal();
                        break;
                    case 'i':
                        binaryTree->inorderTraversal();
                        break;
                    case 'b':
                        binaryTree->breadthFirstTraversal();
                        break;
                    default:
                        cout << "Invalid operation! Try again;" << endl;
                        break;
                }
                break;

            case 'x':
                cout << "exiting...";
                break;

            default:
                cout << "Invalid operation! Try again;" << endl;
                break;
        }

    } while (operation != 'x');
}

void Program::operateBinarySearchTree() {
    binarySearchTree->add(4);
    binarySearchTree->add(2);
    binarySearchTree->add(6);
    binarySearchTree->add(1);
    binarySearchTree->add(3);
    binarySearchTree->add(5);
    binarySearchTree->add(7);
    
    char operation;
    int element, parent, position, count, size;
    Node* targetNode;

    int* preorderArray = makePreorderArray();
    int* postorderArray = makePostorderArray();

    do {
        cout << "Operation: ";
        cin >> operation;

        switch (operation) {
            case 'g':
                cin >> operation ;
                switch (operation) {
                    case 'n':
                        cin >> element;
                        targetNode = binarySearchTree->getNode(element);

                        if (targetNode)
                            cout << "Element " << element << " is found in the binarySearchTree." << endl;
                        else
                            cout << "Element " << element << " is not found in the binarySearchTree." << endl;
                        break;

                    case 'l':
                        cin >> element;
                        targetNode = binarySearchTree->getLeft(element);

                        if (targetNode)
                            cout << "Left child of " << element << " is " << targetNode->element << endl;
                        else
                            cout << "Element " << element << " has no left child" << endl;
                        break;

                    case 'r':
                        cin >> element;
                        targetNode = binarySearchTree->getRight(element);

                        if (targetNode)
                            cout << "Right child of " << element << " is " << targetNode->element << endl;
                        else
                            cout << "Element " << element << " has no right child" << endl;
                        break;

                    case 's':
                        cin >> element;
                        targetNode = binarySearchTree->getSibling(element);

                        if (targetNode)
                            cout << "Sibling node of " << element << " is " << targetNode->element << endl;
                        else
                            cout << "Element " << element << " has no sibling node" << endl;
                        break;

                    case 'c':
                        count = binarySearchTree->getSize();
                        cout << "The binarySearchTree has " << count << " elements." << endl;
                        break;
                    case 'd':
                        cin >> element;
                        count = binarySearchTree->getDepth(element);
                        cout << "Node of " << element << " has a depth of " << count << endl;
                        break;
                    case 'h':
                        cin >> element;
                        count = binarySearchTree->getHeight(element);
                        cout << "Node of " << element << " has a height of " << count << endl;
                        break;

                    default:
                        cout << "Invalid operation! Try again;" << endl;
                        break;
                }

                break;


            case '+':
            case 'a':
                cin >> element;
                if (binarySearchTree->add(element))
                    cout << "Element " << element << " is added." << endl;
                else
                    cout << "Element " << element << " is not added." << endl;
                break;

            case '-':
                cin >> element;
                try {
                    binarySearchTree->remove(element);
                    cout << "Element " << element << " is removed." << endl;
                } catch (const exception& exception) {
                    cout << "Element " << element << " is not removed." << endl;
                }
                break;
            case 'r':
                cin >> operation;
                switch (operation) {
                    case 'e':
                        cin >> element;
                        try {
                            binarySearchTree->remove(element);
                            cout << "Element " << element << " is removed." << endl;
                        } catch (const exception& exception) {
                            cout << "Element " << element << " is not removed." << endl;
                        }
                        break;
                    case 'A':
                        count = binarySearchTree->clearTree();
                        cout << "All " << count << " elements removed." << endl << endl;
                        break;
                    default:
                        cout << "Invalid operation! Try again;" << endl;
                        break;
                }
                break;

            case 'p':
                cin >> operation;
                switch (operation) {
                    case 'r':
                        binarySearchTree->preorderTraversal();
                        break;
                    case 'o':
                        binarySearchTree->postorderTraversal();
                        break;
                    case 'i':
                        binarySearchTree->inorderTraversal();
                        break;
                    case 'b':
                        binarySearchTree->breadthFirstTraversal();
                        break;
                    default:
                        cout << "Invalid operation! Try again;" << endl;
                        break;
                }
                break;

            case 'c':
                cin >> operation;
                switch (operation) {
                    case 'r':
                        binarySearchTree->convertPreorder(preorderArray, 7);
                        break;
                    case 'o':
                        binarySearchTree->convertPostorder(postorderArray, 7);
                        break;
                    default:
                        cout << "Invalid operation! Try again;" << endl;
                        break;
                }
                break;

            case 'x':
                cout << "exiting...";
                break;

            default:
                cout << "Invalid operation! Try again;" << endl;
                break;
        }

    } while (operation != 'x');
}