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

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "UI.h"
using namespace std;


void UI::adminMenu(int& choice)
{
  string str;

  choice = -1;

  cout<< "\n\n\n                   INVENTORY MANAGEMENT SYSTEM ADMIN MENU\n\n";
  cout<< "          1. Add new product \n\n";
  cout<< "          2. Remove Product \n\n";
  cout<< "          3. Add more inventory \n\n";
  cout<< "          4. Print inventory \n\n";
  cout<< "          5. Print customers \n\n";
  cout<< "          0. Exit\n\n";

  while (choice < 0 || choice > 5) {
    cout << "Enter your selection:  ";
    choice = readInt();
  }
}

void UI::cashierMenu(int& choice)
{
  string str;

  choice = -1;

  cout<< "\n\n\n                   INVENTORY MANAGEMENT SYSTEM CASHIER MENU\n\n";
  cout<< "          1. Product purchases\n\n";
  cout<< "          2. Product returns\n\n";
  cout<< "          0. Exit\n\n";

  while (choice < 0 || choice > 2) {
    cout << "Enter your selection:  ";
    choice = readInt();
    if (choice == MAGIC_NUM) return;
  }
}

void UI::printStock(ProdList& list)
{
  // The stringstream class helps us convert from numeric values to string.
  // The I/O manipulation functions help us make the output look pretty.
  stringstream ss;

  
  string li;
  list.toString(li);
  cout << endl << "STOCK: " << endl << endl;
  cout << " ID                                 Name         Size    Qty   Price     Date" << endl;
  cout << " --                                 ----         ----    ---   -----    --------"<< endl;
  
  cout<<li<<endl;
}


void UI::printPurchases(PurchaseArray& purch)
{
   cout << endl << "PURCHASES: " << endl << endl;

   for(int i=0; i<purch.getSize(); i++){
     
     Purchase* p = purch.get(i);
     
     cout << p->getId() << "  " << setw(10) << p->getName()<< "  " << setw(4) <<p->getUnits() << endl;
    
   }

}

void UI::printCustomers(list<Customer*>& customers)
{
  cout << endl << "CUSTOMERS: " << endl << endl;
  list<Customer*>::iterator custIterator;
  for(custIterator = customers.begin(); custIterator != customers.end(); custIterator++){
	 cout << (*custIterator)->getId() << "  " << setw(10) << (*custIterator)->getName() 
         << "  " << setw(4) << (*custIterator)->getPoints() << setw(10) << (*custIterator)->getTotalAmount() << endl;
  
  
	//(*custIterator)->getId()
  }
  
}

void UI::printError(string err)
{
  cout << endl << err << " -- press enter to continue...";
  cin.get();
}
void UI::printString(string str){
  cout << endl << str << endl;
}
void UI::printUsageError()
{
  cout << endl << "Usage:  cushop OPTION" << endl << endl;
  cout <<         "        where OPTION is either: " << endl;
  cout <<         "              -a  Admin menu"        << endl;
  cout <<         "              -c  Cashier menu"      << endl << endl;
}

void UI::promptForInt(string prompt, int& num)
{
  cout << prompt << ": ";
  num = readInt();
}

void UI::promptForStr(string prompt, string& str)
{
  cout << prompt << ": ";
  getline(cin, str);
}

void UI::promptForFloat(string prompt, float& num)
{
  string str;

  cout << prompt << ": ";
  getline(cin, str);

  stringstream ss(str);
  ss >> num;
}

int UI::readInt()
{
  string str;
  int    num;

  getline(cin, str);
  stringstream ss(str);
  ss >> num;

  return num;
}

void UI::pause()
{
  string str;

  cout << endl << "\nPress enter to continue...";
  getline(cin, str);
}

