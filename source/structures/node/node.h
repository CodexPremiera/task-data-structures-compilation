//
// Created by Florabel Comandao on 12/14/2023.
//

#ifndef THE_FINALS_REVIEW_NODE_H
#define THE_FINALS_REVIEW_NODE_H

#endif //THE_FINALS_REVIEW_NODE_H

#include <iostream>
#include <algorithm>
using namespace std;

struct IntListNode {
    int element;
    IntListNode* next;
    IntListNode* prev;
};

struct StringListNode {
    string element;
    StringListNode* next;
    StringListNode* prev;
};

struct Node {
    int element;
    Node* left;
    Node* right;
    Node* parent;

    int getDepth() {
        if (!parent)
            return 0;
        return 1 + parent->getDepth();
    }

    int getHeight() {
        if (!left && !right)
            return 0;

        int leftHeight = (left) ? left->getHeight() : 0;
        int rightHeight = (right) ? right->getHeight() : 0;

        return 1 + max(leftHeight, rightHeight);
    }

    Node* getSibling() {
        if (!parent)
            return nullptr;

        if (this == parent->left)
            return parent->right;
        else
            return parent->left;
    }
    bool hasSibling() {
        if (!parent)
            return false;

        if (this == parent->left)
            return parent->right != nullptr;
        else
            return parent->left != nullptr;
    }

    bool isLeft() {
        if (parent)
            return this == parent->left;
        return false;
    }
    bool isRight() {
        if (parent)
            return this == parent->right;
        return false;
    }
};
