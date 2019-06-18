#include<stdio.h>
#include<iostream>
using namespace std;
class Arithmetic
{
	int a,b;
	public:
		Arithmetic()
		{
			a=0;
			b=0;
		}
		void getData()
		{
			cout << "\n Enter the value of a";
			cin >> a;
			cout << "\n Enter the value of b";
			cin >> b;
		}
		int add()
		{
			return(a+b);
		}
		int sub()
		{
			return(a-b);
		}
		int mod()
		{
			if(b==0)
			{
				cout <<"\na cannot not be mod by b";
			}
			else
			{
			return(a%b);
			}
		}
		int mul()
		{
			return(a*b);
		}
};
int main()
{
	int c;
	Arithmetic d;
	d.getData();
	c=d.add();
	cout << "\nAddition=" << c;
	c=d.sub();
	cout << "\nSubtraction=" << c;
	c=d.mul();
	cout << "\nMultiplication=" << c;
	c=d.mod();
	cout << "\nModulous=" << c;
	return(0);
}
