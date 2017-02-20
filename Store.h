

#ifndef STORE_H
#define STORE_H

#include "ProdArray.h"
#include "Product.h"
#include "CustArray.h"
#include "Customer.h"


//Store class manages stock and customers
class Store
{
public:
    void       addProd(string, string, int, float); //add product to stock
    void       addCust(string);           //add new customer to existing customers
    Product* getProduct(int);              //returns a product by its index in the array
    Customer* getCustomer(int);         //returns a customer by its index in the array
    bool validCustomer(int, int&);   //using the id scans the customers
    bool validItemID(int, int&);   //using the id scans the stock
    int getStockSize();				
    int getCustSize();
    
private:
    ProdArray  stock;         
    CustArray  customers;
};

#endif
