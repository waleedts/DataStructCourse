#include <iostream>
#include "Graph.h"
using namespace std;

int main() {
    Graph g;
    ifstream f;
    string s;
    int x=0;
    try {
        f.open("File.txt");
    }catch (const ifstream::failure& e){
        cerr<<"Error Opening File"<<endl;
    }
    g.createNewGraph(f);
    printMenu();
    while(x!=5){
        cout<<"Enter your choice:";
        try{
            cin>>x;
            if(cin.fail())
            throw invalid_argument("INVALID INPUT");
        }
        catch(invalid_argument & a){
            std::cerr <<a.what();
            cin.clear();
            cin.ignore();
        }
        switch (x){
            case 1:
                cout<<"Please Enter New File Name:";
                cin>>s;
                f.close();
                try {
                    f.open(s);
                }catch (const ifstream::failure& e){
                    cerr<<"Error Opening File"<<endl;
                }
                g.createNewGraph(f);
                break;
            case 2:
                cout<<g.getStartTask()<<endl;
                break;
            case 3:
                cout<<g.getEndTask()<<endl;
                break;
            case 4:
                cout<<"Longest Path Length:"<<g.computeLongestPath()<<endl;
                g.printLongestPath();
                break;
            case 5:
                cout<<"Farewell"<<endl;
                break;
            default:
                cout<<"Invalid Input"<<endl;
        }
    }
    return 0;
}
