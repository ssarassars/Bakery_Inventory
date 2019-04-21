#include "Date.h"

#include <iostream>
Date::Date()
{
  Date(0,0,0);
}

Date::Date(int d, int m, int y):day(d),month(m),year(y) {
  

}

Date::~Date() {

}

Date& Date::operator+= (int numDays)

{
	int random = 0;
	if(numDays>=365){
            year += numDays/365;
            if(numDays%365 >= 30){
                 month += ((numDays%365)/30);
                 day += ((numDays%365)%30);
                  }
         }else if(numDays >= 30 && numDays < 365){
                 month += (numDays/30);
                 day += (numDays%30);  
         }else if(numDays>=0 && numDays < 30){
                 day += numDays;
         }else {
                 random = 0;
            }
                  
        return *this;
}



Date Date::operator+(int numDays) {

    Date dateNew = Date(day, month, year);
	dateNew += numDays;
	return dateNew;
}

bool Date::operator<(const Date& other) 
{
    if(year < other.year){
	return true;
    }else if(year > other.year){
        return false;
    }else { 
		if(month< other.month){
            return true;
		}else if (month >other.month){
			return false;
		}else {
			if(day < other.day){
				return true;
			}else if (day > other.day){
				return false;
			}
		}
    }
       
    return false;
}
string Date::toString()
{
  stringstream ss;
	
  ss<<day<<"/"<<month<<"/"<<year;
  return ss.str();
}
