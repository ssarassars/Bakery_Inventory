#include "Perishable.h"

//Contructor
Perishable::Perishable()
{
//computeExpDate();
}

//Dectructord
Perishable::~Perishable()
{

}

Date Perishable::computeExpDate(Date muDate, int ls)
{
  Date exDate = muDate+ls;
  return exDate;
}
