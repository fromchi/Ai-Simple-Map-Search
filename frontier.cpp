#include "Frontier.h"
#include <iostream> 
#include <deque>



Frontier::Frontier(){}

// the Frontier is in charge of deleting nodes
Frontier::~Frontier(){ 
   for (FrontierList::iterator i = fnodes.begin(); i != fnodes.end(); i++) { 
        delete *i;
    }
}        

bool 
Frontier::add(Node* n){
     fnodes.push_back(n);
     return true;
  
}

bool 
Frontier::check(Node* n){
	for (FrontierList::iterator i = fnodes.begin(); i != fnodes.end(); i++) { 
        return (*n == **i);  
    }
    return false;

}

bool 
Frontier::isEmpty(){
	return (fnodes.empty());

}

Node*
Frontier::pop(){
	Node *ret;
	if(type == FIFO){
		ret = fnodes.front();
		fnodes.pop_front();

	}
	else {
		ret = fnodes.back();
		fnodes.pop_back();

	}
	return ret;

}

void 
Frontier::setType(FrontierType f){
  if(f == LIFO){
  	type = LIFO;
  }
  else {
  	type = FIFO;
  }
}

void 
Frontier::print() const {
	if(type == LIFO){
		for (FrontierList::const_reverse_iterator i = fnodes.rbegin(); i != fnodes.rend(); i++) { 
          std::cout << (*i)->getState() << " ";
    }
}
    else {
    	for (FrontierList::const_iterator i = fnodes.begin(); i != fnodes.end(); i++) { 
            std::cout << (*i)->getState() << " ";

    	}

	}

}