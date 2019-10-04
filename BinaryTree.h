//
// Created by Eduardo Ribeiro da Silva on 03/10/19.
//

#ifndef BINARYSEARCH_BINARYTREE_H
#define BINARYSEARCH_BINARYTREE_H

#include "Node.h"

template <typename T>
class BinaryTree {
public:
    explicit BinaryTree(Node<T> *root);
    virtual ~BinaryTree();

    bool find(const T &data) const;
private:
    bool find(Node<T> *node, const T &data) const;

    Node<T> *root;
};

//#include "BinarySearch.cpp"

template<typename T>
BinaryTree<T>::BinaryTree(Node<T> *root): root(root) {

}

template<typename T>
BinaryTree<T>::~BinaryTree() = default;


template<typename T>
bool BinaryTree<T>::find(const T &data) const {
    return find(root, data);
}

template<typename T>
bool BinaryTree<T>::find(Node<T> *node, const T &data) const {
    if (node == nullptr) {
        return false;
    }

    if (node->getData() == data) {
        return true;
    }

    if (data < node->getData()) {
        return find(node->left(), data);
    }

    return find(node->right(), data);
}

#endif //BINARYSEARCH_BINARYTREE_H
