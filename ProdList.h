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

#ifndef PRODLIST_H
#define PRODLIST_H

#include <string>
#include "defs.h"
#include "Product.h"
//Purpose: to keep an array of product classes
class ProdList
{
	class Node
	{
	friend class ProdList;
	private:
	        Product* data;
	        Node* next;
	        Node* prev;
	};

  public:
    //Purpose: constructor
    ProdList();
    //Purpose: Destructor
    void prodListCleanUp();
	//Purpose: add products to array
    void add(Product*);
	//Purpose: get the product id
    int getSize();
	//Purpose: check if the product exists
    bool checkIfProdExists(int&);
	//Purpose: check if the product is in stock
    bool checkIfProdInStock(int&);
	//Purpose: reduce the number of units in stock
    void reduceStockUnits(int&);
	//Purpose: get the price of the product
    float getPriceOfProduct(int&);
	//Purpose: get the name of the product 
    string getNameOfProd(int&);
	//Purpose: get the unist of products
    int    getUnitsOfProd(int&);
        //Purpose: increase units of stock
    void increaseStockUnits(int&, int&);
	
	Product* get(int&);
	//Purpose: remove product from the product list
    void remove(Product*);
	//Purpose: reorganise by swapping the linked list nodes based on the units
    void reorg();
	//Purpose: find the product given the id of the product
    Product* find(int&);
	//Purpose: toString concatenate print the data of the products
    void toString(string&);
  private:
    Node* head;
};

#endif

