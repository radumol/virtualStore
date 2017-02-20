#include "Purchase.h"


Purchase::Purchase(int u, int i)
{ 
    units = (u >= 0) ? u : 0;    
    id    = (i >= 0) ? i : 0;
  
}

int    Purchase::getId()    { return id;    }
int    Purchase::getUnits() { return units; }
void   Purchase::addUnit() { units = units +1;}


