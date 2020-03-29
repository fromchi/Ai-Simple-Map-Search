#include "Node.h"
#include <iostream>


Node::Node(){
	Node* parent = NULL;
}

Node::Node(Node* p,std::string n,double cost){
  parent = p;
  name = n;   
  ucost = cost;	
  if(p != nullptr){
  	pcost = ucost + p-> ucost;
  }
  else{
	pcost = ucost;
  }
}

State 
Node::getState() const{
	return name;
}
double
Node::getPCost() const{
	return pcost;
}

bool 
Node::operator==(const Node& pref){
	return (pref.name == name);
}
    
bool 
Node::operator<(const Node& other){
	return ( other.pcost < parent->pcost );
}

void 
Node::print() const {
	std::cout << "["<< name<< ", "<< "parent:"<< parent->name << ", "<< pcost << ", "<< ucost  << " ], " << std::endl;
}

void 
Node::traceBack(){ 
	Node * pp = this;
	while(pp != NULL){
		std::cout << pp->name << ", ";
		pp = pp->parent;
	}
	std::cout << std::endl;


}
