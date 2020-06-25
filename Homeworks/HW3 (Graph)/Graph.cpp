//
// Created by Waleed on 12/2/2019.
//

#include "Graph.h"

void printMenu(){
    std::cout<<"*******************MAIN MENU************************"<<
    std::endl<<"*      1- Load New File                            *"<<
    std::endl<<"*      2- Find The Starting Task                   *"<<
    std::endl<<"*      3- Find The Ending Task                     *"<<
    std::endl<<"*      4- Find And Print The Critical Path         *"<<
    std::endl<<"*      5- Exit                                     *"<<
    std::endl<<"****************************************************"<<std::endl;
}

Graph::Graph() {
    GraphList.clear();
    size=0;
    start=end= nullptr;
    longestPath=0;
}

Node::Node() {
    childNO=0;
    Duration=0;
    StartTime=0;
    TaskName="";
    parent= nullptr;
    Children.clear();
}

void Graph::addVertex(int st,int en) {
    Node *s=GraphList[en];
    GraphList[st]->Children.push_back(s);
    GraphList[st]->childNO++;
}


void Graph::addEdge(int num,std::string s,double dur) {
    Node *p=new Node;
    p->TaskName=std::move(s);
    p->Duration=dur;
    try {
        GraphList.at(num)=p;
    }catch (std::out_of_range &e){
        std::cerr << "Out of Range error: " << e.what() << '\n';
        exit(-1);
    }
}

void Graph::printLongestPath() {
    printLongestPath(end);
    std::cout<<std::endl;
}

void Graph::compute() {
    for(int i=0;i<size;i++){
        if((GraphList[i]->StartTime+GraphList[i]->Duration)>longestPath){
            longestPath=GraphList[i]->StartTime+GraphList[i]->Duration;
            end=GraphList[i];
        }
        if(GraphList[i]->StartTime==0){
            start=GraphList[i];
        }
    }
}

void Graph::createNewGraph(std::ifstream &f) {
    GraphList.clear();
    std::string s;
    int num,temp,n;
    double dur;
    f>>size;
    GraphList.resize(size);
    for(int i=0;i<size;i++){
        f>>num>>s>>dur;
        this->addEdge(num,s,dur);
    }
    f>>n;
    for(int i=0;i<n;i++) {
        f >> num >> temp;
        addVertex(num, temp);
        if (GraphList[temp]->StartTime <= GraphList[num]->StartTime + GraphList[num]->Duration) {
            GraphList[temp]->StartTime = GraphList[num]->Duration + GraphList[num]->StartTime;
            GraphList[temp]->parent = GraphList[num];
        }
    }
    compute();
}

double Graph::computeLongestPath() {
    return longestPath;
}

void Graph::printLongestPath(Node * d) {
    if(d==start){
        std::cout<<start->TaskName;
        return;
    }
    printLongestPath(d->parent);
    std::cout<<"->"<<d->TaskName;
}



