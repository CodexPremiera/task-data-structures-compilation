//
// Created by Florabel Comandao on 12/14/2023.
//

#ifndef THE_FINALS_REVIEW_INT_DEQUE_H
#define THE_FINALS_REVIEW_INT_DEQUE_H

#endif //THE_FINALS_REVIEW_INT_DEQUE_H

#include "../list/doubly_list.h"


class IntDeque {
    IntDoublyList* list;

public:
    IntDeque () {
        list = new IntDoublyList();
    }

    int first() {
        return list->getElementAt(1);
    }

    int last() {
        return list->getElementAt(list->getSize());
    }

    int getSize() {
        return list->getSize();
    }

    bool isEmpty() {
        return list->getSize() == 0;
    }

    void addFirst(int element) {
        list->addFirst(element);
    }

    void addLast(int element) {
        list->addLast(element);
    }

    int removeFirst() {
        return list->removeFirst();
    }

    int removeLast() {
        return list->removeLast();
    }

    void print() {
        list->print();
    }
};