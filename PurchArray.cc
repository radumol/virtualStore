#include "PurchArray.h"
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;



PurchArray::PurchArray()
{
  size = 0;
}

PurchArray::~PurchArray(){
    for (int i=0; i<size; ++i) {
        delete elements[i];
    }
}

int PurchArray::getSize() { return size; }

Purchase* PurchArray::get(int index)
{
  if (index < 0 || index >= size)
    exit(1);
  return elements[index];
}

void PurchArray::add(int u, int id)
{
    if (size >= MAX_ARR)
        return;
    for(int i=0; i<size; i++){
        if (elements[i]->getId() == id){
            elements[i]->addUnit();
            return;
        }
    }
    Purchase* newPurchase;
    newPurchase = new Purchase(u, id);
    elements[size++] = newPurchase;
}

