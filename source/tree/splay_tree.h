#ifndef THE_FINALS_REVIEW_SPLAY_TREE_H
#define THE_FINALS_REVIEW_SPLAY_TREE_H

#endif //THE_FINALS_REVIEW_SPLAY_TREE_H


class SplayTree : public BinarySearchTree {
    BinaryTree* binaryTree;

public:
    explicit SplayTree() {
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
            restructure(origin->left);
        }
        else {
            if (origin->right)
                return add(element, origin->right);

            origin->right = binaryTree->addRight(element, origin);
            restructure(origin->right);
        }

        return true;
    }


    /* TRANSPOSITION METHODS */
    bool restructure(int gp) {
        return restructure(getNode(gp));
    }
    bool restructure(Node* child) {
        if (child->parent == nullptr)
            return false;

        // restructure
        while (child->parent != nullptr) {
            Node* parent = child->parent;
            Node* gParent = parent->parent;

            if (child->isRight()) {
                if (gParent == nullptr)
                    zigLeft(child);
                else if (parent->isRight()) {
                    zigLeft(parent);
                    zigLeft(child);
                } else {
                    zigRight(child);
                    zigLeft(child);
                }
            } else {
                if (gParent == nullptr)
                    zigRight(child);
                else if (parent->isLeft()) {
                    zigRight(parent);
                    zigRight(child);
                } else {
                    zigLeft(child);
                    zigRight(child);
                }
            }
        }

        return true;
    }
};