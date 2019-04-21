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


#include "Store.h"
Store::~Store(){
	stock.prodListCleanUp();
	
	for(custIterator = customers.begin(); custIterator != customers.end(); custIterator++){
		(*custIterator)->returnPurchArr().PurchaseArrayCleanUp();
		delete *custIterator;
	}
}

ProdList& Store::getStock()     { return stock; }

list<Customer*>& Store::getCustomers() { return customers; }

void Store::addProd(Product* prod)
{
  stock.add(prod);
}

void Store::addCust(Customer* cust)
{
  customers.push_back(cust);
}

bool Store::checkIfCustExists(int& custId)
{
   for(custIterator =customers.begin(); custIterator != customers.end(); ++custIterator){
		if((*custIterator)->getId()== custId){
			return true;
		}
   }
   return false;

}
void Store::loyaltyPoints(float& priceOfProd, int& custId){
  for(custIterator =customers.begin(); custIterator != customers.end(); ++custIterator){
		if((*custIterator)->getId()== custId){
			(*custIterator)->accumulateLoyaltyPoints(priceOfProd);
		}
  }
}

int Store::returnLoyaltyPoints(int& custId){
   for(custIterator =customers.begin(); custIterator != customers.end(); ++custIterator){
		if((*custIterator)->getId()== custId){
			return (*custIterator)->getPoints();
    }
  }
}

void Store::registerPurchases(int& custId, Purchase* purc, int& prodId){
  
 for(custIterator =customers.begin(); custIterator != customers.end(); ++custIterator){
		if((*custIterator)->getId()== custId){
      
			(*custIterator)->makePurchase(purc,prodId);
      
    }
  }
    
}

void Store::tallyTotalAmount(int& custId,float& priceOfProd,int& units){
  for(custIterator =customers.begin(); custIterator != customers.end(); ++custIterator){
		if((*custIterator)->getId()== custId){
      		(*custIterator)->tallyTotalAmount(priceOfProd,units);
    }
  }
}

PurchaseArray& Store::returnPurchArray(int& custId){ 
  for(custIterator =customers.begin(); custIterator != customers.end(); ++custIterator){
		if((*custIterator)->getId()== custId){
			return (*custIterator)->returnPurchArr();
    }
  }
}




