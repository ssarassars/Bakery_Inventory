#include "Dairy.h"

Dairy::Dairy(string n, string s, int u, float p,int day, int month, int year, int ls) : Product(n, s, u, p, day, month, year,ls)
{ 
  expBehaviour= new Perishable();
  taxBehaviour= new NonTaxable();
  computeExpDate();
}

Dairy::~Dairy(){
	
}


