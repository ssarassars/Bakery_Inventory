#ifndef PURCHASE_H
#define PURCHASE_H

//#include "Store.h"
//#include "UI.h"

#include <string>
using namespace std;
//Purpose: purchase class
class Purchase
{
  public:
	//Purpose: constructor
    Purchase(string="Unknown",int=0, int =0); //product id and units 
    ~Purchase();
  //Purpose: get the product id
    int getId();
	//Purpose: get the units of purchase
    int getUnits();
	//Purpose: increment the units of products
    void  incrementUnits();
	//Purpose: get the name of the product
    string getName();
  private:
    int id; //id of the purchased Product 
    int purchaseUnits;
    string name;
    
};
#endif
