#ifndef PERISHABLE_H
#define PERISHABLE_H

#include "defs.h"
//class ExpirationBehaviour
#include "ExpirationBehaviour.h"


class Perishable : virtual public ExpirationBehaviour
{
public:
  Perishable();
  ~Perishable();
  Date computeExpDate(Date, int);
  private:
    //int lifespan;
    
};

#endif
