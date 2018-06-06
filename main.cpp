#include <iostream>
#include "tree.h"
#include "node.h"
using namespace std;

int main(int argc, char *argv[])
{
  Tree <int> t(4);
  t.insert(6);
  t.insert(64);
  t.insert(16);
  t.insert(56);
  t.insert(600);
  t.insert(116);


  return 0;
}
