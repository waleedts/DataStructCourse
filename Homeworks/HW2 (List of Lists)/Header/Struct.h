//
// Created by Waleed on 10/31/2019.
//

#ifndef HW2__STRUCT_H
#define HW2__STRUCT_H

#include <string>

struct TASK {//the general task structure
    std::string TaskName;
    int ST;//task start time
    int ET;//task end time
    TASK *nextTask = nullptr;
};
struct MACHINE {//the general machine structure
    int id = 0;
    TASK *firstTask = nullptr;
    MACHINE *nextMachine = nullptr;
};
#endif
