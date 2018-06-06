#ifndef TREE_H
#define TREE_H
#include "node.h"
#include "Key.h"

template <class T>
class Tree {
private:
  Node <T> *root;           //Wskaźnik na roota(korzeń).
  int maxNodeElements;      //k (maks. liczba elementów)
  void insertRecursive(Node<T> *n, T value);
public:
  Tree(int _maxNodeElements) : maxNodeElements(_maxNodeElements){
    root = nullptr;
  }

  void traverse() {
    if(root != nullptr)
        root->traverse();
  }

  Node<T>* search(T k){
    return (root == nullptr)? nullptr : root->search(k);
  }
  void insert(T k);
  void remove(T k) = delete;
  bool isFull(Node<T>* node);
  void divide(Node<T> *node, T keyValue);
};

template <class T>
void Tree<T>::insert(T k){
  //Drzewo puste
  if(root == nullptr) {
      //Zaalokuj pamięć dla roota
      root = new Node<T>(maxNodeElements);
      root->keys[0] = Key<T>(k); //wstaw klucz

    }
  else {
        insertRecursive(root, k);
    }

}

template <class T>
void Tree<T>::insertRecursive(Node<T> *node, T k) {

    Key<T> key(k);
    if(!this->isFull(node)){
        int index = 0;
        while(node->keys[index].isAssigned)
        {
            index++;
        }
        node->keys[index] = Key<T>(k);

        node->sort();
    }
  else
  {
      bool inserted = false;
      for(int i= 0; i < maxNodeElements-1; i++)
      {
          if ((node->keys[i] < key && node->keys[i+1] >= key))
          {
                if (node->childPointers[i+1] == nullptr)
                {
                    node->childPointers[i+1] = new Node<T> (maxNodeElements);
                    this->insertRecursive(node->childPointers[i+1], k);
                    inserted = true;
                    break;
                }
          }
      }
      if(!inserted)
        this->divide(node, k);
  }


}


template <class T>
bool Tree<T>::isFull(Node<T>* node) {
  for(int i = 0; i < maxNodeElements; i++) {
       if (!node->keys[i].isAssigned)
         return false;
    }
  return true;
}

template <class T>
void Tree<T>::divide(Node<T> *node, T keyValue) {
    Key<T> key(keyValue);
    node->childPointers[node->maxElements/2] = new Node<T>(maxNodeElements);
    auto child = node->childPointers[node->maxElements/2];
    int start = node->maxElements/2;
    int end = node->maxElements;
    if(node->keys[0] > key)
    {
        end = start;
        start = 0;
    }
    for(int i = start; i < end; i++)
    {
        this->insertRecursive(child, keyValue);
        node->keys[i] = Key<T>();
    }
    node->keys[end] = key;
}


#endif // TREE_H
