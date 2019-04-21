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

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

#include "Product.h"
#include "PurchaseArray.h"

//Purpose: Customer class
class Customer
{
  public:
    
    //Purpose: constructor
    Customer(string="Unknown");
    //Purpose: Destructor
    ~Customer();
    //get the Id of teh customer
    int    getId();
    //Purpose: get the name of customer
    string getName();
    //Purpose: get the total loyalty points
    int    getPoints();
    ////Purpose: get the total amount purchased
    float getTotalAmount();
    //Purpose: accumulate the loyalty points calculated
    void accumulateLoyaltyPoints(float&);
    //Purpose: add purchase to customer class
    void makePurchase(Purchase*,int&);
    //Purpose: tally total amount of purchases made
    void tallyTotalAmount(float&,int&);
    //Purpose: return purchase array
    PurchaseArray& returnPurchArr();
  protected:
    static int nextCustId;
    int        id;
    string     name;
    int        points;
    float        totalAmount;
    PurchaseArray purchArr;
};

#endif
