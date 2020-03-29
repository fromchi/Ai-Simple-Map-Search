#include "Agent.h"
#include <iostream>

using namespace std;

Agent::Agent(Problem *problem){
	p = problem;

}

//search algorithim 

Node*
Agent::search(string location, string dest, bool type){
	if(type == true){
		f.setType(FIFO);
	}
	else {
		f.setType(LIFO);
	}

    Node * parentN = new Node(nullptr, location, 0);

	if(location == dest){
		return parentN;
	}
	else {
    	f.add(parentN);

		while (true) {
			if(f.isEmpty() == true){
				cout << "Not working, city is not correct, try again" << endl;
				return 0;
			}
			else {
				Node *temp = f.pop();
				ex.add(temp);
				string tempState = temp->getState(); 
				CityList clst = p->findNeighbors(tempState);
	            CityList::iterator cli;
	            	for (cli=clst.begin(); cli != clst.end(); cli++) {
	           			 string n = cli->name; 
	           			 double distN = cli->dist; 
	           			 Node* child = new Node(temp, n, distN);
	          	  		if(ex.check(child) != true || f.check(child) != true){
	            			if(child->getState() != dest){
	            				f.add(child);
	            			}
	            			else {
	            				child ->print();
	            				cout << "In reverse order" <<endl;
	            				child->traceBack();
	            				return child;
	            			}
	            		}
	            	}
	            }
	        }
	    }
	}
