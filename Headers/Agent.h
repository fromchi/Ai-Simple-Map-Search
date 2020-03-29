#ifndef AGENT_H
#define AGENT_H
#include <string>

#include "Node.h"
#include "Problem.h"
#include "ExploredSet.h"
#include "Frontier.h"

class Agent {
public:
   Agent(Problem *problem);
   
   Node* 
   search(std::string location, std::string dest, bool type);


private:
	Problem *p;
	Frontier f;
	ExploredSet ex;

};

#endif