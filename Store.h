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

#ifndef STORE_H
#define STORE_H

#include <list>
#include "ProdList.h"
#include "Product.h"

#include "Customer.h"
//Purpose: store to keep track of the products and customers and purchases
class Store
{
  public:
	~Store();
	//Purpose: add product to store
    void       addProd(Product*);
	//Purpose: add customers to store
    void       addCust(Customer*);
	//Purpose: get the array of products
    ProdList& getStock();
	//list<Customer*>::iterator getSize();
	
	//Purpose: get the customer at an index of the array
    Customer* get(int);
	int getSize();
    //Purpose: check if a custId corresponds to a existing customer
    bool checkIfCustExists(int&);
    //Purpose: call the loyalty point accumulator after getting the custId
    void loyaltyPoints(float&, int&);
    //Purpose: return loyalty points accumulated by a customer
    int returnLoyaltyPoints(int&);
    //Purpose: register the purchases made
    void registerPurchases(int&, Purchase*,int&);
    //Purpose: return the purchase array
    PurchaseArray& returnPurchArray(int& );
    //Purpose: calculate the total amount of purchase made
    void tallyTotalAmount(int&,float&,int&);
	list<Customer*>& 	getCustomers(); //retrieve our CustArray
//Purpose:  get the array of customers
    //CustArray& getCustomers();
	
//Purpose: get the array of purchases
   // PurchaseArray& getPurchase();
  private:
    ProdList  stock;
    list<Customer*> customers;
	list<Customer*>::iterator custIterator;
	int size;
	//CustArray  customers;
    
};

#endif
