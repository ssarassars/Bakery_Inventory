#ifndef BAKERY_H
#define BAKERY_H

#include <string>
#include "Product.h"
using namespace std;
//Purpose: Bakery class
class Bakery : public Product
{
  public:
	//Purpose: constructor
    Bakery(string="Unknown", string="Unknown", int=0, float=0.0f,int=0, int=0, int=0, int=0);
    ~Bakery();
};

#endif
