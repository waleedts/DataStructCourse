//
// Created by Waleed on 10/31/2019.
//
#include "../Header/Struct.h"
#include "../Header/MList.h"
MList::MList() {//Constructor for the default values
    id = 1;
    head = nullptr;
}

void MList::insert(TASK *d) {//inserts a Task to the machine list
    MACHINE *m = head;
    MACHINE *last = m;
    TASK *t;
    if (head == nullptr) {//list is empty ~without any machines~
        //creates a new machine and links the task
        auto *a = new MACHINE;
        a->firstTask = d;
        a->id = id;
        id++;
        head = a;
    } else {
        while (m != nullptr) {//navigates to the available location to add the new task
            last = m;
            if (m->firstTask == nullptr) {//machine does not have any task connected so adds the task directly to the machine
                m->firstTask = d;
                return;
            }
            t = m->firstTask;//points to the task connected directly to the machine
            while (t->nextTask != nullptr) {//goes to the end of the list of tasks connected to the machine
                t = t->nextTask;
            }
            if ((t->ET) <= (d->ST)) {
                //task can be added to the location
                t->nextTask = d;
                return;
            }
            m = m->nextMachine;//current machine doesn't have an available location so goes to the next
        }
        //all current machines don't have an available location so creates a new machine ,links it the machine list and links the task to it
        auto *a = new MACHINE;
        a->id = id;
        a->firstTask = d;
        id++;
        last->nextMachine = a;
    }
}

std::ostream &operator<<(std::ostream &o, MList a) {//prints the list of machines and tasks
    MACHINE *m = a.head;
    TASK *t;
    while (m != nullptr) {
        o << "Machine # " << m->id << ':';
        if (m->firstTask == nullptr)continue;
        t = m->firstTask;
        while (t->nextTask != nullptr) {
            o << t->TaskName << '(' << t->ST << '-' << t->ET << ')' << " --- ";
            t = t->nextTask;
        }
        o << t->TaskName << '(' << t->ST << '-' << t->ET << ')' << std::endl;
        m = m->nextMachine;
    }
    return o;
}

