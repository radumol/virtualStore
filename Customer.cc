

#include <cmath>
#include "Customer.h"

int Customer::nextCustId = 2001;

Customer::Customer(string n){ 
    id     = nextCustId++;
    name   = n;
    points = 0;
}


int    Customer::getId()     { return id;     }
string Customer::getName()   { return name;   }
int    Customer::getPoints() { return points; }


Purchase* Customer::getPurchase(int index){return purchases.get(index);}
int Customer::getPurchSize(){return purchases.getSize();}


void Customer::addPurchase(int u, int i){purchases.add(u, i);}

void Customer::setPoints(int p) {points = points + p;}

