#ifndef MEAT_H
#define MEAT_H

#include <string>
#include "Product.h"
using namespace std;
//Purpose: Meat class
class Meat : public Product{

	public:
	//Purpose: constructor
    Meat(string="Unknown", string="Unknown", int=0, float=0.0f,int=0, int=0, int=0,int = 0);
    ~Meat();
};

#endif
