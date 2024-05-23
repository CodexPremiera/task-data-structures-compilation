#ifndef THE_FINALS_REVIEW_AVL_TREE_H
#define THE_FINALS_REVIEW_AVL_TREE_H

#endif //THE_FINALS_REVIEW_AVL_TREE_H


class AVLTree : public BinarySearchTree {
    BinaryTree* binaryTree;

    void checkBalance(Node* startNode) {
        while (startNode != nullptr) {
            if (std::abs(startNode->getBalanceFactor()) > 1)
                restructure(startNode);
            startNode = startNode->parent;
        }
    }

public:
    explicit AVLTree() {
        binaryTree = getBinaryTree();
    }

    /* ADD METHODS */
    bool add(int element) override {
        return add(element, getRoot());
    }

    bool add(int element, Node* origin) override {
        if (!origin) {
            if (origin != getRoot())
                return false;
            setRoot(binaryTree->addRoot(element));
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

        checkBalance(origin);
        return true;
    }


    /* REMOVE METHODS */
    bool remove(int target) override {
        Node* targetNode = this->getNode(target);
        if (!targetNode)
            return false;

        Node* parent;
        try {
            parent = targetNode->parent;
            binaryTree->remove(targetNode);
        }
        catch (const exception& exception) {
            Node* minOfRight = getMinimum(targetNode->right);
            targetNode->element = minOfRight->element;
            parent = minOfRight->parent;
            binaryTree->remove(minOfRight);
        }

        checkBalance(parent);
        return true;
    }

    /* TRANSPOSITION METHODS */
    bool restructure(int gp) {
        return restructure(getNode(gp));
    }
    bool restructure(Node* gp) {
        // validate grandparent
        int gpBalanceFactor = gp->getBalanceFactor();
        if (std::abs(gpBalanceFactor) < 2)
            return false;

        // find parent
        bool parentIsRight = gpBalanceFactor <= 0;
        Node* parent = (parentIsRight) ? gp->right : gp->left;

        // find child
        int parentBalanceFactor = parent->getBalanceFactor();
        Node* child;
        if (parentIsRight)
            child = parentBalanceFactor > 0 ? parent->left : parent->right;
        else
            child = parentBalanceFactor < 0 ? parent->right : parent->left;
        bool childIsRight = parent->right == child;

        // splay
        if (parentIsRight) {
            if (childIsRight) {
                cout << "Zig Left" << endl;
                zigLeft(parent);
            } else {
                cout << "Zigzag Left" << endl;
                zigRight(child);
                zigLeft(child);
            }
        } else {
            if (!childIsRight) {
                cout << "Zig Right" << endl;
                zigRight(parent);
            } else {
                cout << "Zigzag Right" << endl;
                zigLeft(child);
                zigRight(child);
            }
        }

        return true;
    }
};