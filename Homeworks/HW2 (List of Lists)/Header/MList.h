//
// Created by Waleed on 10/31/2019.
//
#ifndef HW2_B__MLIST_H
#define HW2_B__MLIST_H

#include <iostream>

struct MACHINE;
struct TASK;

class MList {
private:
    int id;
    MACHINE *head;
public:
    //Constructor with the default values for (id=1,head=null)
    MList();
    void insert(TASK *d);//Inserts new task in the Machines List
    friend std::ostream &operator<<(std::ostream &o, MList a);//overloaded output operator
};


#endif //HW2__MLIST_H
