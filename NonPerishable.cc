#include "NonPerishable.h"
using namespace std;


NonPerishable::NonPerishable()
{
//computeExpDate();
}

NonPerishable::~NonPerishable()
{

}

Date NonPerishable::computeExpDate(Date muDate, int ls)
{
  Date exDate=muDate+ls;
  return exDate;
}
