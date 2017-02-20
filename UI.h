

#ifndef UI_H
#define UI_H

#include <string>
using namespace std;

#include "ProdArray.h"
#include "CustArray.h"
#include "Store.h"

//UI class displays information to the user

class UI
{
  public:
    void mainMenu(int&);  
    void adminMenu(int&);
    void cashierMenu(int&);
    void promptForInt(string, int&);
    void promptForStr(string, string&);
    void promptForFloat(string, float&);
    void printError(string);
    void printUsageError();
    void printStock(Store&);
    void printCustomers(Store&);
    void printCustomer(Customer*);
    void printProduct(Product*);
    void pause();
    void printText(string);
	


  private:
    int    readInt();
};

#endif
