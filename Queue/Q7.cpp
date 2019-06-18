#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
class Bank
{
	int count;
	char emp_id[10][10];
	char emp_name[10][10];
	public:
		Bank()
		{
			count=0;
		}
		void enter()
		{
			cout << "\nEnter id";
			gets(emp_id[count]);
			cout << "\nEnter name";
			gets(emp_name[count]);
		}
		void operator +()
		{
			count++;
		}
		void operator -()
		{
			if(count>0)
			{
				count--;
			}
			else
			{
				cout << "\nNo Person present in Bank";
			}
		}
		void display()
		{
			for(int i=0;i<count;i++)
			{
				cout << "\nID:" << emp_id[i] << "\tName:" << emp_name[i];
				cout << "\nTotal:" << count;
			}
		}
};
int main()
{
	Bank b;
	int ch;
	do
	{
		cout << "\n1.Enter Bank";
		cout << "\n2.Leave Bank";
		cout << "\n3.Total persons in Bank";
		cout << "\n4.Exit menu";
		cout << "\nEnter ur choice";
		cin >> ch;
		switch(ch)
		{
			case 1:
				b.enter();
				b++;
				break;
			case 2:
				b.enter();
				b--;
				break;
			case 3:
				b.display();
				break;
			case 4:
				break;
		}
	}while(ch!=4);
}
