


#include "Store.h"



Product* Store::getProduct(int index)     { return stock.get(index); }
Customer* Store::getCustomer(int index) { return customers.get(index); }

void Store::addProd(string n, string s, int u, float p){stock.add(n, s, u, p);}
void Store::addCust(string n){customers.add(n);}

int Store::getStockSize(){return stock.getSize();}
int Store::getCustSize(){return customers.getSize();}


bool Store::validCustomer(int id, int& customerIndex){
    
    for(int i=0; i<customers.getSize(); i++){
        if(getCustomer(i)->getId() == id){
            customerIndex = i;
            return true;
        }
    }
    return false;
}

bool Store::validItemID(int id, int& productIndex){
    
    for(int i=0; i<stock.getSize(); i++){
        if(getProduct(i)->getId() == id){
            productIndex = i;
            return true;
        }
    }
    return false;
}