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

#include "Product.h"


int Product::nextProdId = 5001;

Product::Product(string n, string s, int u, float p, int day, int month, int year,int l)
{ 
  id    = nextProdId++;
  name  = n;
  size  = s;
  units = (u >= 0) ? u : 0;
  price = (p >= 0) ? p : 0;
  manufacturedDate = Date(day, month, year);
  lifeSpan = (l ==0) ? Default_Life_Span: l;

}
Product::~Product()
{
	delete expBehaviour;
	delete taxBehaviour;
}


int    Product::getId()    { return id;    }
string Product::getName()  { return name;  }
string Product::getSize()  { return size;  }
int    Product::getUnits() { return units; }
float  Product::getPrice() { return price; }
Date Product::getExpiryDate(){return expiryDate;}

//tax to be paid on the product
float Product::computeTax(){
	return taxBehaviour->computeTax(price);
}
//expiry date of the product
void Product::computeExpDate(){
	expiryDate = expBehaviour->computeExpDate(manufacturedDate,lifeSpan); 
}

void Product::reduce()
{
  units--;
}

void Product::increase(int& prodUnits) {
 
units = units + prodUnits;

}


