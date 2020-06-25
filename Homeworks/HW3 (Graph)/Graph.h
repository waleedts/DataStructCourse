//
// Created by Waleed on 12/2/2019.
//

#ifndef HW3_B_GRAPH_H
#define HW3_B_GRAPH_H

#include <vector>
#include <iostream>
#include <fstream>

void printMenu();

class Node{
public:
    std::string TaskName;
    double Duration;
    double StartTime;
    int childNO;
    std::vector <Node*> Children;
    Node* parent;
    Node();
};

class Graph {
private:
    std::vector <Node*> GraphList;
    int size;
    Node *start,*end;
    double longestPath;
    void printLongestPath(Node*);
    void compute();
public:
    void addVertex(int,int);
    std::string getStartTask(){
        return start->TaskName;
    }
    std::string getEndTask(){
        return end->TaskName;
    }
    void addEdge(int,std::string,double);
    void printLongestPath();
    double computeLongestPath();
    void createNewGraph(std::ifstream &f);
    Graph();
};

#endif //HW3_B_GRAPH_H
