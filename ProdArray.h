
#ifndef PRODARRAY_H
#define PRODARRAY_H

#include "defs.h"
#include "Product.h"

//wrapper class for Products

class ProdArray
{
  public:
    ProdArray();
    ~ProdArray();
    void add(string, string, int, float); //creates a product object and adds it to the list
    Product* get(int);   //get a specific product by its index
    int getSize();  
    
  private:
    Product* elements[MAX_ARR];
    int size;
};
#endif

