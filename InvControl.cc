/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/*  Program:  Simple Inventory System              */
/*  Author:   Christine Laurendeau                 */
/*  Date:     28-JUN-2016                          */
/*                                                 */
/*  (c) 2016 Christine Laurendeau                  */
/*  All rights reserved.  Distribution and         */
/*  reposting, in part or in whole, without the    */
/*  written consent of the author, is illegal.     */
/*                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#include <cstdlib>
#include "InvControl.h"
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
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
  int    expiryDay, expiryMonth, expiryYear, lifeSpanProduct;
  int 	 month,day,year;
  int prodCategory = 0;

  while (1) {
    choice = -1;
    view.adminMenu(choice);
    if (choice == 1) {		// add new product
      while(prodCategory==0){
		view.printString("Please Enter today's Date");
		view.promptForInt("Month (1 = Jan.... 12 = Dec)",month);
		view.promptForInt("Day",day);
		view.promptForInt("Year",year);
		view.promptForInt("Enter product Category\n1.Bakery  2.CoffeeTea  3.Dairy  4.Meat  5.MiscGoods\nProduct Category",prodCategory);
		prodCategory = (prodCategory < 1|| prodCategory>5) ? 0: prodCategory;
	  }
		view.promptForInt("LifeSpan, for default lifespan enter '0'",lifeSpanProduct);
		lifeSpanProduct = (lifeSpanProduct !=0) ? lifeSpanProduct: Default_Life_Span; //setting it 720 for default lifeSpan
		view.promptForStr("Product name", prodName);
		view.promptForStr("Product size", prodSize);
		view.promptForInt("# units", prodUnits);
		view.promptForFloat("Price", prodPrice);
		
		if(prodCategory==1){
			Bakery* newProd = new Bakery(prodName, prodSize, prodUnits, prodPrice,day,month,year,lifeSpanProduct);
			store.addProd(newProd);
		}else if(prodCategory==2){
			CoffeeTea* newProd = new CoffeeTea(prodName, prodSize, prodUnits, prodPrice,day,month,year,lifeSpanProduct);
			store.addProd(newProd);
		}else if(prodCategory==3){
			Dairy* newProd = new Dairy(prodName, prodSize, prodUnits, prodPrice,day,month,year,lifeSpanProduct);
			store.addProd(newProd);
		}else if(prodCategory==4){
			Meat* newProd = new Meat(prodName, prodSize, prodUnits, prodPrice,day,month,year,lifeSpanProduct);
			store.addProd(newProd);
		}else if(prodCategory==5){
			MiscGoods* newProd = new MiscGoods(prodName, prodSize, prodUnits, prodPrice,day,month,year,lifeSpanProduct);
			store.addProd(newProd);
		}
		
		view.pause();
	  
	  
    }else if(choice == 2){   //remove product
	     while(1){
	      view.promptForInt("Enter product ID ", prodId);
	      if(prodId == 0){
          break;
	      }else{
		      if(store.getStock().checkIfProdExists(prodId) == true ){
                                Product* prodToBeRemoved = store.getStock().find(prodId);
				store.getStock().remove(prodToBeRemoved); 
                                view.printString("Product has been removed successfully."); 
		     }else{
			    view.printString("Product Id does not correspond to an existing product");
		      }
	     }
	    }
    }else if (choice == 3) {	// add inventory
	      while(1){
	      view.promptForInt("Enter product ID ", prodId);
	      if(prodId == 0){
		   break;
	      }else{
	      if(store.getStock().checkIfProdExists(prodId) == true){
		        view.promptForInt("Enter number of units to add to stock ", prodUnits);
		        store.getStock().increaseStockUnits(prodId, prodUnits);
	      }else{
		    view.printString("Product Id does not correspond to an existing product");
	      }
	     }
	    }
	    }
    else if (choice == 4) {	// print inventory
      view.printStock(store.getStock());
      view.pause();
    }
    else if (choice == 5) {	// print customers
      //view.printCustomers(store.getCustomers());
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
    if (choice == 1) {			// purchases
      view.promptForInt("Enter Customer ID ", custId);
      //verify this is an existing customer
      if(store.checkIfCustExists(custId) == true){
        view.printString("Welcome to the store!");
        while(1){
          view.promptForInt("Enter product ID to be purchased ", prodId);
          if(prodId == 0){
            break;
          }else{
            if(store.getStock().checkIfProdExists(prodId) == true && store.getStock().checkIfProdInStock(prodId) == true){ //product exists and in stock
              
              view.printString("Hurray product exists and is in stock!");
              store.getStock().reduceStockUnits(prodId);
              float priceOfProd = store.getStock().getPriceOfProduct(prodId);
	            store.loyaltyPoints(priceOfProd, custId);
              
              
              Purchase* p = new Purchase(store.getStock().getNameOfProd(prodId),prodId, 1);
              //Calculating the TAX of the product Purchased 
			  float taxTotal = store.getStock().get(prodId)->computeTax();
			  cout<<"SDAD: "<<taxTotal<<endl;
			  cout<<"price of prod"<< priceOfProd<<endl;
              //adding the tax to the amount that customer was to pay
			  priceOfProd +=taxTotal;
			  priceOfProd = roundf(priceOfProd * 100) / 100;
			  //register The purchase
              store.registerPurchases(custId, p,prodId);
              
              int prodUnits = store.returnPurchArray(custId).returnUnitsOfProd(prodId);
              //tally the Total amount 
              store.tallyTotalAmount(custId,priceOfProd,prodUnits);
              //print total purchasess
			  view.printCustomers(store.getCustomers()); //print total
              view.printPurchases(store.returnPurchArray(custId));
              
             
            }else { 
              view.printString("Product ID does not correspond to an existing product or product is currently not in stock");
            }
          } 
        }
      } else{ 
           view.printString("Customer ID does not correspond to an existing customer.");
          } 
    }
    else if (choice == 2) {		// return purchases
      view.printError("Feature not implemented");
    }
    else if (choice == MAGIC_NUM) {	// print inventory and customers
      view.printStock(store.getStock());
      view.printCustomers(store.getCustomers());
      view.printCustomers(store.getCustomers());
      view.pause();
    }
    else {
      break;
    }
  }
}

void InvControl::initProducts()
{
  /*
     This function is so ugly!  It's because we're using 
     statically allocated memory, instead of dynamically
     alloated.  Don't worry, we'll fix this in Assignment #2.
  */

 
Dairy *prod02= new Dairy("Peachy Milk", "2 L", 3, 8.99f, 12, 01, 1990, 60);
  store.addProd(prod02);

  CoffeeTea* prod01 = new CoffeeTea("Sudzzy Tea Roast", "1 L", 10, 3.99f, 26, 02, 1992,0);
  store.addProd(prod01);
  
  Meat *prod03 = new Meat("Daisy's Spicy Chili Ham", "150 g",5, 1.29f, 05, 02, 1993, 90);
  store.addProd(prod03);

  Bakery *prod04= new Bakery("Daisy's Maple Baked Buns", "220 g", 2, 2.49f, 18, 02, 1994, 30);
  store.addProd(prod04);

  MiscGoods *prod05= new MiscGoods("Marmaduke Pencils", "12-pack", 4, 4.99f, 11, 03, 1995, 0);
  store.addProd(prod05);

  Dairy *prod06= new Dairy("Garfield Cheese", "900 g", 2, 11.99f, 21, 03, 1996, 60);
  store.addProd(prod06);

  CoffeeTea *prod07= new CoffeeTea("Chunky Munkey Coffee", "2 L", 1, 2.97f, 15, 04, 1997, 0);
  store.addProd(prod07);

  Meat *prod08= new Meat("Raw Salmon", "500 g", 0, 12.99f, 29, 04, 1998, 90);
  store.addProd(prod08);

  Bakery *prod09= new Bakery("Happy Baker's Hot dog buns", "12-pack", 5, 3.49f, 13, 05, 1999, 30);
  store.addProd(prod09);

  MiscGoods *prod10= new MiscGoods("Yamaha Harmonica", "8-pack", 8, 3.99f, 17, 05, 2000, 0);
  store.addProd(prod10);

  Dairy *prod11= new Dairy("Moo-cow 2% milk", "1 L", 7, 2.99f, 24, 06, 2001, 60);
  store.addProd(prod11);

  CoffeeTea *prod12= new CoffeeTea("Moo-cow 2% milk", "4 L", 3, 4.99f, 30, 06, 2002, 0);
  store.addProd(prod12);

  Meat *prod13= new Meat("Moo-cow Beef Angus Meat", "250 ml", 4, 1.49f, 14, 07, 2003, 90);
  store.addProd(prod13);

  Bakery *prod14= new Bakery("Good Morning Breakfast Croissant", "400 g", 2, 5.49f, 19, 07, 2004, 30);
  store.addProd(prod14);

  MiscGoods *prod15= new MiscGoods("Lightening Bolt Protector", "150 g", 8, 4.99f, 10, 10, 2005, 0);
  store.addProd(prod15);

  Bakery *prod16= new Bakery("Bakery Heaven Special", "100 g", 2, 4.99f, 20, 11, 2006, 60);
  store.addProd(prod16);

  CoffeeTea *prod17= new CoffeeTea("Munchies BBQ Flavoured Tea", "250 g", 7, 2.99f, 23, 11, 2007, 0);
  store.addProd(prod17);

  Meat *prod18= new Meat("Munchies Ketchup Chicken Bites", "250 g", 3, 2.99f, 27, 11, 2008, 90);
  store.addProd(prod18);

  Bakery *prod19= new Bakery("Baked Pizza Hamburgers", "210 g", 4, 1.99f, 16, 12, 2009, 30);
  store.addProd(prod19);

  MiscGoods *prod20= new MiscGoods("Dogbert Toy Robot", "180 g", 5, 2.29f, 26, 12, 2010, 0);
  store.addProd(prod20);  
 /* */
}

void InvControl::initCustomers()
{
Customer  *cust01 = new Customer("Starbuck");
  Customer *cust02= new Customer("Apollo");
  Customer *cust03= new Customer("Boomer");
  Customer *cust04= new Customer("Athena");
  Customer *cust05= new Customer("Helo");
  Customer *cust06= new Customer("Crashdown");
  Customer *cust07= new Customer("Hotdog");
  Customer *cust08= new Customer("Kat");
  Customer *cust09= new Customer("Chuckles");
  Customer *cust10= new Customer("Racetrack");

  store.addCust(cust01);
  store.addCust(cust02);
  store.addCust(cust03);
  store.addCust(cust04);
  store.addCust(cust05);
  store.addCust(cust06);
  store.addCust(cust07);
  store.addCust(cust08);
  store.addCust(cust09);
  store.addCust(cust10);

}

