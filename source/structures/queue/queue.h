//
// Created by Florabel Comandao on 12/14/2023.
//

#ifndef THE_FINALS_REVIEW_INT_QUEUE_H
#define THE_FINALS_REVIEW_INT_QUEUE_H

#endif //THE_FINALS_REVIEW_INT_QUEUE_H


#include "../list/singly_list.h"


class IntQueue {
private:
    IntSinglyList *list;

public:
    IntQueue () {
        this->list = new IntSinglyList();
    }

    void enqueue(int element) {
        list->addLast(element);
    }

    int dequeue() {
        return list->removeFirst();
    }

    int first() {
        return list->getElementAt(1);
    }

    int getSize() {
        return list->getSize();
    }

    bool isEmpty() {
        return list->getSize() == 0;
    }

    void print() {
        list->print();
    }
};

class NodeQueue {
private:
    NodeArrayList *list;

public:
    NodeQueue () {
        this->list = new NodeArrayList();
    }

    void enqueue(Node* element) {
        list->addLast(element);
    }

    Node* dequeue() {
        return list->removeFirst();
    }

    Node* first() {
        return list->getElementAt(1);
    }

    int getSize() {
        return list->getSize();
    }

    bool isEmpty() {
        return list->getSize() == 0;
    }

    void print() {
        list->print();
    }
};

class StringQueue {
private:
    StringSinglyList *list;

public:
    StringQueue () {
        this->list = new StringSinglyList();
    }

    void enqueue(const string& element) {
        list->addLast(element);
    }

    string dequeue() {
        return list->removeFirst();
    }

    string first() {
        return list->getElementAt(1);
    }

    int getSize() {
        return list->getSize();
    }

    bool isEmpty() {
        return list->getSize() == 0;
    }

    void print() {
        list->print();
    }
};