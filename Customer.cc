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

#include <cmath>
#include "Customer.h"

int Customer::nextCustId = 2001;

Customer::Customer(string n)
{ 
  id     = nextCustId++;
  name   = n;
  points = 0;
  totalAmount = 0.0;
  
}

Customer::~Customer()
{
  //delete purchArr;
}

int    Customer::getId()     { return id;     }
string Customer::getName()   { return name;   }
int    Customer::getPoints() { return points; }
float  Customer::getTotalAmount() { return totalAmount;}


void Customer::accumulateLoyaltyPoints(float& priceOfProd){
	int pointsToAdd;
	float priceOfProdRounded;
	priceOfProdRounded = ceil(priceOfProd);
	pointsToAdd = (int) priceOfProdRounded;
	points = points + pointsToAdd;

}

void Customer::tallyTotalAmount(float& priceOfProd, int& units){ 
  totalAmount += priceOfProd * units;
} 

void Customer::makePurchase(Purchase* purc,int& prodId){ 
  //purchArr.increaseUnitsOfProd(prodId);
  purchArr.add(purc);
  
  
}

PurchaseArray& Customer::returnPurchArr(){
  return purchArr;
}
