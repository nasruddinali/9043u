#include<conio.h>
#include<stdio.h>
#include<iostream>
using namespace std;
class Pntr_obj
{
	int roll_no;
	char name[20];
	public:
		int setdata()
		{
			cout<<"\nRoll number=:";
			cin>>roll_no;
			fflush(stdin);
			cout<<"\nName=";
			gets(name);
		}
		void print(Pntr_obj *p1,Pntr_obj *p2,Pntr_obj *p3)
		{
			if(p1==this)
			cout<<"\nP1 invoked print() function";
			else if(p2==this)
			cout<<"\nP2 invoked print() function";
			else if(p3==this)
			cout<<"\nP3 invoked print() function";
		}
};
int main()
{
	Pntr_obj p1,p2,p3,Temp;
	p1.setdata();
	p2.setdata();
	p3.setdata();
	p2.print(&p1,&p2,&p3);
	return (0);
}
