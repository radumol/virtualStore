

#include <string>
#include <cstdlib>
using namespace std;

#include "CustArray.h"

CustArray::~CustArray(){
    for (int i=0; i<size; ++i) {
        delete elements[i];
    }
}


CustArray::CustArray()
{
  size = 0;
}

int CustArray::getSize() { return size; }

Customer* CustArray::get(int index)
{
  if (index < 0 || index >= size)
    exit(1);
  return elements[index];
}

void CustArray::add(string n)
{
  if (size >= MAX_ARR)
    return;
  Customer* newCustomer;
  newCustomer = new Customer(n);
  elements[size++] = newCustomer;
}

