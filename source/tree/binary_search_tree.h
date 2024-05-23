#ifndef THE_FINALS_REVIEW_BINARY_SEARCH_TREE_H
#define THE_FINALS_REVIEW_BINARY_SEARCH_TREE_H

#endif //THE_FINALS_REVIEW_BINARY_SEARCH_TREE_H


class BinarySearchTree {
    BinaryTree* binaryTree;
    Node* root;

public:
    explicit BinarySearchTree() {
        binaryTree = new BinaryTree();
        root = binaryTree->getRoot();
    }


    /* ADD METHODS */
    virtual bool add(int element) {
        return add(element, root);
    }

    virtual bool add(int element, Node* origin) {
        if (!origin) {
            if (origin != this->root)
                return false;
            root = binaryTree->addRoot(element);
            return true;
        }

        if (element == origin->element)
            return false;

        if (element < origin->element) {
            if (origin->left)
                return add(element, origin->left);

            origin->left = binaryTree->addLeft(element, origin);
        }
        else {
            if (origin->right)
                return add(element, origin->right);

            origin->right = binaryTree->addRight(element, origin);
        }

        return true;
    }

    /* REMOVE METHODS */
    virtual bool remove(int target) {
        Node* targetNode = this->getNode(target);
        if (!targetNode)
            return false;

        try {
            binaryTree->remove(targetNode);
        }
        catch (const exception& exception) {
            Node* minOfRight = getMinimum(targetNode->right);
            targetNode->element = minOfRight->element;
            binaryTree->remove(minOfRight);
        }

        return true;
    }

    int clearTree() {
        int countRemoved = binaryTree->clearTree();
        this->root = binaryTree->getRoot();
        return countRemoved;
    }


    /* GET METHODS */
    Node* getNode(int element) {
        return getNode(element, this->binaryTree->getRoot());
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

    int getPredecessor(int element) {
        return getPredecessor(getNode(element));
    }
    int getPredecessor(Node* node) {
        if (node->left)
            return getMaximum(node->left)->element;

        while (node->isLeft())
            node = node->parent;
        return node->parent->element;
    }

    int getSuccessor(int element) {
        return getSuccessor(getNode(element));
    }
    int getSuccessor(Node* node) {
        if (node->right)
            return getMinimum(node->right)->element;

        while (node->isRight())
            node = node->parent;
        return node->parent->element;
    }

    BinaryTree* getBinaryTree() {
        return this->binaryTree;
    }
    Node* getRoot() {
        return binaryTree->getRoot();
    }
    void setRoot(Node* newRoot) {
        binaryTree->setRoot(newRoot);
        this->root = newRoot;
    }

    int getSize() {
        return binaryTree->getSize();
    }
    void setSize(int size) {
        binaryTree->setSize(size);
    }
    int getDepth(int element) {
        return binaryTree->getDepth(element);
    }
    int getHeight(int element) {
        return binaryTree->getHeight(element);
    }


    /* TRANSPOSITION METHODS */
    void zigLeft(int element) {
        this->binaryTree->zigLeft(getNode(element));
    }
    void zigLeft(Node* element) {
        this->binaryTree->zigLeft(element);
    }

    void zigRight(int element) {
        this->binaryTree->zigRight(getNode(element));
    }
    void zigRight(Node* element) {
        this->binaryTree->zigRight(element);
    }


    /* TRAVERSAL METHODS  */
    void inorderTraversal() {
        binaryTree->inorderReversedTraversal();
    }
    void preorderTraversal() {
        binaryTree->preorderTraversal();
    }
    void postorderTraversal() {
        binaryTree->postorderTraversal();
    }
    void breadthFirstTraversal() {
        binaryTree->breadthFirstTraversal();
    }

    /* CONVERT ARRAYS TO TREES */
    Node* convertPreorder(int* array, int size) {
        this->binaryTree->clearTree();
        this->binaryTree->setSize(size);

        Node* newRoot = convertPreorder(array, 0, size - 1, nullptr);
        this->binaryTree->setRoot(newRoot);

        return newRoot;
    }
    Node* convertPreorder(int* array, int start, int end, Node* parent) {
        if (end < start)
            return nullptr;

        int leftStart = start + 1;
        int leftEnd = start;
        while(array[leftEnd + 1] < array[start] && leftEnd < end)
            leftEnd++;

        int rightStart = leftEnd + 1;
        int rightEnd = end;

        Node* newNode = new Node{array[start], nullptr, nullptr, parent};
        newNode->left = convertPreorder(array, leftStart, leftEnd, newNode);
        newNode->right = convertPreorder(array, rightStart, rightEnd, newNode);

        return newNode;
    }

    Node* convertPostorder(int* array, int size) {
        binaryTree->clearTree();
        this->binaryTree->setSize(size);

        Node* newRoot = convertPostorder(array, 0, size - 1, nullptr);
        this->binaryTree->setRoot(newRoot);

        return newRoot;
    }
    Node* convertPostorder(int* array, int start, int end, Node* parent) {
        if (end < start)
            return nullptr;

        int leftStart = start;
        int leftEnd = start - 1;
        while(array[leftEnd + 1] < array[end] && leftEnd < end)
            leftEnd++;

        int rightStart = leftEnd + 1;
        int rightEnd = end - 1;

        Node* newNode = new Node{array[end], nullptr, nullptr, parent};
        newNode->left = convertPostorder(array, leftStart, leftEnd, newNode);
        newNode->right = convertPostorder(array, rightStart, rightEnd, newNode);

        return newNode;
    }
};