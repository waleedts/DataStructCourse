//
// Created by Waleed on 10/31/2019.
//
#include <fstream>
#include "../Header/Struct.h"
#include "../Header/TList.h"

TList::TList() {
    head = nullptr;
}

std::ifstream &operator>>(std::ifstream &in, TList &s) {
    int n, k, j;
    std::string st;
    in >> n;
    for (int i = 0; i < n; i++) {
        in >> st >> j >> k;
        s.insert(st, j, k);
    }
    return in;
}

std::ostream &operator<<(std::ostream &o, TList a) {
    TASK *p = a.head;
    while (p != nullptr) {
        o << p->TaskName << ' ' << p->ST << '-' << p->ET << std::endl;
        p = p->nextTask;
    }
    return o;
}
void TList::insert(std::string TaskName, int ST, int ET) {
    //creates new task and fills it with info
    auto *t = new TASK;
    t->TaskName = std::move(TaskName);
    t->ST = ST;
    t->ET = ET;
    //navigates to the end of task list
    TASK *p = head;
    if (head == nullptr) {
        head = t;
    } else if (head->ST > t->ST) {
        t->nextTask = head;
        head = t;
    } else {
        while ((p->nextTask != nullptr) && (p->nextTask->ST <= t->ST)) {
            p = p->nextTask;
        }
        t->nextTask = p->nextTask;
        p->nextTask = t;
    }
}

bool TList::empty() {
    return head == nullptr;
}

TASK *TList::pop() {//removes the first task in the task list
    TASK *a = head;
    head = head->nextTask;
    a->nextTask = nullptr;
    return a;
}