#ifndef NODE_H
#define NODE_H
#include "tree.h"
template <class T>
class Tree;

template <class T>
class Node {
private:
  int maxElements;            //Maksymalna liczba elementów w węźle. El. = [key, childPointer]
  Node <T> **childPointers;   //Tablica wskaźników na potomków
  T *keys;                    //Tablica kluczy
  int n;
public:
  Node();
  Node(int _maxElements) : maxElements(_maxElements) {
    //Zaalokuj pamięć na maksymalną liczbę możliwych kluczy i wskaźników na potomków
    keys = new int[maxElements];
    childPointers = new Node<T> *[maxElements];

  }

  void insertNonFull(T k); //Wstaw nowy klucz w poddrzewie(jeśli węzeł nie jest pełny)
  //void splitChild(int i, Node *y); //Podziel potomka y tego węzła; i - indeks 'y' w tablicy childPointers
  void traverse();
  Node<T> *search(T k);  //Szukaj klucza w poddrzewie wskazanego węzła.
  void sort();
  friend Tree<T>;
};


template <class T>
void Node<T>::sort(){
  while(true){
      bool changed = false;
      for(int i = 0; i < maxElements - 1; i++) {
          if(keys[i] > keys[i+1]) {
              int temp = keys[i];
              keys[i] = keys[i+1];
              keys[i+1] = temp;
              changed = true;
            }
       }
      if(!changed) {
          break;
        }
    }
}

#endif // NODE_H
