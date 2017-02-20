#ifndef PURCHARRAY_H
#define PURCHARRAY_H

#include "defs.h"
#include "Purchase.h"

//wrapper classs for purchases which stores an array of purchases

class PurchArray
{
  public:
    
    PurchArray();
    ~PurchArray(); //destructor
    void add(int, int);   //add a new purchase to the array
    Purchase* get(int);  //get specific purchase by its index from the array
    int getSize();
    
  private:
    Purchase* elements[MAX_ARR];
    int size;
};

#endif
