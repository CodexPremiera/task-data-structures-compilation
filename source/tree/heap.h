#ifndef THE_FINALS_REVIEW_HEAP_H
#define THE_FINALS_REVIEW_HEAP_H

#endif //THE_FINALS_REVIEW_HEAP_H

class Heap {
    IntArrayList* arrayList;

    int getLeft(int index) {
        return index * 2 + 1;
    }

    int getRight(int index) {
        return index * 2 + 2;
    }

    int getParent(int index) {
        return (index - 1) / 2;
    }

public:
    Heap() {
        arrayList = new IntArrayList();
    }

    int getMin() {
        return arrayList->getElementAt(1);
    }
    int getSize() {
        return arrayList->getSize();
    }
    int isEmpty() {
        return arrayList->getSize() == 0;
    }

    void add(int element) {
        int index = arrayList->getSize() - 1;
        int parentIndex = getParent(index);
        int parent = arrayList->getElementAt(parentIndex + 1);

        arrayList->addLast(element);

        while (element < parent) {
            arrayList->swap(index, parentIndex);
            index = parentIndex;
            parentIndex = getParent(index);
            parent = arrayList->getElementAt(parentIndex);
        }
    }

    int removeMin() {
        if (arrayList->getSize() == 0)
            return -999;
        
        arrayList->swap(0, arrayList->getSize() - 1);
        
        int size = arrayList->getSize();
        int current = 0;
        while (true) {
            int leftIndex = getLeft(current);
            int leftChild = arrayList->getElementAt(leftIndex + 1);
            
            int rightIndex = getRight(current);
            int rightChild = arrayList->getElementAt(rightIndex + 1);
            
            int smallerIndex = current;
            
            if (leftIndex < size && 
                    leftChild < arrayList->getElementAt(smallerIndex + 1))
                smallerIndex = leftIndex;

            if (rightIndex < size &&
                rightChild < arrayList->getElementAt(smallerIndex + 1))
                smallerIndex = rightIndex;

            if (smallerIndex == current)
                return arrayList->removeLast();

            arrayList->swap(current, smallerIndex);
            current = smallerIndex;
        }
    }

    void print() {
        arrayList->print();
    }
};