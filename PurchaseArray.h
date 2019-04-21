#ifndef PURCHASEARRAY_H
#define PURCHASEARRAY_H

#include "defs.h"
#include "Purchase.h"
//Purpose: Store purchases made in an array
class PurchaseArray
{
  public:
    //Purpose: Constructor
    PurchaseArray();
    //Purpose: Deconstructor
    void PurchaseArrayCleanUp();
    //Purpose: Add to purchase array
    void add(Purchase*);
    //Purpose: getter for index
    Purchase* get(int);
    //Purpose: get size of the array
    int getSize();
    //Purpose: check if the purchase exists in the array if it doesnt add to array
    bool checkIfExists(Purchase*);
    //Purpose: return the units of product bought for the purchase
    int returnUnitsOfProd(int&);
	int increaseUnitsOfProd(int& );
  private:
    Purchase *purchArr[MAX_ARR];
    int size;
    
};
#endif
