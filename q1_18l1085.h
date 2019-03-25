#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;
//We not need friend function with class name beacuse friend function knows the class of object which we use in that friend function for example
//in this case obj is member of class Date so when we use Date obj friend function knows about that obj is member of date class and this 
//frirnd fuction access its private variables and functions easily
class Date{
	friend ostream &operator<<(ostream &out,Date &obj){// Cout OPerator
		out<<obj.monthNames[obj.mon]<<" "<<obj.day<<" , "<<obj.year<<endl;
		return out;
	}
	friend istream &operator>>(istream &in,Date &obj){
		cout<<endl;
		cout<<"Enter Day Of Date : ";
		in>>obj.day;
		if(obj.day<1 || obj.day>30){//conditions for invalid day 
			obj.day=1;
		}
		cout<<"Enter Month Of Date : ";
		in>>obj.mon;
		 if(obj.mon<1 || obj.mon>12){//conditions for invalid month
			obj.mon=1;
		}
		cout<<"Enter Year Of Date : ";
		in>>obj.year;
		if (obj.year<1000 || obj.year>9999){//conditions for invalid year
			obj.year=2000;
		}
		return in;
	}//Cin operator
	friend Date & operator+(Date &obj,int n){
		obj.day=obj.day+n;
		if(obj.day>30){
			obj.mon=obj.mon+1;
			if(obj.mon>12){
				obj.mon=1;
				obj.year=obj.year+1;
			}
			obj.day=1;
		}
		return obj;
	}
private:
	int day;
	int mon;
	int year;
	static string monthNames[13];
public:
	Date();
	Date(int m,int d,int y);
	Date(const Date &obj);
	
	
	bool operator==(Date &obj){
		if(day==obj.day && mon==obj.mon && year==obj.year){
			return true;
		}
		else{
			return false;
		}
	}
	Date& operator--();
	Date& operator--(int dummy);
	int operator[]( int n);
};
