#include <iostream>
#include "doubleLinkedList.h"
using namespace std;
void doubleLinkedList::insert(int x)
{
    if(head== nullptr) {//The first node
        Node *t=new Node;
        t->id=x;
        t->next= nullptr;
        t->previous=nullptr;
        head =t;
        return;
    }
    else if(x<(head->id)) {//Before the first node
        Node *t=new Node;
        t->id=x;
        t->next=head;
        t->next->previous=t;
        t->previous=nullptr;
        head=t;
        return;
    }else{//General Node
        Node *t=new Node;
        t->id=x;
        Node *p1=head,*p2=head;
        while(p1!=nullptr){
            if(x>(p1->id)){
                p2=p1;
                p1=p1->next;
            }else{
                p2->next=t;
                t->previous=p2;
                t->next=p1;
                p1->previous=t;
                return;
            }
        }
        p2->next=t;
        t->previous=p2;
        t->next=nullptr;
    }
}
void doubleLinkedList::displayB()
{
    Node *temp;
    temp=head;
    while(temp->next!= nullptr)
    {
        temp=temp->next;
    }
    while(temp!= nullptr)
    {
        cout<<temp->id<<"\t";
        temp=temp->previous;
    }

    cout<<"\n--------------------------------------------\n";
}
void doubleLinkedList::displayI()
{
    Node *temp;
    temp=head;
    while(temp!= nullptr)
    {
        cout<<temp->id<<"\t";
        temp=temp->next;
    }
    cout<<"\n--------------------------------------------\n";
}
void doubleLinkedList::deleteL(){//List Deletion
    Node *p=head;
    while (p!=nullptr){
        head=head->next;
        p->next= nullptr;
        free(p);
        p=head;
    }
}

