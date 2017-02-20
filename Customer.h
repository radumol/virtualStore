

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;



#include "PurchArray.h"

//class that represents any customer of the store

class Customer
{
  public:
    Customer(string="Unknown");
    int    getId();
    string getName();
    int    getPoints();
    void setPoints(int);  //sets the points
    
    
    void addPurchase(int, int);  //add a purchase to a customer's account
    Purchase* getPurchase(int);   //returns a purchase by its index in the array
    int getPurchSize();   //returns total number of purchases
    
    
  protected:
    static int nextCustId;
    int        id;
    string     name;
    int        points;
    PurchArray purchases;
};

#endif
