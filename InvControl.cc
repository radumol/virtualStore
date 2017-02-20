

#include <iostream>
#include <cstdlib>
#include "InvControl.h"
#include "Store.h"
#include <cmath>

using namespace std;

InvControl::InvControl()
{
  initProducts();
  initCustomers();
}

void InvControl::launch(int argc, char* argv[])
{
  if (argc != 2) {
    view.printUsageError();
    exit(1);
  }

  string option(argv[1]);

  if (option == "-a") {		// Admin menu
    processAdmin();
  }
  else if (option == "-c") {	// Cashier menu
    processCashier();
  }
  else {
    view.printUsageError();
    exit(1);
  }
}

void InvControl::processAdmin()
{
  int    choice;
  string prodName, prodSize;
  int    prodUnits, prodId, amount;
  float  prodPrice;
  int prodIndex;

  while (1) {
    choice = -1;
    view.adminMenu(choice);
    if (choice == 1) {		// add new product
      view.promptForStr("Product name", prodName);
      view.promptForStr("Product size", prodSize);
      view.promptForInt("# units", prodUnits);
      view.promptForFloat("Price", prodPrice);
      //Product prod(prodName, prodSize, prodUnits, prodPrice);
      store.addProd(prodName, prodSize, prodUnits, prodPrice);
      view.pause();
    }
    else if (choice == 2) {	// add inventory
        view.promptForInt("Enter ID of inventory product (to stop, press '0')", prodId);
        while(!store.validItemID(prodId, prodIndex) && prodId != 0){
            view.promptForInt("ID not found, enter again (to stop, press '0')", prodId);
        }
        if (prodId == 0) break;
        view.promptForInt("Enter the number of units to add: ", prodUnits);
        while (prodUnits < 0 ){
            view.promptForInt("Can't accept negative number, please enter again: ", prodUnits);
        }
        store.getProduct(prodIndex)->addUnits(prodUnits);
    }
    else if (choice == 3) {	// print inventory
      view.printStock(store);
      view.pause();
    }
    else if (choice == 4) {	// print customers
      view.printCustomers(store);
      view.pause();
    }
    else {
      break;
    }
  }
}

void InvControl::processCashier()
{
  int choice;
  int prodId, custId;

  while (1) {
    choice = -1;
    view.cashierMenu(choice);
    if (choice == 1) {
        
        int productIndex;
        int customerIndex;
        int bonusPoints = 0;
        float totalPrice = 0;
        
        view.promptForInt("Please enter ID of purchasing customer.", custId);
        
        while (!store.validCustomer(custId, customerIndex) ){
            view.promptForInt("The provided ID does not match any existing customers, enter again", custId);
	}
        view.printCustomer(store.getCustomer(customerIndex));
        
        while(1){
            
            view.promptForInt("Enter ID of each desired product to purchase (to stop, press '0')", prodId);
            
            while(!store.validItemID(prodId, productIndex) && prodId != 0){
                view.promptForInt("ID not found, enter again (to stop, press '0')", prodId);
            }
            if (prodId == 0) break;
            
            if(store.getProduct(productIndex)->getUnits() != 0 ){
                
                store.getProduct(productIndex)->takeOne();
                totalPrice = totalPrice + store.getProduct(productIndex)->getPrice();
                store.getCustomer(customerIndex)->addPurchase(1, prodId);
            }
            else{
                view.printText("Sorry but we're out of stock for this product");
            }
        }
        bonusPoints = floor(totalPrice +0.5);
        store.getCustomer(customerIndex)->setPoints(bonusPoints);
        view.printCustomer(store.getCustomer(customerIndex));
    }
    else if (choice == 2) {		// return purchases
      view.printError("Feature not implemented");
    }
    else if (choice == MAGIC_NUM) {	// print inventory and customers
      view.printStock(store);
      view.printCustomers(store);
      view.pause();
    }
    else {
      break;
    }
  }
}

void InvControl::initProducts()
{
  store.addProd("Sudzzy Dish Soap", "1 L", 10, 3.99f);
  store.addProd("Peachy Laundry Soap", "2 L", 3, 8.99f);
  store.addProd("Daisy's Spicy Chili", "150 g", 5, 1.29f);
  store.addProd("Daisy's Maple Baked Beans", "220 g", 2, 2.49f);
  store.addProd("Marmaduke Hot Dogs", "12-pack", 4, 4.99f);
  store.addProd("Garfield Hamburger Patties", "900 g", 2, 11.99f);

  store.addProd("Chunky Munkey Ice Cream", "2 L", 1, 2.97f);

  store.addProd("It's Your Bday Chocolate Cake", "500 g", 0, 12.99f);

  store.addProd("Happy Baker's Hot dog buns", "12-pack", 5, 3.49f);

  store.addProd("Happy Baker's Hamburger buns", "8-pack", 8, 3.99f);

  store.addProd("Moo-cow 2% milk", "1 L", 7, 2.99f);

  store.addProd("Moo-cow 2% milk", "4 L", 3, 4.99f);

  store.addProd("Moo-cow 5% coffee cream", "250 ml", 4, 1.49f);

  store.addProd("Good Morning Granola Cereal", "400 g", 2, 5.49f);

  store.addProd("Lightening Bolt Instant Coffee", "150 g", 8, 4.99f);

  store.addProd("Lightening Bolt Decaf Coffee", "100 g", 2, 4.99f);

  store.addProd("Munchies BBQ Chips", "250 g", 7, 2.99f);

  store.addProd("Munchies Ketchup Chips", "250 g", 3, 2.99f);

  store.addProd("Dogbert Salted Chips", "210 g", 4, 1.99f);

  store.addProd("Dogbert Sweet and Spicy Popcorn", "180 g", 5, 2.29f);

}

void InvControl::initCustomers()
{
    /*
  Customer cust01("Starbuck");
  Customer cust02("Apollo");
  Customer cust03("Boomer");
  Customer cust04("Athena");
  Customer cust05("Helo");
  Customer cust06("Crashdown");
  Customer cust07("Hotdog");
  Customer cust08("Kat");
  Customer cust09("Chuckles");
  Customer cust10("Racetrack");
*/
  store.addCust("Starbuck");
  store.addCust("Apollo");
  store.addCust("Boomer");
  store.addCust("Athena");
  store.addCust("Helo");
  store.addCust("Crashdown");
  store.addCust("Hotdog");
  store.addCust("Kat");
  store.addCust("Chuckles");
  store.addCust("Racetrack");
}

