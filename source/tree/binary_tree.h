//
// Created by Florabel Comandao on 12/14/2023.
//

#ifndef THE_FINALS_REVIEW_BINARY_TREE_H
#define THE_FINALS_REVIEW_BINARY_TREE_H

#endif //THE_FINALS_REVIEW_BINARY_TREE_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class BinaryTree {
private:
    Node* root;
    int size;

public:
    BinaryTree() {
        this->root = nullptr;
        this->size = 0;
    }
    ~BinaryTree() {
        this->clearTree();
    }

    /* ADD METHODS */
    Node* addRoot(int element) {
        if (this->root)
            throw logic_error("Root already exists.");

        this->root = new Node{element, nullptr, nullptr, nullptr};
        size++;
        return this->root;
    }

    Node* addLeft(int element, int parent) {
        return addLeft(element, this->getNodeByElement(parent));
    }
    Node* addLeft(int element, Node* parent) {
        if (!parent)
            return nullptr;
        if (parent->left)
            throw logic_error("Left child already exists.");

        parent->left = new Node{element, nullptr, nullptr, parent};
        size++;
        return parent->left;
    }

    Node* addRight(int element, int parent) {
        return addRight(element, this->getNodeByElement(parent));
    }
    Node* addRight(int element, Node* parent) {
        if (!parent)
            return nullptr;
        if (parent->right)
            throw logic_error("Right child already exists.");

        parent->right = new Node{element, nullptr, nullptr, parent};
        size++;
        return parent->right;
    }

    /* REMOVE METHODS */
    int remove(int target) {
        return remove(getNodeByElement(target));
    }
    int remove(Node* target) {
        if (!target) {
            cout << "Cannot remove a null node.";
            return -9999999;
        }
        if (target->left && target->right)
            throw logic_error("Cannot remove a full node.");

        int removedElement = target->element;
        Node* parent = target->parent;
        Node* child = (target->left) ? target->left : target->right;

        if (target == this->root)
            this->root = child;
        else if (parent->left == target)
            parent->left = child;
        else
            parent->right = child;

        if (child)
            child->parent = parent;

        delete target;
        size--;
        return removedElement;
    }

    int clearTree() {
        int nodesRemoved = clearTree(this->root);
        this->root = nullptr;
        return nodesRemoved;
    }
    int clearTree(Node* subtreeRoot) {
        if (!subtreeRoot)
            return 0;

        int clearedLeft = clearTree(subtreeRoot->left);
        int clearedRight = clearTree(subtreeRoot->right);

        delete subtreeRoot;
        size--;
        return 1 + clearedLeft + clearedRight;
    }


    /* SET AND GET METHODS */
    void setRoot(Node* newRoot) {
        this->root = newRoot;
    }
    void setSize(int newSize) {
        this->size = newSize;
    }

    Node* getRoot() {
        return this->root;
    }

    Node* getLeft(int element) {
        return getLeft(getNodeByElement(element));
    }
    Node* getLeft(Node* parent) {
        return (parent) ? parent->left : nullptr;
    }

    Node* getRight(int element) {
        return getRight(getNodeByElement(element));
    }
    Node* getRight(Node* parent) {
        return (parent) ? parent->right : nullptr;
    }

    Node* getSibling(int element) {
        return getSibling(getNodeByElement(element));
    }
    Node* getSibling(Node* target) {
        return (target) ? target->getSibling() : nullptr;
    }

    Node* getNodeByElement(int element) {
        return getNodeByElement(element, this->root);
    }
    Node* getNodeByElement(int element, Node* origin) {
        if (!origin || origin->element == element)
            return origin; // Element found or reached a leaf

        Node* isFoundLeft = getNodeByElement(element, origin->left);
        if (isFoundLeft)
            return isFoundLeft;

        return getNodeByElement(element, origin->right); // Element found in the right subtree (or not found)
    }

    int getSize() {
        return this->size;
    }

    int getDepth(int element) {
        return getNodeByElement(element)->getDepth();
    }

    int getHeight(int element) {
        return getNodeByElement(element)->getHeight();
    }


    /* TRANSPOSITION METHODS */
    void zig(Node* curr, bool isLeft) {
        // check parent
        Node* parent = curr->parent;
        if (parent == nullptr)
            throw runtime_error("Cannot perform zig if the parent node is null");

        // handle grandparent
        Node* grandparent = parent->parent;
        if (grandparent == nullptr)
            root = curr;
        else if (parent->isLeft())
            grandparent->left = curr;
        else
            grandparent->right = curr;
        curr->parent = grandparent;

        // handle child relationships
        Node* detached;
        if (isLeft) {
            detached = curr->left;
            curr->left = parent;
            parent->right = detached;
        } else {
            detached = curr->right;
            curr->right = parent;
            parent->left = detached;
        }

        // handle parent relationships
        if (detached != nullptr)
            detached->parent = parent;
        parent->parent = curr;
    }

    void zigLeft(Node* curr) {
        zig(curr, true);
    }

    void zigRight(Node* curr) {
        zig(curr, false);
    }


    /* TRAVERSAL METHODS */
    void preorderTraversal() {
        if (!this->root)
            cout << "Tree is empty." << endl;
        else {
            cout << "Preorder Traversal: " << endl;
            preorderTraversal(this->root, "");
            cout << endl;
        }
    }
    void preorderTraversal (Node* current, string padding) {
        if (current) {
            string arrowConnector;
            cout << padding;

            if (current->parent) {
                if (current->isLeft() && current->hasSibling()) {
                    padding += " |    ";
                    arrowConnector += " |--->";
                } else {
                    padding += "      ";
                    arrowConnector += " `--->";
                }
            }

            cout << arrowConnector << setw(2) << current->element << endl;
            preorderTraversal(current->left, padding);
            preorderTraversal(current->right, padding);
        }
    }

    void inorderTraversal() {
        cout << "Inorder Traversal: " << endl;
        inorderTraversal(this->root, "");
        cout << endl;
    }
    void inorderTraversal(Node* current, string padding) {
        if (current) {
            string splitConnector = (current->left || current->right) ? " -|" : "";
            string arrowConnector;

            if (current->getDepth() > 1) {
                if (current->parent->isLeft() && current->isRight() ||
                    current->parent->isRight() && current->isLeft())
                    padding += " |  ";
                else
                    padding += "    ";
            }

            if (current->parent) {
                padding += "   ";
                if (current->isLeft())
                    arrowConnector = " ,->";
                else
                    arrowConnector = " `->";
            }

            inorderTraversal(current->left, padding);
            cout << padding << arrowConnector << setw(2) << current->element << splitConnector << endl;
            inorderTraversal(current->right, padding);
        }
    }

    void inorderReversedTraversal() {
        cout << "Inorder Reversed Traversal: " << endl;
        inorderReversedTraversal(this->root, "");
        cout << endl;
    }
    void inorderReversedTraversal(Node* current, string padding) {
        if (current) {
            string splitConnector = (current->left || current->right) ? " -|" : "";
            string arrowConnector;

            if (current->getDepth() > 1) {
                if (current->parent->isLeft() && current->isRight() ||
                    current->parent->isRight() && current->isLeft())
                    padding += " |  ";
                else
                    padding += "    ";
            }

            if (current->parent) {
                padding += "   ";
                if (current->isRight())
                    arrowConnector = " ,->";
                else
                    arrowConnector = " `->";
            }

            inorderReversedTraversal(current->right, padding);
            cout << padding << arrowConnector << setw(2) << current->element << splitConnector << endl;
            inorderReversedTraversal(current->left, padding);
        }
    }

    void postorderTraversal() {
        cout << "Postorder Traversal: " << endl;
        postorderTraversal(this->root, "");
        cout << endl;
    }
    void postorderTraversal(Node* current, string padding) {
        if (current) {
            string arrowConnector;

            if (current->getDepth() > 1) {
                if ( current->parent->isRight() && current->parent->hasSibling() )
                    padding += " |    ";
                else
                    padding += "      ";
            }

            if (current->parent) {
                if (current->isRight() && current->hasSibling())
                    arrowConnector += " |--->";
                else
                    arrowConnector += " ,--->";
            }

            postorderTraversal(current->left, padding);
            postorderTraversal(current->right, padding);
            cout << padding << arrowConnector << setw(2) << current->element << endl;
        }
    }

    void breadthFirstTraversal() {
        cout << "Breadth First Traversal: ";
        breadthFirstTraversal(this->root);
        cout << endl;
    }
    static void breadthFirstTraversal(Node* origin) {
        auto* queue = new NodeQueue();
        queue->enqueue(origin);

        while(!queue->isEmpty()) {
            origin = queue->dequeue();
            cout << origin->element << " ";

            if (origin->left)
                queue->enqueue(origin->left);
            if (origin->right)
                queue->enqueue(origin->right);
        }
    }
};
