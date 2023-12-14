//
// Created by Florabel Comandao on 12/14/2023.
//

#ifndef THE_FINALS_REVIEW_PROGRAM_H
#define THE_FINALS_REVIEW_PROGRAM_H

#include <iostream>
#include <algorithm>

#include "../structures/list/int_list.h"
#include "../structures/node/node.h"

#include "../structures/stacks/stack.h"
#include "../structures/queue/queue.h"
#include "../structures/deque/deque.h"

#include "../tree/binary_tree.h"
#include "../tree/binary_search_tree.h"
#include "../tree/heap.h"


class Program {
    IntList* list;
    IntStack* stack;
    IntQueue* queue;
    IntDeque* deque;
    BinaryTree* binaryTree;
    BinarySearchTree* binarySearchTree;
    Heap* heap;

private:
    int* makePreorderArray();
    int* makePostorderArray();

    bool isBalancedParenthesis();

public:
    Program();

    void operateList();
    void operateStack();
    void operateQueue();
    void operateDeque();

    void operateTree();
    void operateBinaryTree();
    void operateBinarySearchTree();
    void operateHeap();

    void solveParenthesis();
};


#endif //THE_FINALS_REVIEW_PROGRAM_H
