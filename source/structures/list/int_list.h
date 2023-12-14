//
// Created by Florabel Comandao on 12/14/2023.
//

#ifndef THE_FINALS_REVIEW_LIST_H
#define THE_FINALS_REVIEW_LIST_H

#endif //THE_FINALS_REVIEW_LIST_H

class IntList {
public:
    virtual int getElementAt(int position) = 0;
    virtual int getSize() = 0;

    virtual void addFirst(int element) = 0;
    virtual void addLast(int element) = 0;
    virtual void add(int element) = 0;
    virtual void addAt(int element, int position) = 0;
    virtual void addSorted(int element) = 0;

    virtual int removeFirst() = 0;
    virtual int removeLast() = 0;
    virtual int remove(int element) = 0;
    virtual int removeAt(int position) = 0;
    virtual int removeAll(int element) = 0;

    virtual void print() = 0;
};
