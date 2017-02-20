

#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;

//class that represents any product available in the store

class Product
{
  public:
    Product(string="Unknown", string="Unknown", int=0, float=0.0f);
    int    getId();
    string getName();
    string getSize();
    int    getUnits();
    float  getPrice();
    void   takeOne();    //decrease the inventory by one
    void   addUnits(int);   //add a number of inventory
  protected:
    static int nextProdId;   //internally assigned to a product
    int        id;
    string     name;
    string     size;
    int        units;
    float      price;
};

#endif
