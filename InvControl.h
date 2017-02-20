

#ifndef INVCONTROL_H
#define INVCONTROL_H

#include "Store.h"
#include "UI.h"

//class that functions as the store's brain
// connection between UI and the store

class InvControl
{
  public:
    InvControl();
    void launch(int, char*[]);
  private:
    Store     store;
    UI        view;
    void      initProducts();  //adds predetermined products to the store
    void      initCustomers();  //adds predetermined customers to the store
    void      processAdmin();   //administration related functions
    void      processCashier();  //cashier related functions
};
#endif
