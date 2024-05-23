#ifndef THE_FINALS_REVIEW_AVL_TREE_H
#define THE_FINALS_REVIEW_AVL_TREE_H

#endif //THE_FINALS_REVIEW_AVL_TREE_H


class RedBlackTree {
private:
    Node* root;
    int size;

public:
    explicit RedBlackTree() {
        this->root = nullptr;
        this->size = 0;
    }

    /* INSERTION METHODS */
    bool insert(int element) {
        Node* newNode = new Node{element, nullptr, nullptr, nullptr, true};

        if (!root) {
            newNode->isRed = false;
            root = newNode;
            size++;
            return true;
        }

        return insert(newNode, root);
    }

    bool insert(Node* newNode, Node* origin) {
        if (newNode->element < origin->element) {
            if (origin->left)
                return insert(newNode, origin->left);
            origin->left = newNode;
            newNode->parent = origin;
        }
        else {
            if (origin->right)
                return insert(newNode, origin->right);
            origin->right = newNode;
            newNode->parent = origin;
        }

        size++;
        return checkViolation(newNode);
    }

    /* DELETION METHODS */
    bool remove(int target) {
        Node* targetNode = this->getNode(target);
        if (!targetNode)
            return false;

        try {
            remove(targetNode);
        }
        catch (const exception& exception) {
            Node* minOfRight = getMinimum(targetNode->right);
            targetNode->element = minOfRight->element;
            remove(minOfRight);
        }

        return true;
    }

    bool remove(Node* targetNode) {
        if (!targetNode) {
            cout << "Cannot remove a null node.";
            return false;
        }
        if (targetNode->left && targetNode->right)
            throw logic_error("Cannot remove a full node.");

        Node* parent = targetNode->parent;
        Node* child = (targetNode->left) ? targetNode->left : targetNode->right;

        if (targetNode == this->root)
            this->root = child;
        else if (parent->left == targetNode)
            parent->left = child;
        else
            parent->right = child;

        if (child)
            child->parent = parent;




        delete targetNode;
        size--;
        return true;
    }


    /* GET METHODS */
    Node* getNode(int element) {
        return getNode(element, this->root);
    }
    Node* getNode(int element, Node* origin) {
        if (!origin || origin->element == element)
            return origin;

        Node* nextNode = (element < origin->element) ? origin->left : origin->right;
        return (nextNode) ? getNode(element, nextNode) : nullptr;
    }

    Node* getMinimum(Node* origin = nullptr) {
        return (origin && origin->left) ? getMinimum(origin->left) : origin;
    }

    Node* getMaximum(Node* origin = nullptr) {
        return (origin && origin->right) ? getMaximum(origin->right) : origin;
    }

    int getSize() {
        return this->size;
    }



    bool checkViolation(Node* newNode) {
        if (newNode == root)
            return true;

        Node* parentNode = newNode->parent;
        if(!parentNode->isRed || !newNode->isRed)
            return checkViolation(newNode->parent);

        Node* gpNode = parentNode->parent;
        Node* uncleNode = (gpNode->left == parentNode) ? gpNode->right : gpNode->left;

        if (uncleNode == nullptr || !uncleNode->isRed) { // if black uncle, restructure
            cout << "INSERTION Violation: Case 1" << endl;
            restructure(newNode);
        }
        else { // if red uncle, recolor
            cout << "INSERTION Violation: Case 2" << endl;
            if (gpNode != root)
                gpNode->isRed = true;
            parentNode->isRed = false;
            uncleNode->isRed = false;
        }

        return checkViolation(newNode);
    }


    /* TRANSPOSITION METHODS */
    void restructure(Node* child) {
        Node* parent = child->parent;
        Node* gParent = parent->parent;

        bool parentIsRight = gParent->right == parent;
        bool childIsRight = parent->right == child;


        if (parentIsRight) {
            if (childIsRight) {
                cout << "ZIG LEFT" << endl;
                zigLeft(parent);
                parent->isRed = false;
            } else {
                cout << "ZIGZAG LEFT" << endl;
                zigRight(child);
                zigLeft(child);
                child->isRed = false;
            }
        } else {
            if (!childIsRight) {
                cout << "ZIG RIGHT" << endl;
                zigRight(parent);
                parent->isRed = false;
            } else {
                cout << "ZIGZAG RIGHT" << endl;
                zigLeft(child);
                zigRight(child);
                child->isRed = false;
            }
        }

        gParent->isRed = true;
    }

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
                    padding += "   |    ";
                    arrowConnector += "   |--->";
                } else {
                    padding += "        ";
                    arrowConnector += "   `--->";
                }
            }

            char open = current->isRed ? '(' : '[';
            char close = current->isRed ? ')' : ']';
            cout << arrowConnector << open << setw(2) << current->element << close << endl;
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
                    padding += "   |  ";
                else
                    padding += "      ";
            }

            if (current->parent) {
                padding += "   ";
                if (current->isLeft())
                    arrowConnector = "   ,->";
                else
                    arrowConnector = "   `->";
            }

            inorderTraversal(current->left, padding);
            char open = current->isRed ? '(' : '[';
            char close = current->isRed ? ')' : ']';
            cout << padding << arrowConnector << setw(2) << open << current->element << close << splitConnector << endl;
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
                    padding += "   |  ";
                else
                    padding += "      ";
            }

            if (current->parent) {
                padding += "   ";
                if (current->isRight())
                    arrowConnector = "   ,->";
                else
                    arrowConnector = "   `->";
            }

            inorderReversedTraversal(current->right, padding);
            char open = current->isRed ? '(' : '[';
            char close = current->isRed ? ')' : ']';
            cout << padding << arrowConnector << open << setw(2) << current->element << close << splitConnector << endl;
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
                    padding += "   |    ";
                else
                    padding += "        ";
            }

            if (current->parent) {
                if (current->isRight() && current->hasSibling())
                    arrowConnector += "   |--->";
                else
                    arrowConnector += "   ,--->";
            }

            postorderTraversal(current->left, padding);
            postorderTraversal(current->right, padding);
            char open = current->isRed ? '(' : '[';
            char close = current->isRed ? ')' : ']';
            cout << padding << arrowConnector << open << setw(2) << current->element << close << endl;
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