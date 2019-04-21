
#ifndef TAXATIONBEHAVOUR_H
#define TAXATIONBEHAVOUR_H

//#include "Taxable.h"
//#include "NonTaxable.h"

class TaxationBehaviour
{
  public:
	TaxationBehaviour();
	~TaxationBehaviour();
	virtual float computeTax(float)=0;
  private:

};


#endif
