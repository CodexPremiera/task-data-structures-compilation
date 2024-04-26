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
    this->avlTree = new AVLTree();
    this->splayTree = new SplayTree();
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
         << "[a] AVL Tree" << endl
         << "[l] Splay Tree" << endl
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

            case 'a':
                cout << endl << "AVL TREE OPERATIONS" << endl;
                this->operateAVLTree();
                hasSelected = true;
                break;

            case 'l':
                cout << endl << "SPLAY TREE OPERATIONS" << endl;
                this->operateSplayTree();
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
    binarySearchTree->add(8);
    binarySearchTree->add(4);
    binarySearchTree->add(12);
    binarySearchTree->add(2);
    binarySearchTree->add(6);
    binarySearchTree->add(10);
    binarySearchTree->add(14);
    binarySearchTree->add(1);
    binarySearchTree->add(3);
    binarySearchTree->add(5);
    binarySearchTree->add(7);
    binarySearchTree->add(9);
    binarySearchTree->add(11);
    binarySearchTree->add(13);
    binarySearchTree->add(15);
    
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
                    case 'b':
                        cin >> element;
                        count = binarySearchTree->getNode(element)->getBalanceFactor();
                        cout << "The balance factor of " << element << " is " << count << endl;
                        break;

                    case 'p':
                        cin >> element;
                        count = binarySearchTree->getPredecessor(element);
                        cout << "Predecessor of " << element << " is " << count << endl;
                        break;
                    case 'u':
                        cin >> element;
                        count = binarySearchTree->getSuccessor(element);
                        cout << "Successor of " << element << " is " << count << endl;
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


void Program::operateAVLTree() {
    avlTree->add(1);
    avlTree->add(2);
    avlTree->add(3);
    avlTree->add(4);
    avlTree->add(5);
    avlTree->add(6);
    avlTree->add(7);
    avlTree->add(8);
    avlTree->add(9);
    avlTree->add(10);
    avlTree->add(11);
    avlTree->add(12);
    avlTree->add(13);
    avlTree->add(14);
    avlTree->add(15);

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
                        targetNode = avlTree->getNode(element);

                        if (targetNode)
                            cout << "Element " << element << " is found in the avlTree." << endl;
                        else
                            cout << "Element " << element << " is not found in the avlTree." << endl;
                        break;

                    case 'l':
                        cin >> element;
                        targetNode = avlTree->getLeft(element);

                        if (targetNode)
                            cout << "Left child of " << element << " is " << targetNode->element << endl;
                        else
                            cout << "Element " << element << " has no left child" << endl;
                        break;

                    case 'r':
                        cin >> element;
                        targetNode = avlTree->getRight(element);

                        if (targetNode)
                            cout << "Right child of " << element << " is " << targetNode->element << endl;
                        else
                            cout << "Element " << element << " has no right child" << endl;
                        break;

                    case 's':
                        cin >> element;
                        targetNode = avlTree->getSibling(element);

                        if (targetNode)
                            cout << "Sibling node of " << element << " is " << targetNode->element << endl;
                        else
                            cout << "Element " << element << " has no sibling node" << endl;
                        break;

                    case 'c':
                        count = avlTree->getSize();
                        cout << "The avlTree has " << count << " elements." << endl;
                        break;
                    case 'd':
                        cin >> element;
                        count = avlTree->getDepth(element);
                        cout << "Node of " << element << " has a depth of " << count << endl;
                        break;
                    case 'h':
                        cin >> element;
                        count = avlTree->getHeight(element);
                        cout << "Node of " << element << " has a height of " << count << endl;
                        break;
                    case 'b':
                        cin >> element;
                        count = avlTree->getNode(element)->getBalanceFactor();
                        cout << "The balance factor of " << element << " is " << count << endl;
                        break;

                    case 'p':
                        cin >> element;
                        count = avlTree->getPredecessor(element);
                        cout << "Predecessor of " << element << " is " << count << endl;
                        break;
                    case 'u':
                        cin >> element;
                        count = avlTree->getSuccessor(element);
                        cout << "Successor of " << element << " is " << count << endl;
                        break;

                    default:
                        cout << "Invalid operation! Try again;" << endl;
                        break;
                }

                break;


            case '+':
            case 'a':
                cin >> element;
                if (avlTree->add(element))
                    cout << "Element " << element << " is added." << endl;
                else
                    cout << "Element " << element << " is not added." << endl;
                break;

            case '-':
                cin >> element;
                try {
                    avlTree->remove(element);
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
                            avlTree->remove(element);
                            cout << "Element " << element << " is removed." << endl;
                        } catch (const exception& exception) {
                            cout << "Element " << element << " is not removed." << endl;
                        }
                        break;
                    case 'A':
                        count = avlTree->clearTree();
                        cout << "All " << count << " elements removed." << endl << endl;
                        break;
                    default:
                        cout << "Invalid operation! Try again;" << endl;
                        break;
                }
                break;

            case 'z':
                cin >> operation >> element;
                switch (operation) {
                    case 'l':
                        try {
                            avlTree->zigLeft(element);
                            cout << " Zig Left done on " << element << endl;
                        } catch (const runtime_error& error) {
                            cout << " Zig Left failed on " << element << endl;
                        }
                        break;
                    case 'r':
                        try {
                            avlTree->zigRight(element);
                            cout << " Zig Right done on " << element << endl;
                        } catch (const runtime_error& error) {
                            cout << " Zig Right can't be done on " << element << endl;
                        }
                        break;
                    case 't':
                        if (avlTree->restructure(element))
                            cout << "Restructure done at " << element << endl;
                        else
                            cout << "Restructure failed at " << element << endl;
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
                        avlTree->preorderTraversal();
                        break;
                    case 'o':
                        avlTree->postorderTraversal();
                        break;
                    case 'i':
                        avlTree->inorderTraversal();
                        break;
                    case 'b':
                        avlTree->breadthFirstTraversal();
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
                        avlTree->convertPreorder(preorderArray, 7);
                        break;
                    case 'o':
                        avlTree->convertPostorder(postorderArray, 7);
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


void Program::operateSplayTree() {
    splayTree->add(1);
    splayTree->add(2);
    splayTree->add(3);
    splayTree->add(4);
    splayTree->add(5);
    splayTree->add(6);
    splayTree->add(7);
    splayTree->add(8);
    splayTree->add(9);
    splayTree->add(10);
    splayTree->add(11);
    splayTree->add(12);
    splayTree->add(13);
    splayTree->add(14);
    splayTree->add(15);

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
                        targetNode = splayTree->getNode(element);

                        if (targetNode)
                            cout << "Element " << element << " is found in the splayTree." << endl;
                        else
                            cout << "Element " << element << " is not found in the splayTree." << endl;
                        break;

                    case 'l':
                        cin >> element;
                        targetNode = splayTree->getLeft(element);

                        if (targetNode)
                            cout << "Left child of " << element << " is " << targetNode->element << endl;
                        else
                            cout << "Element " << element << " has no left child" << endl;
                        break;

                    case 'r':
                        cin >> element;
                        targetNode = splayTree->getRight(element);

                        if (targetNode)
                            cout << "Right child of " << element << " is " << targetNode->element << endl;
                        else
                            cout << "Element " << element << " has no right child" << endl;
                        break;

                    case 's':
                        cin >> element;
                        targetNode = splayTree->getSibling(element);

                        if (targetNode)
                            cout << "Sibling node of " << element << " is " << targetNode->element << endl;
                        else
                            cout << "Element " << element << " has no sibling node" << endl;
                        break;

                    case 'c':
                        count = splayTree->getSize();
                        cout << "The splayTree has " << count << " elements." << endl;
                        break;
                    case 'd':
                        cin >> element;
                        count = splayTree->getDepth(element);
                        cout << "Node of " << element << " has a depth of " << count << endl;
                        break;
                    case 'h':
                        cin >> element;
                        count = splayTree->getHeight(element);
                        cout << "Node of " << element << " has a height of " << count << endl;
                        break;
                    case 'b':
                        cin >> element;
                        count = splayTree->getNode(element)->getBalanceFactor();
                        cout << "The balance factor of " << element << " is " << count << endl;
                        break;

                    case 'p':
                        cin >> element;
                        count = splayTree->getPredecessor(element);
                        cout << "Predecessor of " << element << " is " << count << endl;
                        break;
                    case 'u':
                        cin >> element;
                        count = splayTree->getSuccessor(element);
                        cout << "Successor of " << element << " is " << count << endl;
                        break;

                    default:
                        cout << "Invalid operation! Try again;" << endl;
                        break;
                }

                break;


            case '+':
            case 'a':
                cin >> element;
                if (splayTree->add(element))
                    cout << "Element " << element << " is added." << endl;
                else
                    cout << "Element " << element << " is not added." << endl;
                break;

            case '-':
                cin >> element;
                try {
                    splayTree->remove(element);
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
                            splayTree->remove(element);
                            cout << "Element " << element << " is removed." << endl;
                        } catch (const exception& exception) {
                            cout << "Element " << element << " is not removed." << endl;
                        }
                        break;
                    case 'A':
                        count = splayTree->clearTree();
                        cout << "All " << count << " elements removed." << endl << endl;
                        break;
                    default:
                        cout << "Invalid operation! Try again;" << endl;
                        break;
                }
                break;

            case 'z':
                cin >> operation >> element;
                switch (operation) {
                    case 'l':
                        try {
                            splayTree->zigLeft(element);
                            cout << " Zig Left done on " << element << endl;
                        } catch (const runtime_error& error) {
                            cout << " Zig Left failed on " << element << endl;
                        }
                        break;
                    case 'r':
                        try {
                            splayTree->zigRight(element);
                            cout << " Zig Right done on " << element << endl;
                        } catch (const runtime_error& error) {
                            cout << " Zig Right can't be done on " << element << endl;
                        }
                        break;
                    case 't':
                        if (splayTree->restructure(element))
                            cout << "Restructure done at " << element << endl;
                        else
                            cout << "Restructure failed at " << element << endl;
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
                        splayTree->preorderTraversal();
                        break;
                    case 'o':
                        splayTree->postorderTraversal();
                        break;
                    case 'i':
                        splayTree->inorderTraversal();
                        break;
                    case 'b':
                        splayTree->breadthFirstTraversal();
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
                        splayTree->convertPreorder(preorderArray, 7);
                        break;
                    case 'o':
                        splayTree->convertPostorder(postorderArray, 7);
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


void Program::operateHeap() {
    char operation;
    int element, count;

    cout << "THE HEAP OPERATIONS" << endl;
    do {
        cout << "Operation: ";
        cin >> operation;

        switch (operation) {
            case 's':
                if (heap->isEmpty())
                    cout << "The heap is empty." << endl;
                count = heap->getSize();
                cout << "The heap has " << count << " elements." << endl;
                break;

            case 'm':
                element = heap->getMin();
                cout << "The minimum element is " << element << endl;
                break;


            case '+':
                cin >> element;
                heap->add(element);
                break;

            case '-':
                try {
                    element = heap->removeMin();
                    cout << "The minimum element [" << element << "] is removed." << endl;
                } catch (const exception& exception) {
                    cout << "Nothing is removed." << endl;
                }

                break;

            case 'p':
                heap->print();
                break;

            case 'x':
                cout << "exiting...";
                break;

            default:
                cout << "Invalid operation! Try again;" << endl;
                break;
        }

    } while (operation != 'x');
}; 