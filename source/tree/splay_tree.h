#ifndef THE_FINALS_REVIEW_SPLAY_TREE_H
#define THE_FINALS_REVIEW_SPLAY_TREE_H

#endif //THE_FINALS_REVIEW_SPLAY_TREE_H


class SplayTree : public BinarySearchTree {
    BinaryTree* binaryTree;

public:
    explicit SplayTree() {
        binaryTree = getBinaryTree();
    }

    /* SEARCH METHOD */
    Node* search(int element) {
        Node* found = search(element, this->binaryTree->getRoot());
        splay(found);
        return found;
    }
    Node* search(int element, Node* origin) {
        if (!origin || origin->element == element)
            return origin;

        Node* nextNode = (element < origin->element) ? origin->left : origin->right;
        return (nextNode) ? search(element, nextNode) : origin;
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
            splay(origin->left);
        }
        else {
            if (origin->right)
                return add(element, origin->right);

            origin->right = binaryTree->addRight(element, origin);
            splay(origin->right);
        }

        return true;
    }


    /* REMOVE METHODS */
    bool remove(int target) override {
        Node* targetNode = search(target);
        cout << getRoot()->element << endl;
        cout << targetNode->element << endl;

        if (targetNode->element != target)
            return false;

        if (!targetNode->left && !targetNode->right)  {
            setRoot(nullptr);
        }
        else if (targetNode->left && targetNode->right) {
            Node* maxOfLeft = getMaximum(targetNode->left);
            splay(maxOfLeft);
            attach(targetNode->parent, targetNode->right);
        }
        else if (targetNode->right) {
            setRoot(targetNode->right);
            targetNode->right->parent = nullptr;
        }
        else {
            setRoot(targetNode->left);
            targetNode->left->parent = nullptr;
        }

        cout << "targetNode: " << targetNode->element << endl;
        delete targetNode;
        setSize(getSize() - 1);
        return true;
    }

    void attach(Node* gp, Node* child) {
        if (gp != nullptr)
            gp->right = child;

        if (child != nullptr)
            child->parent = gp;
    }


    /* TRANSPOSITION METHODS */
    bool splay(int gp) {
        return splay(getNode(gp));
    }
    bool splay(Node* child) {
        if (child == nullptr)
            return false;

        if (child->parent == nullptr)
            return false;

        // splay
        while (child != getRoot()) {
            Node* parent = child->parent;
            Node* gParent = parent->parent;

            if (child->isRight()) {
                if (gParent == nullptr)
                    zigLeft(child);
                else if (parent->isRight()) {
                    zigLeft(parent);
                    zigLeft(child);
                } else {
                    zigLeft(child);
                    zigRight(child);
                }
            } else {
                if (gParent == nullptr)
                    zigRight(child);
                else if (parent->isLeft()) {
                    zigRight(parent);
                    zigRight(child);
                } else {
                    zigRight(child);
                    zigLeft(child);
                }
            }
        }

        return true;
    }
};