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

#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include "Date.h"
#include "Defs.h"

#include "Perishable.h"
#include "NonPerishable.h"
#include "Taxable.h"
#include "NonTaxable.h"

using namespace std;
//Purpose: Product class
class Product
{
  public:
	//Purpose: constructor
    Product(string="Unknown", string="Unknown", int=0, float=0.0f,int=0, int=0, int=0,int = 0);
    
	virtual ~Product();
	//Purpose: get the id of the product
    int    getId();
     
	//Purpose: get the name of the product
    string getName();
	//Purpose: get the size of the product
    string getSize();
	//Purpose: get the units of product
    int    getUnits();
	//Purpose: get the price of the product
    float  getPrice();
	Date getExpiryDate();
	//Purpose: reduce the products in stock
    void   reduce();
        //Purpose: increase units of product
    void increase(int&);
	
    float computeTax();
    void computeExpDate();
  protected:
	
	static int nextProdId;
    int        id;
    string     name;
    string     size;
    int        units;
    float      price;
    
	Date manufacturedDate;
    Date expiryDate;
	int lifeSpan;
	
	TaxationBehaviour* taxBehaviour;
	ExpirationBehaviour* expBehaviour;
	
	
};

#endif
