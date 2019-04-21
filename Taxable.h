#ifndef TAXABLE_H
#define TAXABLE_H
#include "defs.h"
#include <string>
#include "TaxationBehaviour.h"
using namespace std;

//Purpose: Taxable class
class Taxable : public TaxationBehaviour
{

  public:
    Taxable();
    ~Taxable();
    float computeTax(float);

  protected:
    float taxRate;
    
};

#endif
