
#ifndef EXPIRATIONBEHAVIOUR_H
#define EXPIRATIONBEHAVIOUR_H

#include "Date.h"

class ExpirationBehaviour
{
  public:
	ExpirationBehaviour();
	~ExpirationBehaviour();
	virtual Date computeExpDate(Date, int)=0;
};


#endif
