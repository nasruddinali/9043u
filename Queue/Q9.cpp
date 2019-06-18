#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
class Matrix
{
	int mat[10][10];
	public:
		static int n;
		void getMat();
		void display();
		Matrix operator +(Matrix M);
		Matrix operator -(Matrix M);
};
void Matrix::getMat()
{
	cout << "\nEnter the matrix";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin >> mat[i][j];
		}
	}
}
void Matrix::display()
{
	for(int i=0;i<n;i++)
	{
		cout << "\n";
		for(int j=0;j<n;j++)
			cout << mat[i][j] << " ";
	}
}
Matrix Matrix::operator +(Matrix M)
{
	Matrix m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		m.mat[i][j]=M.mat[i][j]+mat[i][j];
	}
	return m;
}
Matrix Matrix::operator -(Matrix M)
{
	Matrix m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		m.mat[i][j]=M.mat[i][j]-mat[i][j];
	}
	return m;
}
int Matrix::n=0;
int main()
{
	Matrix c1,c2,c3;
	cout << "\nEnter the size of matrix:";
	cin >> Matrix::n;
	c1.getMat();
	c2.getMat();
	c3=c1+c2;
	cout << "\nresult of overloaded '+' operator";
	c3.display();
	c3=c1-c2;
	cout << "\nresult of overloaded '-' operator";
	c3.display();
	return(0);
}

