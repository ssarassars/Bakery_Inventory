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

#ifndef INVCONTROL_H
#define INVCONTROL_H
#include "defs.h"

#include "Store.h"
#include "UI.h"
#include "Purchase.h"

#include "Dairy.h"
#include "MiscGoods.h"
#include "Meat.h"
#include "Bakery.h"
#include "CoffeeTea.h"

//Purpose: to keep track of the flow of products and customers
class InvControl
{
  public:
    //Purpose: Constructor
    InvControl();
    
    //Product* newProduct;
    //Customer* newCustomer;
    //Purpose: launch the program
    void launch(int, char*[]);
  private:
    Store     store;
    UI        view;
    //Purpose: Initialize products
    void      initProducts();
    //Purpose: Initialize customers
    void      initCustomers();
    //Purpose: access admin menu
    void      processAdmin();
    //Purpose: access cashier menu
    void      processCashier();
};
#endif
