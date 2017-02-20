

#ifndef CUSTARRAY_H
#define CUSTARRAY_H

#include "defs.h"
#include "Customer.h"

//Wrapper class for customers

class CustArray
{
  public:
    CustArray();           
    ~CustArray();
    void add(string);     //add a customer
    Customer* get(int);   
    int getSize();        //get the number of costumers

  private:
    Customer* elements[MAX_ARR];
    int size;
};

#endif

