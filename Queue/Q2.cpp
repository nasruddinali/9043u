#include<stdio.h>
#include<iostream>
using namespace std;
class Reverse
{
	int num,r;
	public:
		void getNum();
		int reverse();
};
void Reverse::getNum()
{
	cout << "\nEnter the number=";
	cin >> num;
}
int Reverse::reverse()
{
	int n=num;
	int rem,rev=0;
	while(n>0)
	{
		rem=num%10;
		rev=rev*10+rem;
		num/=10;
	}
	return rev;
}
int main()
{
	Reverse r;
	r.getNum();
	int re=r.reverse();
	cout <<"Reverse number=" << re;
	return(0);
}
