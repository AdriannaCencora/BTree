#ifndef TREE_H
#define TREE_H
#include "node.h"

template <class T>
class Tree {
private:
  Node <T> *root;           //Wskaźnik na roota(korzeń).
  int maxNodeElements;      //k (maks. liczba elementów)
  void insertRecursive(Node<T> *n, T value);
public:
  Tree();
  Tree(int _maxNodeElements) : maxNodeElements(_maxNodeElements){
    root = nullptr;
  }

  void traverse() {
    if(root != nullptr)   root->traverse();
  }

  Node<T>* search(T k){
    return (root == nullptr)? nullptr : root->search(k);
  }
  void insert(T k);
  void remove(T k);
  bool isFull(Node<T> node);

};

template <class T>
void Tree<T>::insert(T k){
  //Drzewo puste
  if(root == nullptr) {
      //Zaalokuj pamięć dla roota
      root = new Node<T>(maxNodeElements);
      root->keys[0] = k; //wstaw klucz

    }
  else {
    insertRecursive(root, k);

    }

}

template <class T>
void Tree<T>::insertRecursive(Node<T> *node, T k) {

    if(!node->isFull()){
        int index = 0;
        while(node->keys[index] != nullptr) {
            index++;
          }
        node->keys[index] = k;

        node->sort();
    }
  else {
      for(int i= 0; i < maxNodeElements-1; i++) {
          if (node->keys[i]  < k && node->keys[i+1] >= k) {
           if  (node->childPointers[i+1] == nullptr) {

               node->childPointers[i+1] = new Node<T> (maxNodeElements);
             }
            }

          insertRecursive(node->childPointers[i+1], k);

            //Jest miejsce


            return;

        }

    }


}


template <class T>
bool Tree<T>::isFull(Node<T> node) {
  int index = 0;
  for(int i = 0; i < maxNodeElements; i++) {
       if (node->keys[i] != nullptr)
         index++;
    }
  return ((index == maxNodeElements) ? true : false);
}


#endif // TREE_H
