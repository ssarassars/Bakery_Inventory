#ifndef NONTAXABLE_H
#define NONTAXABLE_H
#include "defs.h"
#include <string>
using namespace std;
#include "TaxationBehaviour.h"

class NonTaxable : public TaxationBehaviour
{
	
  public:
    NonTaxable();
    ~NonTaxable();
    float computeTax(float);
  protected:
     float taxRate;

};

#endif
