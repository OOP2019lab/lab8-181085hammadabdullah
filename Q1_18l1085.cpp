// Q1_18l1085.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "q1_18l1085.h"
string Date::monthNames[13]={ "", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"} ;
Date::Date(){//Default values
	day=1;
	mon=1;
	year=2000;
}
Date::Date(int m,int d,int y){
	if(d<1 || d>30){//conditions for invalid day
			day=1;
		}
	else{
day=d;
	}
	if(m<1 || m>12){//conditions for invalid month
			mon=1;
		}
	else{
mon=m;
	}
	
	if(y<1 || y>12){//conditions for invalid year
			year=2000;
		}
	else{
year=y;
	}

}
Date::Date(const Date &obj){//Copy constrctor
	year=obj.year;
	mon=obj.mon;
	year=obj.year;
}
Date &Date::operator--(){//pre increment
	day=day-1;
if(day<1){
mon=mon-1;
day=30;
}
return *this;
}
Date &Date::operator--(int dummy){//post increment
	Date temp=*this;
day=day-1;
if(day<1){
mon=mon-1;
day=30;
return temp;
}
}
int Date::operator[](int n){//subscript opertor
	if(n<0 && n>2){
	cout<<"only index 0 , 1 and 2 present"<<endl;
	}
	else{
	if(n==0){
		return day;
	}
	if(n==1){
		return mon;
	}
	if(n==2){
		return year;
	}
	}
}


