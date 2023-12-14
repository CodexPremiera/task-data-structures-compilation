//
// Created by Florabel Comandao on 12/14/2023.
//

#ifndef THE_FINALS_REVIEW_INT_STACK_H
#define THE_FINALS_REVIEW_INT_STACK_H

#endif //THE_FINALS_REVIEW_INT_STACK_H

#include "../list/array_list.h"


class IntStack {
    IntArrayList* list;

public:
    IntStack () {
        list = new IntArrayList();
    }
    int getSize() {
        return list->getSize();
    }
    bool isEmpty() {
        return list->getSize() == 0;
    }

    int top() {
        return list->getElementAt(list->getSize());
    }

    void push(int element) {
        list->addLast(element);
    }

    int pop() {
        return list->removeLast();
    }

    void print() {
        list->print();
    }
};

class CharStack {
    CharArrayList* list;

public:
    CharStack () {
        list = new CharArrayList();
    }
    int getSize() {
        return list->getSize();
    }
    bool isEmpty() {
        return list->getSize() == 0;
    }

    char top() {
        return list->getElementAt(list->getSize());
    }

    void push(char element) {
        list->addLast(element);
    }

    char pop() {
        return list->removeLast();
    }

    void print() {
        list->print();
    }
};

class StringStack {
    StringArrayList* list;

public:
    StringStack () {
        list = new StringArrayList();
    }
    int getSize() {
        return list->getSize();
    }
    bool isEmpty() {
        return list->getSize() == 0;
    }

    string top() {
        return list->getElementAt(list->getSize());
    }

    void push(const string& element) {
        list->addLast(element);
    }

    string pop() {
        return list->removeLast();
    }

    void print() {
        list->print();
    }
};