#include <string>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "PurchaseArray.h"

PurchaseArray::PurchaseArray()
{
  size = 0;
 
}

void PurchaseArray::PurchaseArrayCleanUp()
{
  for(int i=0; i<size; i++){
     delete purchArr[i];
 }
}

int PurchaseArray::getSize() { return size; }

Purchase* PurchaseArray::get(int index)
{
  if (index < 0 || index >= size)
    exit(1);
  return purchArr[index];
}

void PurchaseArray::add(Purchase* purch)
{
  bool checkExists = checkIfExists(purch);
  
  
  if (size >= MAX_ARR)
    return;
  
  if(checkExists == false){ 
    purchArr[size++] = purch;
  }
  
}

bool PurchaseArray::checkIfExists(Purchase* purch){ 
  
  //cout<<purchArr[0]->getId()<<endl;
  for(int i =0; i < size; i++){ 
    if(purchArr[i]->getId() == purch->getId()){ 
      
      purchArr[i]->incrementUnits();
      return true;
   } 
  }
  
  return false;
}

int PurchaseArray::returnUnitsOfProd(int& prodId){
   for(int i =0; i < size; i++){ 
		if(purchArr[i]->getId() == prodId){ 
			purchArr[i]->getUnits();
		}

   }
}

int PurchaseArray::increaseUnitsOfProd(int& prodId){
	for(int i =0; i < size; i++){ 
		if(purchArr[i]->getId() == prodId){ 
			purchArr[i]->incrementUnits();
		}

   }
}


