#include "Purchase.h"

Purchase::Purchase(string n, int productId, int u)
{ 
  name = n;
  id  = productId;
  purchaseUnits = u;
  
}

Purchase::~Purchase(){
  
}


int    Purchase::getUnits()    { return purchaseUnits;   }
int    Purchase::getId()       { return id;              }
string Purchase::getName()     {return name;}
void   Purchase::incrementUnits(){ purchaseUnits = purchaseUnits+1;}
