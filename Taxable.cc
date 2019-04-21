#include "Taxable.h"

using namespace std;
Taxable::Taxable()
{

}


Taxable::~Taxable()
{

}

float Taxable::computeTax(float price)
{
  return price*0.13;
}
