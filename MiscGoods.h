#ifndef MISCGOODS_H
#define MISCGOODS_H

#include <string>
#include "Product.h"
using namespace std;
//Purpose: MiscGoods class
class MiscGoods : public Product{

	public:
		MiscGoods(string="Unknown", string="Unknown", int=0, float=0.0f,int=0, int=0, int=0,int = 0);
		~MiscGoods();
	

    
};

#endif
