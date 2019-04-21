#include "CoffeeTea.h"

CoffeeTea::CoffeeTea(string n, string s, int u, float p,int day, int month, int year, int ls) : Product(n, s, u, p, day, month, year,ls){
  taxBehaviour   = new Taxable();
  expBehaviour = new NonPerishable();
  computeExpDate();

}
CoffeeTea::~CoffeeTea(){
	
}


