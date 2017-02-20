#ifndef PURCHASE_H
#define PURCHASE_H

#include <string>
using namespace std;

//Class that represents a purchase of a specific product 
// and how much of that product was purchased
class Purchase
{
  public:
    Purchase(int=0, int=0);
    int    getId();   //returns the id of the purchased unit
    int    getUnits();  //returns the amount of units purchased
    void addUnit();  //add one unit to the purchase

  protected:
    int        id;
    int        units;
};

#endif
