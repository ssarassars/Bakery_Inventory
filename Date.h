#ifndef DATE_H
#define DATE_H

#include <string>
#include <sstream>
using namespace std;
//Purpose: Date class
class Date
{
  public:
	//Purpose: constructor
    Date();
	Date(int,int,int);
    ~Date();
	Date& operator += (int);
	Date operator + (int);
	//bool operator < (const Date&);
	bool operator < (const Date&);
	string toString();

    
  protected:
    int        day;
    int        month;
    int        year;

};

#endif
