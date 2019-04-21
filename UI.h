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

#ifndef UI_H
#define UI_H

#include <string>
using namespace std;

#include "ProdList.h"
#include "Store.h"
#include <list>
#include "Customer.h"
//Purpose: user interface to print to user
class UI
{
  public:
    
    void mainMenu(int&);
    //Purpose: admin menu access 
    void adminMenu(int&);
	//Purpose: cashier menu access 
    void cashierMenu(int&);
	//Purpose: integer input function
    void promptForInt(string, int&);
	//Purpose: string input function
    void promptForStr(string, string&);
	//Purpose: float input function
    void promptForFloat(string, float&);
	//Purpose: print an error message
    void printError(string);
	//Purpose: pring usage error
    void printUsageError();
	//Purpose: print product information
    void printStock(ProdList&);
	//Purpose: print customer information
    void printCustomers(list<Customer*>&);
	//Purpose: print purchase information
    void printPurchases(PurchaseArray&);
	//Purpose: print string message
    void printString(string);
	//Purpose: pause to view
    void pause();

  private:
    int    readInt();
};

#endif
