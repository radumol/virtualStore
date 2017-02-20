
#include "Product.h"

int Product::nextProdId = 5001;

Product::Product(string n, string s, int u, float p)
{ 
  id    = nextProdId++;
  name  = n;
  size  = s;
  units = (u >= 0) ? u : 0;
  price = (p >= 0) ? p : 0;
}

int    Product::getId()    { return id;    }
string Product::getName()  { return name;  }
string Product::getSize()  { return size;  }
int    Product::getUnits() { return units; }
float  Product::getPrice() { return price; }

void Product::takeOne() {units = units -1;}

void Product::addUnits(int u){ units = units + u;}
