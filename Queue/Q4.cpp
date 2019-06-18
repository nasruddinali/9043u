#include<conio.h>
#include<stdio.h>
#include<iostream>
using namespace std;
class Temp
{
	int a;
	int b;
	public:
		static int count;
		static int dcount;
		Temp()
		{
			b=9;
			a=10;
			count++;
		}
		~Temp()
		{
			cout<<"\ndestructor invoked";
			dcount++;
		}
		static void show()
		{
			cout<<"\nmade objects:"<<count;
			cout<<"\ndestroyed objects:"<<dcount;
		}
};
int Temp::count=0;
int Temp::dcount=0;
int main()
{
	Temp t1;
	Temp t2;
	Temp *t;
	t=new Temp();
	delete(t);
	Temp::show();
	return 0;
}
