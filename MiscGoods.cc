#include "MiscGoods.h"

MiscGoods::MiscGoods(string n, string s, int u, float p,int day, int month, int year, int ls) : Product(n, s, u, p, day, month, year,ls)
{
    expBehaviour = new NonPerishable();
	taxBehaviour = new NonTaxable();
	computeExpDate();
}

MiscGoods::~MiscGoods()
{
	
}