#ifndef FRONTIER_H
#define FRONTIER_H

#include "Node.h"
#include <queue>

enum FrontierType { LIFO, FIFO };

typedef std::deque<Node*> FrontierList;

class Frontier {
public:
    Frontier();
    ~Frontier(); // the Frontier is in charge of deleting nodes
    bool add(Node*);
    bool check(Node*);
    bool isEmpty();
    Node* pop();
    void setType(FrontierType);
    void print() const;
private:
    
    FrontierType type;
    FrontierList fnodes;
};

#endif
