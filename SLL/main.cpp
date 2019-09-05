#include <iostream>
#include "singleLinkedList.h"

int main() {
    List n;
    n.insert(5);
    n.insert(10);
    n.insert(2);
    n.insert(1);
    n.display();
    n.deleteN(2);
    n.display();
    n.deleteN(1);
    n.display();
    n.deleteL();
    n.display();
    return 0;
}