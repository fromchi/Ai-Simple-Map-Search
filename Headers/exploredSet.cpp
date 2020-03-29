#include "ExploredSet.h"
#include <iostream>



ExploredSet::ExploredSet() {}

ExploredSet::~ExploredSet(){}

bool 
ExploredSet::check(Node* n){
	for (ExploredNodes::const_iterator i = exset.begin(); i != exset.end(); i++) { 
        if (n->getState() == i->first) return true; 
        
    }
    return false;

 
}

bool 
ExploredSet::add(Node* n){
	exset.insert({n->getState(), 0});
	return true;
}

void 
ExploredSet::print() const{

for (ExploredNodes::const_reverse_iterator i = exset.rbegin(); i != exset.rend(); i++) { 
        std::cout << i->first << " " << i->second << std::endl; 
    } 	

}