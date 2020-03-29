#include "Problem.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>

using namespace std;

CityLink::CityLink(string left, string right, double dist) {
    a = left; 
    b = right;
    cost = dist;
}

bool
CityLink::operator==(const CityLink& cl) const {
    if(cl.a == a && cl.b == b && cl.cost == cost){
      return true;
    }
    else {
      return false;
    }
}

// just get the contents of a CityLink
void
CityLink::getVals(string& a,string& b,double& c) const {
  a = this->a;
  b = this->b;
  c = this->cost;
}


Problem::Problem() {}

bool
Problem::init(string fname) {
    int dis = 0;
    string city, neighbor;
    fstream fin;
    fin.open(fname.c_str()); 
    if(!fin.is_open()){
        cout << "File doesn't exist" << endl;
       exit(1);
       
    }
    else {
      while (fin >> city >> neighbor >> dis){
      CityLink cl(city, neighbor, dis);
      insert(cl);
    }
  }
}
// insert one link into cmap
bool
Problem::insert(CityLink cl) {
    cmap.push_back(cl);
}
// find all candidates and put into list
CityList
Problem::findNeighbors(string cname) {
  CityList n;
  CityLinks:: iterator i;
  string a, b;
  double c;
  for(i = cmap.begin(); i !=cmap.end(); i++){
    i->getVals(a, b, c);
   if(a == cname){
      Neighbor cn;
      cn.name = b; 
      cn.dist = c; 
      n.push_back(cn);
    }
  }
  return n;
    
}

// for debugging
void
Problem::print() const {
string a, b;
double d;
  for(CityLinks::const_iterator i = cmap.begin(); i != cmap.end(); i++){
   i->getVals(a, b, d);
   cout << a <<" "<< b <<" "<< d << endl;
  }
  
  }
