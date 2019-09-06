#ifndef _doubleLinkedList_h
#define _doubleLinkedList_h

class doubleLinkedList {
private:
    struct Node {
        int id;
        Node *next;
        Node *previous;
    };
    Node *head = nullptr;
public:
    void insert(int);

    //void deleteN(int x);
    void deleteL();

    void displayB();

    void displayI();
};

#endif
