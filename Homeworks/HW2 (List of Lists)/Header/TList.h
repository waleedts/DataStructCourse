//
// Created by Waleed on 10/31/2019.
//
#ifndef HW2_B__TLIST_H
#define HW2_B__TLIST_H

#include <iostream>

struct TASK;

class TList {
private:
    TASK *head;
public:
    TASK *pop();

    bool empty();

    TList();

    friend std::ostream &operator<<(std::ostream &o, TList a);//overloaded output stream

    friend std::ifstream &operator>>(std::ifstream &in, TList &s);//overloaded file input stream

    void insert(std::string TaskName, int ST, int ET);//makes the new task and links it to the task list
};


#endif //HW2__TLIST_H
