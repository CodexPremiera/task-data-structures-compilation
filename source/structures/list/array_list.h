//
// Created by Florabel Comandao on 12/14/2023.
//

#ifndef THE_FINALS_REVIEW_ARRAY_LIST_H
#define THE_FINALS_REVIEW_ARRAY_LIST_H

#endif //THE_FINALS_REVIEW_ARRAY_LIST_H

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;


class IntArrayList : public IntList {
private:
    int *array;
    int capacity;
    int size;

    void reallocate() {
        array = static_cast<int*>( realloc(array, capacity*sizeof(int)) );

        for (int i = size; i < capacity; i++)
            array[i] = 0;
    }

    void checkCapacity()  {
        const int floor = capacity * (2.0/3.0);

        if (floor < size && size < capacity)
            return;

        if (size >= capacity)
            capacity = ceil(capacity * 1.5);
        else {
            capacity = ceil(capacity * 0.75);
            if (capacity <= 5)
                capacity = 5;
        }
        reallocate();
    }

public:
    IntArrayList() {
        this->size = 0;
        this->capacity = 5;
        this->array = static_cast<int*>( calloc(capacity, sizeof(int)) );
    }

    int getElementAt(int position) {
        if (position < 1 || position > size)
            throw logic_error("Position out of bounds.");

        return array[position - 1];
    }

    int getSize() {
        return this->size;
    }

    void addFirst(int element) {
        addAt(element, 1);
    }

    void addLast(int element) {
        checkCapacity();
        array[size++] = element;
    }

    void add(int element) {
        addLast(element);
    }

    void addAt(int element, int position) {
        if (position < 1 || position > size + 1)
            return;

        checkCapacity();
        int index = position - 1;
        for (int i = size; i > index; i--)
            array[i] = array[i - 1];
        array[index] = element;
        size++;
    }

    void addSorted(int element) {
        int currIndex;
        int distanceToHead = abs(element - array[0]);
        int distanceToTail = abs(element - array[size - 1]);

        if (distanceToHead <= distanceToTail) {
            cout << "Adding from head" << endl;
            currIndex = 0;
            while (currIndex != size && element >= array[currIndex])
                currIndex++;
        } else {
            cout << "Adding from tail" << endl;
            currIndex = size;
            while (currIndex != 0 && element < array[currIndex - 1])
                currIndex--;
        }

        addAt(element, currIndex + 1);
    }

    void swap(int index1, int index2) {
        int temp = array[index1];
        array[index1] = array[index2];
        array[index2] = temp;
    }

    int removeFirst() {
        return removeAt(1);
    }

    int removeLast() {
        if (this->size <= 0)
            throw logic_error("Cannot do remove. The list is empty.");

        int removed = array[size - 1];
        array[size - 1] = 0;
        size--;
        checkCapacity();
        return removed;
    }

    int remove(int element) {
        if (this->size <= 0)
            throw logic_error("Cannot do remove. The list is empty.");

        int position = 1;
        while (position <= size && array[position - 1] != element) {
            position++;
        }

        if (position > this->size)
            throw logic_error("Cannot do remove. Element not found.");

        removeAt(position);
        return position;
    }

    int removeAt(int position) {
        if (this->size <= 0)
            throw logic_error("Cannot do remove. The list is empty.");
        if (position < 1 || size < position)
            throw logic_error("Cannot do remove. Position out of bounds.");

        int index = position - 1;
        int removed = array[index];

        for (int i = index; i < size; i++)
            array[i] = array[i + 1];
        array[size] = 0;

        size--;
        checkCapacity();
        return removed;
    }

    int removeAll(int element) {
        int current = 0;
        int precedent = 0;
        int countRemove = 0;

        for (current; current < size; current++) {
            if (array[current] == element)
                countRemove++;
            else {
                array[precedent] = array[current];
                precedent++;
            }
        }

        for (current; current < capacity; current++)
            array[current] = 0;

        size -= countRemove;
        checkCapacity();
        return countRemove;
    }

    void print () {
        if (this->size == 0) {
            cout << "The list is empty." << endl;
            return;
        }
        cout << "Size: " << size << endl;

        for(int i = 0; i < capacity; i++) {
            if (i < size)
                cout << array[i];
            else
                cout << ".";
            cout << " ";
        }
        cout << endl;

    }
};

class CharArrayList {
private:
    char *array;
    int capacity;
    int size;

    void reallocate() {
        array = static_cast<char*>( realloc(array, capacity*sizeof(char)) );

        for (int i = size; i < capacity; i++)
            array[i] = 0;
    }

    void checkCapacity()  {
        const int floor = capacity * (2.0/3.0);

        if (floor < size && size < capacity)
            return;

        if (size >= capacity)
            capacity = ceil(capacity * 1.5);
        else {
            capacity = ceil(capacity * 0.75);
            if (capacity <= 5)
                capacity = 5;
        }
        reallocate();
    }

public:
    CharArrayList() {
        this->size = 0;
        this->capacity = 5;
        this->array = static_cast<char*>( calloc(capacity, sizeof(char)) );
    }

    char getElementAt(int position) {
        if (position < 1 || position > size)
            throw logic_error("Position out of bounds.");

        return array[position - 1];
    }

    int getSize() {
        return this->size;
    }

    void addFirst(char element) {
        addAt(element, 1);
    }

    void addLast(char element) {
        checkCapacity();
        array[size++] = element;
    }

    void add(char element) {
        addLast(element);
    }

    void addAt(char element, int position) {
        if (position < 1 || position > size + 1)
            return;

        checkCapacity();
        int index = position - 1;
        for (int i = size; i > index; i--)
            array[i] = array[i - 1];
        array[index] = element;
        size++;
    }

    void addSorted(char element) {
        int currIndex;
        int distanceToHead = abs(element - array[0]);
        int distanceToTail = abs(element - array[size - 1]);

        if (distanceToHead <= distanceToTail) {
            cout << "Adding from head" << endl;
            currIndex = 0;
            while (currIndex != size && element >= array[currIndex])
                currIndex++;
        } else {
            cout << "Adding from tail" << endl;
            currIndex = size;
            while (currIndex != 0 && element < array[currIndex - 1])
                currIndex--;
        }

        addAt(element, currIndex + 1);
    }

    char removeFirst() {
        return removeAt(1);
    }

    char removeLast() {
        if (this->size <= 0)
            throw logic_error("Cannot do remove. The list is empty.");

        int removed = array[size - 1];
        array[size - 1] = 0;
        size--;
        checkCapacity();
        return removed;
    }

    int remove(char element) {
        if (this->size <= 0)
            throw logic_error("Cannot do remove. The list is empty.");

        int position = 1;
        while (position <= size && array[position - 1] != element) {
            position++;
        }

        if (position > this->size)
            throw logic_error("Cannot do remove. Element not found.");

        removeAt(position);
        return position;
    }

    char removeAt(int position) {
        if (this->size <= 0)
            throw logic_error("Cannot do remove. The list is empty.");
        if (position < 1 || size < position)
            throw logic_error("Cannot do remove. Position out of bounds.");

        int index = position - 1;
        char removed = array[index];

        for (int i = index; i < size; i++)
            array[i] = array[i + 1];
        array[size] = 0;

        size--;
        checkCapacity();
        return removed;
    }

    int removeAll(char element) {
        int current = 0;
        int precedent = 0;
        int countRemove = 0;

        for (current; current < size; current++) {
            if (array[current] == element)
                countRemove++;
            else {
                array[precedent] = array[current];
                precedent++;
            }
        }

        for (current; current < capacity; current++)
            array[current] = 0;

        size -= countRemove;
        checkCapacity();
        return countRemove;
    }

    void print () {
        if (this->size == 0) {
            cout << "The list is empty." << endl;
            return;
        }
        cout << "Size: " << size << endl;

        for(int i = 0; i < capacity; i++) {
            if (i < size)
                cout << array[i];
            else
                cout << ".";
            cout << " ";
        }
        cout << endl;

    }
};

class NodeArrayList {
private:
    Node** array;
    int capacity;
    int size;

    void reallocate() {
        array = static_cast<Node**>( realloc(array, capacity*sizeof(Node)) );

        for (int i = size; i < capacity; i++)
            array[i] = 0;
    }

    void checkCapacity()  {
        const int floor = capacity * (2.0/3.0);

        if (floor < size && size < capacity)
            return;

        if (size >= capacity)
            capacity = ceil(capacity * 1.5);
        else {
            capacity = ceil(capacity * 0.75);
            if (capacity <= 5)
                capacity = 5;
        }
        reallocate();
    }

public:
    NodeArrayList() {
        this->size = 0;
        this->capacity = 5;
        this->array = static_cast<Node**>( calloc(capacity, sizeof(Node)) );
    }

    Node* getElementAt(int position) {
        if (position < 1 || size < position)
            return nullptr;

        return array[position - 1];
    }

    int getSize() {
        return this->size;
    }

    void addFirst(Node* element) {
        addAt(element, 1);
    }

    void addLast(Node* element) {
        checkCapacity();
        array[size++] = element;
    }

    void add(Node* element) {
        addLast(element);
    }

    void addAt(Node* element, int position) {
        if (position < 1 || position > size + 1)
            return;

        checkCapacity();
        int index = position - 1;
        for (int i = size; i > index; i--)
            array[i] = array[i - 1];
        array[index] = element;
        size++;
    }

    Node* removeFirst() {
        return removeAt(1);
    }

    Node* removeLast() {
        Node* removed = array[size - 1];
        array[size - 1] = nullptr;
        size--;
        checkCapacity();
        return removed;
    }

    int remove(int element) {
        for (int position = 1; position <= size; position++) {
            if(array[position - 1]->element == element) {
                removeAt(position);
                return position;
            }
        }
        return -999;
    }

    Node* removeAt(int position) {
        if (position < 1 || size < position)
            return nullptr;

        int index = position - 1;
        Node* removed = array[index];

        for (int i = index; i < size; i++)
            array[i] = array[i + 1];
        array[size] = nullptr;

        size--;
        checkCapacity();
        return removed;
    }

    int removeAll(int element) {
        int current = 0;
        int precedent = 0;
        int countRemove = 0;

        for (current; current < size; current++) {
            if (array[current]->element == element)
                countRemove++;
            else {
                array[precedent] = array[current];
                precedent++;
            }
        }

        for (current; current < capacity; current++)
            array[current] = nullptr;

        size -= countRemove;
        checkCapacity();
        return countRemove;
    }

    void print () {
        if (this->size == 0) {
            cout << "The list is empty." << endl;
            return;
        }
        cout << "Size: " << size << endl;

        for(int i = 0; i < capacity; i++) {
            if (i < size)
                cout << array[i]->element;
            else
                cout << ".";
            cout << " ";
        }
        cout << endl;

    }
};

class StringArrayList {
private:
    string* array;
    int capacity;
    int size;

    void reallocate() {
        array = static_cast<string*>( realloc(array, capacity*sizeof(string)) );

        for (int i = size; i < capacity; i++)
            array[i] = "";
    }

    void checkCapacity()  {
        const int floor = capacity * (2.0/3.0);

        if (floor < size && size < capacity)
            return;

        if (size >= capacity)
            capacity = ceil(capacity * 1.5);
        else {
            capacity = ceil(capacity * 0.75);
            if (capacity <= 5)
                capacity = 5;
        }
        reallocate();
    }

public:
    StringArrayList() {
        this->size = 0;
        this->capacity = 5;
        this->array = static_cast<string*>( calloc(capacity, sizeof(string)) );
    }

    string getElementAt(int position) {
        if (position < 1 || size < position)
            return "";

        return array[position - 1];
    }

    int getSize() {
        return this->size;
    }

    void addFirst(const string& element) {
        addAt(element, 1);
    }

    void addLast(const string& element) {
        checkCapacity();
        array[size++] = element;
    }

    void add(const string& element) {
        addLast(element);
    }

    void addAt(const string& element, int position) {
        if (position < 1 || position > size + 1)
            return;

        checkCapacity();
        int index = position - 1;
        for (int i = size; i > index; i--)
            array[i] = array[i - 1];
        array[index] = element;
        size++;
    }

    string removeFirst() {
        return removeAt(1);
    }

    string removeLast() {
        string removed = array[size - 1];
        array[size - 1] = "";
        size--;
        checkCapacity();
        return removed;
    }

    int remove(const string& element) {
        for (int position = 1; position <= size; position++) {
            if(array[position - 1] == element) {
                removeAt(position);
                return position;
            }
        }
        return -999;
    }

    string removeAt(int position) {
        if (position < 1 || size < position)
            return "";

        int index = position - 1;
        string removed = array[index];

        for (int i = index; i < size; i++)
            array[i] = array[i + 1];
        array[size] = "";

        size--;
        checkCapacity();
        return removed;
    }

    int removeAll(const string& element) {
        int current = 0;
        int precedent = 0;
        int countRemove = 0;

        for (current; current < size; current++) {
            if (array[current] == element)
                countRemove++;
            else {
                array[precedent] = array[current];
                precedent++;
            }
        }

        for (current; current < capacity; current++)
            array[current] = "";

        size -= countRemove;
        checkCapacity();
        return countRemove;
    }

    void print () {
        if (this->size == 0) {
            cout << "The list is empty." << endl;
            return;
        }
        cout << "Size: " << size << endl;

        for(int i = 0; i < capacity; i++) {
            if (i < size)
                cout << array[i];
            else
                cout << ".";
            cout << " ";
        }
        cout << endl;

    }
};
