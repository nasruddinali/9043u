#include<stdio.h>
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int main()
{
	int ch,flag=0,flag1;
	char datafile[20],src[20],phone[10];
	while(1)
	{
		cout << "\n Menu\n1.Add\n2.Delete\n3.Search\n4.Save\n5.Exit\nEnter ur choice:";
		cin >> ch;
		switch(ch)
		{
			case 1:
				ofstreamoutfile;
				outfile.open("arshad.txt",ios::app);
				cout << "\nEnter ur name=";
				cin.ignore();
				cin.getline(datafile,20);
				outfile << datafile << "";
				cout << "Enter ur phone:";
				cin.ignore();
				cin.getline(phone,10);
				outfile << phone << endl;
				outfile.close();
				break;
				case 2:
				ifstreamfile("abc.txt");
				ofstreamoutfile("temp.txt");
				cout << "\nEnter name u want to Delete from database:";
				cin.ignore();
				cin.getline(src,20);
				while(infile>>datafile>>phone)
				{
					if(strcmp(datafile,src))
					{
						flag1=0;
						outfile << datafile << ' ' << phone << endl;
					}
					else
						flag1=1;
				}
				infile.close();
				outfile.close();
				remove("arshad.txt");
				rename("temp.txt","abc.txt");
				if(flag1==0)
				{
					cout << "there is no record with the name u entered" << endl;
				}
				else
					cout << "Record has been deleted" << endl;
				break;
				case 3:
				ifstreamfile;
				infile.open("arshad.txt");
				cout << "\nEnter name of person to be searched:";
				cin.ignore();
				cin.getline(src,20);
				while(infile>>datafile>>phone)
				{
					if(strstr(datafile,src))
					{
						flag=1;
						break;
					}
					else
						flag=0;
				}
				if(flag==1)
				{
					cout << "\nRecord found";
					cout << "\nName:" << datafile << "\nPhone:" << phone << endl;
				}
				else
					cout << "\nRecord not found";
				infile.close();
				break;
				case 4:
				ifstreamfile;
				infile.open("arshad.txt");
				while(infile>>datafile>>phone)
					cout << "Name:" << datafile << "\nPhone:" <<phone << endl;
				break;
				case 5:
				return(0);
		}
	}
	return(0);
}
