#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
class Polygon
{
	public:
		virtual int area()
		{
			cout<<"\npolygon class area() function";
		}
};
class Rectangle:public Polygon
{
	int base;
	int height;
	public:
		Rectangle(int b,int h)
		{
			base=b;
			height=h;
		}
		int area()
		{
			cout<<"\nrectangle class area() called";
			cout<<"\nthe area of rectangle:"<<base*height;
		}
};
class Triangle:public Polygon
{
	int base;
	int height;
	public:
		Triangle(int b,int h)
		{
			base=b;
			height=h;
		}
		int area()
		{
			cout<<"\ntriangle class area() called";
			cout<<"\narea of triangle is:"<<0.5*base*height;
		}
};
int main()
{
	Polygon *c;
	c=new Rectangle(3,6);
	c->area();
	delete(c);
	c=new Triangle(6,8);
	c->area();
	delete(c);
	return(0);
}
