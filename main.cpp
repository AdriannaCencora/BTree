#include <iostream>
#include "tree.h"
#include "node.h"

using namespace std;

int main(int argc, char *argv[]) {
    Tree<int> t(4);
    t.insert(6);
    t.insert(64);
    t.insert(16);
    t.insert(56);
    t.insert(18);
    t.insert(116);

    if (t.hasValue(200)) {
        cout << endl << "Present" << endl;
    }
    else {
        cout << endl << "Absent" << endl;
    }

    if (t.hasValue(5)) {
        cout << endl << "Present" << endl;
    }
    else {
        cout << endl << "Absent" << endl;
    }
    cout << endl << t.printTree() << endl;

    t.removeValue(6);

    cout << endl << t.printTree() << endl;

    return 0;
}
