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

  std::vector<Node<T>*>children;
  std::vector<Key<T>> keys;

  Node(int _maxElements) :
          maxElements(_maxElements),
          children(_maxElements, nullptr),
          keys(_maxElements)
  {
  }
  ~Node()
  {
      for(auto child : children)
          delete child;
  };

  void insertNonFull(T k)
  {
      printf("insertNonFull invoked\n");
  };

  void traverse() {
      printf("insertNonFull invoked\n");
  };
   bool isElementsNumberCorrect();
  void sort();
  bool canRemoveElement();
    friend Tree<T>;
};


template <class T>
void Node<T>::sort(){
    std::sort(this->keys.begin(), this->keys.begin() + this->maxElements);

}

template<class T>
bool Node<T>::isElementsNumberCorrect() {
    int sum = 0;
    for (int i = 0; i < maxElements; i++) {
        if (keys[i].isAssigned) {
            sum++;
        }

    }
    return sum > maxElements / 2;
}

template<class T>
bool Node<T>::canRemoveElement() {
    int sum = -1;
    for (int i = 0; i < maxElements; i++) {
        if (keys[i].isAssigned) {
            sum++;
        }

    }
    return sum > maxElements / 2;
}

#endif // NODE_H
