#ifndef TREE_H
#define TREE_H

#include "node.h"
#include "Key.h"
#include  <string>

template<class T>
class Tree {
private:
    Node<T> *root;           //Wskaźnik na roota(korzeń).
    int maxNodeElements;      //k (maks. liczba elementów)
    void insertRecursive(Node<T> *n, T value);

public:
    Tree(int _maxNodeElements) : maxNodeElements(_maxNodeElements) {
        root = nullptr;
    }

    std::string out = "";

    bool hasValueRecursive(Node<T> *node, T value);

    bool hasValue(T value);

    void insert(T k);

    void removeValue(T value);

    void removeValueRecursive(Node<T> *node, T value);

    Node<T> *findParent(Node<T> *node);

    Node<T> *findParentRecursive(Node<T> *node, Node<T> *finalNode);

    bool isFull(Node<T> *node);

    std::string printTree();

    void printTreeRecursive(Node<T> *node);

};

template<class T>
void Tree<T>::insert(T k) {
    //Drzewo puste
    if (root == nullptr) {
        //Zaalokuj pamięć dla roota
        root = new Node<T>(maxNodeElements);
        root->keys[0] = Key<T>(k); //wstaw klucz

    } else {
        insertRecursive(root, k);
    }

}

template<class T>
void Tree<T>::insertRecursive(Node<T> *node, T k) {

    Key<T> key(k);
    if (!this->isFull(node)) {
        int index = 0;
        while (node->keys[index].isAssigned) {
            index++;
        }
        node->keys[index] = Key<T>(k);

        node->sort();
    } else {
        for (int i = 0; i < maxNodeElements - 1; i++) {
            if ((node->keys[i] < key && node->keys[i + 1] >= key)) {
                if (node->children[i] == nullptr) {
                    node->children[i] = new Node<T>(maxNodeElements);

                    this->insertRecursive(node->children[i], node->keys[i].getValue());
                    this->insertRecursive(node->children[i], k);

                    while (!node->isElementsNumberCorrect()) {
                        this->insertRecursive(node->children[i], node->keys[i + 1].getValue());
                        node->keys[i + 1].clearValue();
                    }
                    return;
                }
            }
        }
        node->children[maxNodeElements - 1] = new Node<T>(maxNodeElements);
        this->insertRecursive(node->children[maxNodeElements - 1], node->keys[maxNodeElements - 1].getValue());
        this->insertRecursive(node->children[maxNodeElements - 1], k);
    }


}

template<class T>
bool Tree<T>::hasValue(T value) {
    return hasValueRecursive(root, value);
}

template<class T>
bool Tree<T>::hasValueRecursive(Node<T> *node, T value) {
    for (int i = 0; i < node->maxElements; i++) {

        if (node->keys[i].isAssigned) {
            if (node->keys[i].getValue() == value) {
                return true;
            }
        }
    }

    for (int i = 0; i < node->maxElements; i++) {

        if (node->children[i] != nullptr) {
            if (hasValueRecursive(node->children[i], value)) {
                return true;
            }
        }
    }

    return false;
}


template<class T>
bool Tree<T>::isFull(Node<T> *node) {
    for (int i = 0; i < maxNodeElements; i++) {
        if (!node->keys[i].isAssigned) {
            return false;
        }
    }
    return true;
}

template<class T>
void Tree<T>::removeValue(T value) {
    removeValueRecursive(root, value);
}

template<class T>
void Tree<T>::removeValueRecursive(Node<T> *node, T value) {
    for (int i = 0; i < maxNodeElements; i++) {
        if (node->keys[i].isAssigned) {
            if (node->keys[i].getValue() == value) {
                node->keys[i].clearValue();

                std::vector<Node<T> *> all;
                while (node->children[i] != nullptr) {
                    node = node->children[i];
                    all.push_back(node);
                }
                while (!all.empty()) {
                    Node<T> *parent = findParent(all[0]);
                    all[0]->keys[0].clearValue();
                    all.erase(all.begin());
                }
                node->sort();
                return;
            }
        }
    }
    for (int i = 0; i < maxNodeElements; i++) {
        if (node->keys[i].isAssigned) {
            if (node->children[i] != nullptr) {
                removeValueRecursive(node->children[i], value);
            }
        }
    }
}

template<class T>
Node<T> *Tree<T>::findParent(Node<T> *node) {
    return findParentRecursive(root, node);
}

template<class T>
Node<T> *Tree<T>::findParentRecursive(Node<T> *currentNode, Node<T> *finalNode) {
    Node<T> *output = NULL;
    if (currentNode == finalNode) {
        output = currentNode;
        return output;
    } else {
        for (int i = 0; i < maxNodeElements; i++) {
            if (currentNode->children[i] != nullptr) {
                output = findParentRecursive(currentNode->children[i], finalNode);
                if (output == finalNode) {
                    output = currentNode;
                    return output;
                }
            }
        }
    }
    return output;
}

template<class T>
std::string Tree<T>::printTree() {
    out = "";
    printTreeRecursive(root);
    return out;
}

template<class T>
void Tree<T>::printTreeRecursive(Node<T> *node) {
    out += "(";
    for (int i = 0; i < maxNodeElements; i++) {
        if (node->keys[i].isAssigned) {
            out += std::to_string(node->keys[i].getValue()) + " ";
        }
    }

    out += ") ";
    for (int i = 0; i < maxNodeElements; i++) {
        if (node->children[i] != nullptr) {
            printTreeRecursive(node->children[i]);
        }
    }
}

#endif // TREE_H
