#include <cstdlib>
#include <iostream>
#include "singleLinkedList.h"
using namespace std;

void List::deleteN(int x){//Single Node Deletion
    if(head->id==x){//First Node
        Node *p1=head;
        head=head->next;
        p1->next= nullptr;
        free(p1);
    }
    else
    {//General Case (Mid+Last)
        Node *p1=head,*p2=head;
        while(p1->id!=x){
            p2=p1;
            p1=p1->next;
            if(p1 == nullptr)return;
        }
        p2->next=p1->next;
        p1->next= nullptr;
        free(p1);
    }
}
void List::deleteL(){//List Deletion
    Node *p=head;
    while (p!=nullptr){
        head=head->next;
        p->next= nullptr;
        free(p);
        p=head;
    }
}
void List::insert(int x)
{
    if(head== nullptr) {//The first node
        Node *t=new Node;
        t->id=x;
        t->next= nullptr;
        head =t;
        return;
    }
    else if(x<(head->id)) {//Before the first node
        Node *t=new Node;
        t->id=x;
        t->next=head;
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
                p1->next=t;
                t->next=p2;
                return;
            }
        }
        p2->next=t;
        t->next=nullptr;
    }
}
void List::display()
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