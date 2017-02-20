

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "UI.h"
using namespace std;





void UI::adminMenu(int& choice)
{
  string str;

  choice = -1;

  cout<< "\n\n\n                   INVENTORY MANAGEMENT SYSTEM ADMIN MENU\n\n";
  cout<< "          1. Add new product \n\n";
  cout<< "          2. Add more inventory \n\n";
  cout<< "          3. Print inventory \n\n";
  cout<< "          4. Print customers \n\n";
  cout<< "          0. Exit\n\n";

  while (choice < 0 || choice > 4) {
    cout << "Enter your selection:  ";
    choice = readInt();
  }
}

void UI::cashierMenu(int& choice)
{
  string str;

  choice = -1;

  cout<< "\n\n\n                   INVENTORY MANAGEMENT SYSTEM CASHIER MENU\n\n";
  cout<< "          1. Product purchases\n\n";
  cout<< "          2. Product returns\n\n";
  cout<< "          0. Exit\n\n";

  while (choice < 0 || choice > 2) {
    cout << "Enter your selection:  ";
    choice = readInt();
    if (choice == MAGIC_NUM) return;
  }
}

void UI::printStock(Store& store)
{
  
  

  cout << endl << "STOCK: " << endl << endl;
  cout << " ID                                 Name             Size    Qty    Price" << endl;
  cout << " --                                 ----             ----    ---    -----" << endl;

  for (int i=0; i<store.getStockSize(); i++) {

    printProduct(store.getProduct(i));
  }
}

void UI::printProduct(Product* prod){
    
    // The stringstream class helps us convert from numeric values to string.
    // The I/O manipulation functions help us make the output look pretty.

    
    stringstream ss;
    cout << prod->getId()   << "  " << setw(40) << prod->getName() << "  "
         << setw(10) << prod->getSize() << "  " << setw(4)  << prod->getUnits() << "    ";

    ss << setw(6) << fixed << setprecision(2) << prod->getPrice();

    cout << "$" << ss.str() << endl;
    ss.str("");
}

void UI::printCustomers(Store& store)
{
  cout << endl << "CUSTOMERS: " << endl << endl;

  for (int i=0; i<store.getCustSize(); i++) {
    printCustomer(store.getCustomer(i));
  }
}

void UI::printCustomer(Customer* cust){
    cout << "------------------------------" <<endl;
    cout << cust->getId() << "  " << setw(10) << cust->getName() 
         << "  " << setw(4) << cust->getPoints() <<endl;
    if (cust->getPurchSize() != 0){
         cout << "Has purchased: " << endl;
    
        for (int j=0; j<cust->getPurchSize(); j++){
            cout<< "id: " << cust->getPurchase(j)->getId() 
            <<"   |  # of units: " << cust->getPurchase(j)->getUnits() << endl;
        }
    }else{cout<<"no purchases made"<<endl;}
    cout << "------------------------------" <<endl;
    
}

void UI::printError(string err)
{
  cout << endl << err << " -- press enter to continue...";
  cin.get();
}


void UI::printText(string s){
    cout << s <<endl;
}

void UI::printUsageError()
{
  cout << endl << "Usage:  cushop OPTION" << endl << endl;
  cout <<         "        where OPTION is either: " << endl;
  cout <<         "              -a  Admin menu"        << endl;
  cout <<         "              -c  Cashier menu"      << endl << endl;
}

void UI::promptForInt(string prompt, int& num)
{
  cout << prompt << ": ";
  num = readInt();
}

void UI::promptForStr(string prompt, string& str)
{
  cout << prompt << ": ";
  getline(cin, str);
}

void UI::promptForFloat(string prompt, float& num)
{
  string str;

  cout << prompt << ": ";
  getline(cin, str);

  stringstream ss(str);
  ss >> num;
}

int UI::readInt()
{
  string str;
  int    num;

  getline(cin, str);
  stringstream ss(str);
  ss >> num;

  return num;
}

void UI::pause()
{
  string str;

  cout << endl << "\nPress enter to continue...";
  getline(cin, str);
}

