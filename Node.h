#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

typedef std::string State;

class Node {
public:
    Node();
    Node(Node*,std::string,double cost);
    State getState() const;
    double getPCost() const;
    bool operator==(const Node&);
    bool operator<(const Node&);
    void print() const;
    void traceBack();
private:
    Node* parent;
    State name;   // the name is actually the "state"
    double ucost;	// unit cost:  distance to parent
    double pcost;	// total path cost: distance to root
};

#endif
