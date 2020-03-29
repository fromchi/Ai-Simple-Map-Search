#include "Problem.h"
#include "Node.h"
#include "ExploredSet.h"
#include "Frontier.h"
#include "Agent.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    string dest, local;
    int type;
    Problem p;
    Agent a(&p);
    
    p.init("romania-pairs.txt");
    cout << "Please enter a starting location" << endl;
    cin >> local;
    cout << "Please enter a destination" << endl;
    cin >> dest;
    cout << "Lifo (0) or Fifo(1)?" << endl;
    cin >> type;
       
    if(type == 0){
         a.search(local, dest , 0);
    }

    else if(type == 1){
         a.search(local, dest , true);
    }

    else {
        cout << "please try again" << endl;
    }
    
    return 0;
}
