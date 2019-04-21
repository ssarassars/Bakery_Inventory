#ifndef COFFEETEA_H
#define COFFEETEA_H

#include <string>
#include "Product.h"
using namespace std;
//Purpose: CoffeeTea class
class CoffeeTea : public Product{

	public:
	//Purpose: constructor
    CoffeeTea(string="Unknown", string="Unknown", int=0, float=0.0f,int=0, int=0, int=0,int = 0);
    ~CoffeeTea();
};

#endif
