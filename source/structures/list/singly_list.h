//
// Created by Florabel Comandao on 12/14/2023.
//

#ifndef THE_FINALS_REVIEW_INT_SINGLY_LIST_H
#define THE_FINALS_REVIEW_INT_SINGLY_LIST_H

#endif //THE_FINALS_REVIEW_INT_SINGLY_LIST_H

#include <iostream>
#include <cstdlib>

using namespace std;

class IntSinglyList: public IntList {
    IntListNode* head;
    IntListNode* tail;
    int size;

public:
    IntSinglyList() {
        this->head = this->tail = nullptr;
        this->size = 0;
    }

    int getElementAt(int position) {
        if (position < 1 || position > this->size)
            throw logic_error("Position out of bounds.");

        IntListNode* current = head;
        for (int currPos = 1; currPos < position; currPos++)
            current = current->next;

        return current->element;
    }

    int getSize() {
        return this->size;
    }

    void addFirst(int element) {
        IntListNode* newNode = new IntListNode{element, head};

        if (!tail)
            tail = newNode;

        head = newNode;
        size++;
    }

    void addLast(int element) {
        IntListNode* newNode = new IntListNode{element, nullptr};

        if (!head)
            head = newNode;
        else
            tail->next = newNode;

        tail = newNode;
        size++;
    }

    void add(int element) {
        addLast(element);
    }

    void addAt(int element, int position) {
        if (position < 1 || size + 1 < position) {
            cerr << "Invalid Position." << endl;
            return;
        }

        IntListNode* newNode = new IntListNode{element, head};
        IntListNode* precedent = nullptr;

        for (int currPos = 1; currPos < position; currPos++) {
            precedent = newNode->next;
            newNode->next = precedent->next;
        }

        if (precedent)
            precedent->next = newNode;
        else
            head = newNode;

        if (newNode->next == nullptr)
            tail = newNode;

        size++;
    }

    void addSorted(int element) {
        IntListNode* newNode = new IntListNode{element, head};
        IntListNode* precedent = nullptr;

        while (newNode->next && element >= newNode->next->element) {
            precedent = newNode->next;
            newNode->next = precedent->next;
        }

        if (precedent)
            precedent->next = newNode;
        else
            head = newNode;

        if (newNode->next == nullptr)
            tail = newNode;

        size++;
    }

    int removeFirst() {
        if (!head)
            throw logic_error("Cannot do remove. The list is empty.");

        int removed = head->element;
        IntListNode* successor = head->next;
        delete head;

        head = successor;
        size--;
        return removed;
    }

    int removeLast() {
        return removeAt(size);
    }

    int remove(int element) {
        if (!head)
            throw logic_error("Cannot do remove. The list is empty.");

        IntListNode* current = head;
        IntListNode* precedent = nullptr;
        int currPos;

        for (currPos = 1; currPos <= size; currPos++) {
            if (current->element != element) {
                precedent = current;
                current = current->next;
                continue;
            }

            if (current == head)
                head = current->next;
            else
                precedent->next = current->next;

            if (current == tail)
                tail = precedent;

            delete current;
            size--;
        }

        if (currPos > this->size)
            throw logic_error("Cannot do remove. Element not found.");

        return currPos;
    }

    int removeAt(int position) {
        IntListNode* current = head;
        IntListNode* precedent = nullptr;
        int removed;

        for (int currPos = 1; currPos <= size; currPos++) {
            if (currPos != position) {
                precedent = current;
                current = current->next;
                continue;
            }

            if (current == head)
                head = current->next;
            else
                precedent->next = current->next;

            if (current == tail)
                tail = precedent;

            removed = current->element;
            delete current;
            size--;
        }

        if (!head)
            throw logic_error("Cannot do remove. The list is empty.");
        if (position < 1 || position > this->size)
            throw logic_error("Cannot do remove. Position out of bounds.");

        return removed;
    }

    int removeAll(int element) {
        IntListNode* current = head;
        IntListNode* precedent = nullptr;
        IntListNode* successor;
        int countRemoved = 0;

        for (int currPos = 1; currPos <= size; currPos++) {
            if (current->element != element) {
                precedent = current;
                current = current->next;
                continue;
            }

            if (current == head)
                head = current->next;
            else
                precedent->next = current->next;

            if (current == tail)
                tail = precedent;

            successor = current->next;
            delete current;
            current = successor;
            countRemoved++;
        }

        size -= countRemoved;
        return countRemoved;
    }

    void print() {
        IntListNode *current = head;
        cout << "Size: " << size << endl;

        for (int currPos = 1; currPos <= size; currPos++) {
            cout << current->element;
            if (current->next != nullptr)
                cout << " -> ";
            current = current->next;
        }
        cout << endl;
    }
};

class StringSinglyList {
    StringListNode* head;
    StringListNode* tail;
    int size;

public:
    StringSinglyList() {
        this->head = this->tail = nullptr;
        this->size = 0;
    }

    string getElementAt(int position) {
        if (position < 1 || size < position)
            return "";

        StringListNode* current = head;
        for (int currPos = 1; currPos < position; currPos++)
            current = current->next;

        return current->element;
    }

    int getSize() {
        return this->size;
    }

    void addFirst(const string& element) {
        StringListNode* newNode = new StringListNode{element, head};

        if (!tail)
            tail = newNode;

        head = newNode;
        size++;
    }

    void addLast(const string& element) {
        StringListNode* newNode = new StringListNode{element, nullptr};

        if (!head)
            head = newNode;
        else
            tail->next = newNode;

        tail = newNode;
        size++;
    }

    void add(const string& element) {
        addLast(element);
    }

    void addAt(const string& element, int position) {
        if (position < 1 || size + 1 < position) {
            cerr << "Invalid Position." << endl;
            return;
        }

        StringListNode* newNode = new StringListNode{element, head};
        StringListNode* precedent = nullptr;

        for (int currPos = 1; currPos < position; currPos++) {
            precedent = newNode->next;
            newNode->next = precedent->next;
        }

        if (precedent)
            precedent->next = newNode;
        else
            head = newNode;

        if (newNode->next == nullptr)
            tail = newNode;

        size++;
    }

    string removeFirst() {
        if (!head)
            return "";

        string removed = head->element;
        StringListNode* successor = head->next;
        delete head;

        head = successor;
        size--;
        return removed;
    }

    string removeLast() {
        return removeAt(size);
    }

    int remove(const string& element) {
        StringListNode* current = head;
        StringListNode* precedent = nullptr;

        for (int currPos = 1; currPos <= size; currPos++) {
            if (current->element != element) {
                precedent = current;
                current = current->next;
                continue;
            }

            if (current == head)
                head = current->next;
            else
                precedent->next = current->next;

            if (current == tail)
                tail = precedent;

            delete current;
            size--;
            return currPos;
        }

        return -1;
    }

    string removeAt(int position) {
        StringListNode* current = head;
        StringListNode* precedent = nullptr;

        for (int currPos = 1; currPos <= size; currPos++) {
            if (currPos != position) {
                precedent = current;
                current = current->next;
                continue;
            }

            if (current == head)
                head = current->next;
            else
                precedent->next = current->next;

            if (current == tail)
                tail = precedent;

            string removed = current->element;
            delete current;
            size--;
            return removed;
        }

        return "";
    }

    int removeAll(const string& element) {
        StringListNode* current = head;
        StringListNode* precedent = nullptr;
        StringListNode* successor;
        int countRemoved = 0;

        for (int currPos = 1; currPos <= size; currPos++) {
            if (current->element != element) {
                precedent = current;
                current = current->next;
                continue;
            }

            if (current == head)
                head = current->next;
            else
                precedent->next = current->next;

            if (current == tail)
                tail = precedent;

            successor = current->next;
            delete current;
            current = successor;
            countRemoved++;
        }

        size -= countRemoved;
        return countRemoved;
    }

    void print() {
        StringListNode *current = head;
        cout << "Size: " << size << endl;

        for (int currPos = 1; currPos <= size; currPos++) {
            cout << current->element;
            if (current->next != nullptr)
                cout << " -> ";
            current = current->next;
        }
        cout << endl;
    }
};
