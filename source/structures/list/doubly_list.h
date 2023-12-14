//
// Created by Florabel Comandao on 12/14/2023.
//

#ifndef THE_FINALS_REVIEW_INT_DOUBLY_LIST_H
#define THE_FINALS_REVIEW_INT_DOUBLY_LIST_H

#endif //THE_FINALS_REVIEW_INT_DOUBLY_LIST_H

#include <iostream>
#include <cstdlib>
#include <cmath>


using namespace std;


class IntDoublyList : public IntList {
    IntListNode *head;
    IntListNode *tail;
    int size;

private:
    void addBetween(int element, IntListNode* precedent, IntListNode* successor) {
        IntListNode *newIntListNode = new IntListNode;
        newIntListNode->element = element;
        newIntListNode->next = successor;
        newIntListNode->prev = precedent;

        precedent->next = successor->prev = newIntListNode;
        size++;
    }

    void removeNode (IntListNode* targetIntListNode) {
        targetIntListNode->prev->next = targetIntListNode->next;
        targetIntListNode->next->prev = targetIntListNode->prev;
        delete targetIntListNode;
        size--;
    }

public:
    IntDoublyList() {
        head = (IntListNode*) calloc (1, sizeof(IntListNode));
        tail = (IntListNode*) calloc (1, sizeof(IntListNode));

        head->next = tail;
        tail->prev = head;

        size = 0;
    }

    int getElementAt(int position) {
        if (position < 1 || size < position)
            throw logic_error("Position out of bounds.");

        IntListNode* current;
        int centerPos = round(size / 2.0);

        if (position <= centerPos) {
            current = head->next;
            for (int i = 1; i < position; i++)
                current = current->next;
            cout << "Traversed from head." << endl;
        } else {
            current = tail;
            for (int i = size; i >= position; i--)
                current = current->prev;
            cout << "Traversed from tail." << endl;
        }

        return current->element;
    }

    int getSize() {
        return this->size;
    }

    void addFirst(int element) {
        addBetween(element, head, head->next);
    }

    void addLast(int element) {
        addBetween(element, tail->prev, tail);
    }

    void add(int element) {
        addLast(element);
    }

    void addAt(int element, int position) {
        IntListNode* current = head->next;
        IntListNode* precedent = head;

        if (position < 1 || size + 1 < position)
            return;

        for (int currPos = 1; currPos < position; currPos++) {
            precedent = current;
            current = current->next;
        }

        addBetween(element, precedent, current);
    }

    void addSorted(int element) {
        IntListNode *current;
        int distanceToHead = abs(element - head->next->element);
        int distanceToTail = abs(element - tail->prev->element);

        if (distanceToHead <= distanceToTail) {
            cout << "Adding from head" << endl;
            current = head->next;
            while (current != tail && element >= current->element)
                current = current->next;
            addBetween(element, current->prev, current);
        } else {
            cout << "Adding from tail" << endl;
            current = tail->prev;
            while (current != head && element < current->element)
                current = current->prev;
            addBetween(element, current, current->next);
        }
    }

    int removeFirst() {
        return removeAt(1);
    }

    int removeLast() {
        return removeAt(size);
    }

    int remove(int element) {
        IntListNode* current = head->next;

        int currPos = 1;
        while(currPos <= size && current->element != element) {
            current = current->next;
            currPos++;
        }

        if (!head)
            throw logic_error("Cannot do remove. The list is empty.");
        if (currPos > this->size)
            throw logic_error("Cannot do remove. Element not found.");

        removeNode(current);
        return currPos;
    }


    int removeAt(int position) {
        IntListNode* current = head->next;

        int currPos = 1;
        while(currPos <= size && currPos != position) {
            current = current->next;
            currPos++;
        }

        if (!head)
            throw logic_error("Cannot do remove. The list is empty.");
        if (position < 1 || position > this->size)
            throw logic_error("Cannot do remove. Position out of bounds.");

        int removed = current->element;
        removeNode(current);
        return removed;
    }

    int removeAll(int element) {
        IntListNode* current = head->next;
        IntListNode* precedent = head;
        IntListNode* successor;
        int countRemoved = 0;

        for (int currPos = 1; currPos < size; currPos++) {
            successor = current->next;
            if (current->element == element) {
                delete current;
                current = successor;
                successor = successor->next;
                countRemoved++;

                if (current != tail) continue;
            }

            if (current->prev != precedent) {
                precedent->next = current;
                current->prev = precedent;
            }

            precedent = current;
            current = successor;
        }

        size -= countRemoved;
        return countRemoved;
    }

    int retainCorner(int amountFront, int amountRear) {
        IntListNode* frontEnd = head;
        for (int currPos = 1; currPos <= amountFront; currPos++)
            frontEnd = frontEnd->next;

        IntListNode* rearEnd = tail;
        for (int currPos = 1; currPos <= amountRear; currPos++)
            rearEnd = rearEnd->prev;

        IntListNode* toDelete = frontEnd->next;
        IntListNode* nextDelete;
        int countDeleted = 0;
        while (toDelete != rearEnd) {
            nextDelete = toDelete->next;
            delete toDelete;
            toDelete = nextDelete;
            countDeleted++;
        }

        frontEnd->next = rearEnd;
        rearEnd->prev = frontEnd;

        size -= countDeleted;
        return countDeleted;
    }

    void print() {
        cout << "Size: " << size << endl;

        IntListNode *current = head->next;
        for (int currPos = 1; currPos <= size; currPos++) {
            cout << current->element;
            if (current->next != tail)
                cout << " -> ";
            current = current->next;
        }
        cout << endl;

        current = tail->prev;
        for (int currPos = 1; currPos <= size; currPos++) {
            cout << current->element;
            if (current->prev != head)
                cout << " <- ";
            current = current->prev;
        }
        cout << endl;
    }
};
