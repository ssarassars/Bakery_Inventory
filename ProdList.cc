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

#include <string>
#include <cstdlib>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

#include "ProdList.h"

ProdList::ProdList() : head(0) 
{
 
}

void ProdList::prodListCleanUp()
{
  Node* currNode = head;
  Node* nextNode;

  while(currNode != NULL){
    nextNode = currNode->next;
    delete currNode->data;
    delete currNode;
    currNode = nextNode;
  }
}

Product* ProdList::find(int& prodId){
Node* currNode = head;


  while(currNode != NULL){
    if(currNode->data->getId() == prodId)
      break;
    currNode = currNode->next;
  }
return (currNode->data);
}

void ProdList::add(Product* prod)
{
  Node* newProdNode = new Node;
  Node* currNode;
  Node* prevNode;

  newProdNode->data = prod;
  newProdNode->next = NULL;
  newProdNode->prev = NULL;

  currNode = head;
  prevNode = NULL;

  
    while(currNode != NULL){
      if(newProdNode->data->getExpiryDate() < currNode->data->getExpiryDate())
        break;
        prevNode = currNode;
        currNode = currNode->next;
    }
    
    if (prevNode == NULL){                   //add to front of list
      if(head !=NULL){
        head->prev = newProdNode;
        newProdNode->next = head;
      
      }
      head = newProdNode;
      //newProdNode->prev = head;
      
    }else{
      prevNode->next = newProdNode;      //add to middle of list
      newProdNode->prev = prevNode;
      if(currNode !=NULL){
          currNode->prev = newProdNode;
      }
     
    }
    newProdNode->next = currNode;
  }


void ProdList::remove(Product* prod) {

  Node* currNode;
  Node* prevNode;

  currNode = head;
  prevNode = NULL;   //CAUSE UI PROMPT CHECKS FOR AVAILABILITY OF PRODUCT NO NEED TO INCLUDE EMPTY LIST CASE

 	while(currNode != NULL){
		
    if(prod->getId() == currNode->data->getId())
			break;
      prevNode = currNode;
      currNode = currNode->next;
  }

	if (prevNode == NULL){                   //remove from front of list
   // currNode->next->prev = NULL;
    //currNode->next->next= head->next;
    head = currNode->next;
    head->prev = NULL;
	
	}else{
    prevNode->next = currNode->next;
    if(prevNode->next !=NULL){
        prevNode->next->prev = prevNode;
    }
    
    
    //currNode->prev = prevNode;
   //currNode->prev->next = currNode->next;      //remove from middle of list
	  //currNode->next->prev = currNode->prev;
  }
  
  delete currNode->data;
  delete currNode; //deallocate memory for the removed object node
}

void ProdList::reorg()          //PASS IN THE LIST AS PARAMETER?? --> FUNC CALLED IN REDUCE/ADD STOCK FUNCS BELOW
{
  Node* currNode;   
  currNode = head;
  Node* nextNode = currNode->next;
  int i;
  int count = 0;

  while(currNode != NULL){
    count++;
    currNode = currNode->next;
  }

  for(i=0; i<count; ++i){
   currNode = head;
   nextNode = currNode->next;
	
  while (nextNode != NULL) { 
      if (currNode->data->getUnits() > nextNode->data->getUnits()) {
        if(nextNode->next!=NULL){
            nextNode->next->prev = currNode;
        }
        
   
        currNode->next = nextNode->next;
        nextNode->next = currNode;
        nextNode->prev = currNode->prev;
        if(currNode->prev !=NULL){
     
          currNode->prev->next = nextNode;
          currNode->prev = nextNode;
        }else {
          currNode->prev = nextNode;
          head = nextNode;
          nextNode->prev = NULL;
        }
        
        
      }
      currNode = nextNode;
      nextNode = nextNode->next;
  }
 }
} 
bool ProdList::checkIfProdExists(int& prodId){  

Node* currNode = head;

  while(currNode != NULL){
    if(currNode->data->getId() == prodId){
      return true;
    }else{
    currNode = currNode->next;
    }
  }
return false;
}

bool ProdList::checkIfProdInStock(int& prodId){  
 
Node* currNode = head;

while(currNode != NULL){
	if(currNode->data->getId() == prodId && currNode->data->getUnits()>0){
             return true;
        }else{
	currNode = currNode->next;
     }
}
return false;
}


void ProdList::reduceStockUnits(int& prodId)
{

  Node* currNode = head;

  while(currNode != NULL){
    if(currNode->data->getId() == prodId)
      break;
    currNode = currNode->next;
  }
  currNode->data->reduce();
  reorg();
}

void ProdList::increaseStockUnits(int& prodId, int& prodUnits)
{

  Node* currNode = head;

  while(currNode != NULL){
    if(currNode->data->getId() == prodId)
      break;
    currNode = currNode->next;
  }
  currNode->data->increase(prodUnits);
  reorg();
}

float ProdList::getPriceOfProduct(int& prodId){

Node* currNode = head;

while(currNode != NULL){
	if(currNode->data->getId() == prodId)
             break;
	currNode = currNode->next;
     }
return currNode->data->getPrice();
}

Product* ProdList::get(int& prodId){ 
	Node* currNode = head;
	while(currNode != NULL){
	if(currNode->data->getId() == prodId)
             break;
	currNode = currNode->next;
     }
	return currNode->data;
	
}

string ProdList::getNameOfProd(int& prodId){

  Node* currNode = head;

  while(currNode != NULL){
    if(currNode->data->getId() == prodId)
      break;
    currNode = currNode->next;
  }
  return currNode->data->getName(); 
}


int ProdList::getUnitsOfProd(int& prodId){

Node* currNode = head;

while(currNode != NULL){
	if(currNode->data->getId() == prodId)
             break;
	currNode = currNode->next;
     }
return currNode->data->getUnits();
}


void ProdList::toString(string& outStr){   
  
stringstream ss;
stringstream ps;
stringstream ns;
  
  Node* currNode = head;
  Node* finalNode= NULL;

  while (currNode != NULL){
    
    ss << currNode->data->getId()   << "  " << setw(35) << currNode->data->getName() << "  "
         << setw(10) << currNode->data->getSize() << "  " << setw(4)  << currNode->data->getUnits() << "    ";
	//ss<<currNode->data->getExpiryDate().toString();
    
    ps << setw(6) << fixed << setprecision(2) << currNode->data->getPrice();
	ss << "$" << ps.str();
    ss<<setw(14)<<currNode->data->getExpiryDate().toString()<<endl;
	//ss.str("");
	//ss<<setw(3)<<currNode->data->getUnits()<<setw(40)<<currNode->data->getName()<<setw(8)<<currNode->data->getId()<<setw(17)<<currNode->data->getExpiryDate().toString()<<"\n";

	outStr +=ss.str();
    ss.str("");
    ps.str("");
    finalNode = currNode;
   currNode = currNode->next;
  }
  
  
  while(finalNode != NULL){ 
  ss << finalNode->data->getId()   << "  " << setw(40) << finalNode->data->getName() << "  "
         << setw(10) << finalNode->data->getSize() << "  " << setw(4)  << finalNode->data->getUnits() << "    ";

    ps << setw(6) << fixed << setprecision(2) << finalNode->data->getPrice();

    ss << "$" << ps.str() << endl;
    outStr +=ss.str();
    ss.str("");
    ps.str("");
    finalNode = finalNode->prev;
  
  }
}

