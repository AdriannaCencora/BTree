#ifndef NODE_H
#define NODE_H
#include "tree.h"
#include "Key.h"
#include <vector>
#include <cstdio>
#include <algorithm>

template <class T>
class Tree;

template <class T>
class Node {
private:
public:
  int maxElements;            //Maksymalna liczba elementów w węźle. El. = [key, childPointer]

  std::vector<Node<T>*>childPointers;
  std::vector<Key<T>> keys;

  Node(int _maxElements) :
          maxElements(_maxElements),
          childPointers(_maxElements, nullptr),
          keys(_maxElements)
  {
  }
  ~Node()
  {
      for(auto child : childPointers)
          delete child;
  };

  void insertNonFull(T k)
  {
      printf("insertNonFull invoked\n");
  };

  void traverse() {
      printf("insertNonFull invoked\n");
  };
  Node<T> *search(T k)
  {
      printf("insertNonFull invoked\n");

  };

  void sort();
  friend Tree<T>;
};


template <class T>
void Node<T>::sort(){
//  while(true){
//      bool changed = false;
//      for(int i = 0; i < maxElements - 1; i++) {
//          if(keys[i] > keys[i+1])
//          {
//              std::swap(keys[i], keys[i+1]);
//              changed = true;
//          }
//       }
//      if(!changed) {
//          break;
//        }
//    }
    std::sort(this->keys.begin(), this->keys.begin() + this->maxElements);

}

#endif // NODE_H
