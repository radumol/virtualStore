

#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

#include "ProdArray.h"

ProdArray::~ProdArray(){
    for (int i=0; i<size; ++i) {
        delete elements[i];
    }
}

ProdArray::ProdArray()
{
  size = 0;
}

int ProdArray::getSize() { return size; }

Product* ProdArray::get(int index)
{
  if (index < 0 || index >= size)
    exit(1);
  return elements[index];
}

void ProdArray::add(string n, string s, int u, float p){
    if (size >= MAX_ARR)
        return;
    Product* newProduct;
    newProduct = new Product(n, s, u, p);
    elements[size++] = newProduct;
}


