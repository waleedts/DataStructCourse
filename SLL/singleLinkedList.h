#ifndef _singleLinkedList_h
#define _singleLinkedList_h
class List{
private:
    struct Node{
        int id;
        Node *next;
    };
    Node *head= nullptr;
public:
    void insert(int);
    void deleteN(int);
    void deleteL();
    void display();
};
#endif