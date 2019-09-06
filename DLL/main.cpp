#include <iostream>
#include "doubleLinkedList.h"
using namespace std;

int main() {
    doubleLinkedList n;
    n.insert(4);
    n.insert(3);
    n.insert(6);
    n.insert(5);
    n.displayB();
    n.displayI();
    n.deleteL();
}
