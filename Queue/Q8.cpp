#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
class Company
{
	int basic_sal;
	int year;
	public:
		Company()
		{
			basic_sal=0;
			year=0;
		}
		void get()
		{
			cout << "\nsalary=";
			cin >> basic_sal;
			cout << "\nyear=";
			cin >> year;
		}
		void display()
		{
			cout << "\nsalary=" << basic_sal;
			cout << "\nyear=" <<year;
		}
		Company operator +(Company c)
		{
			Company temp;
			temp.basic_sal=c.basic_sal+basic_sal;
			temp.year=c.year+year;
			return temp;
		}
		Company operator -(Company c)
		{
			Company temp;
			temp.basic_sal=c.basic_sal-basic_sal;
			temp.year=c.year-year;
			return temp;
		}
};
int main()
{
	Company c1,c2,c3;
	c1.get();
	c2.get();
	c3=c1+c2;
	cout << "\nresult of overloaded '+' operator";
	c3.display();
	c3=c1-c2;
	cout << "\nresult of overloaded '-' operator";
	c3.display();
	return(0);
}
