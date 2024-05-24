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
#include "../tree/avl_tree.h"
#include "../tree/splay_tree.h"
#include "../tree/red_black_tree.h"
#include "../tree/heap.h"

#include "../graph/vertex.h"
#include "../graph/edge.h"
#include "../graph/graph.h"
#include "../graph/adjacency_matrix_graph.h"
#include "../graph/adjacency_list_graph.h"

class Program {
    IntList* list;
    IntStack* stack;
    IntQueue* queue;
    IntDeque* deque;
    BinaryTree* binaryTree;
    BinarySearchTree* binarySearchTree;
    AVLTree* avlTree;
    SplayTree* splayTree;
    RedBlackTree* redBlackTree;
    Heap* heap;
    AdjacencyMatrixGraph* adjacencyMatrixGraph;
    AdjacencyListGraph* adjacencyListGraph;


private:
    int* makePreorderArray();
    int* makePostorderArray();

public:
    Program();

    void operateList();
    void operateStack();
    void operateQueue();
    void operateDeque();

    void operateTree();
    void operateBinaryTree();
    void operateBinarySearchTree();
    void operateAVLTree();
    void operateSplayTree();
    void operateRedBlackTree();
    void operateHeap();

    void operateGraph();
    void operateCertainGraph(Graph* graph);
};


#endif //THE_FINALS_REVIEW_PROGRAM_H
