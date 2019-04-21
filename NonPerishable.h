#ifndef NONPERISHABLE_H
#define NONPERISHABLE_H

#include "defs.h"
//class ExpirationBehaviour
#include "ExpirationBehaviour.h"

class NonPerishable :  virtual public ExpirationBehaviour
{

public:
  NonPerishable();
  ~NonPerishable();
  Date computeExpDate(Date, int);
private:

};

#endif
