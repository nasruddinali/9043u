#include<stdio.h>
#include<iostream>
using namespace std;
class VowelCount
{
	public:
		static int count_vowel(char *p);
};
int VowelCount::count_vowel(char *p)
{
	int count=0;
	cout << "\nVowel in string=";
	while((*p)!='\0')
	{
		if((*p)=='a'||(*p)=='e'||(*p)=='i'||(*p)=='o'||(*p)=='u')
		{
			cout << "\n" << *p;
			count++;
		}
		p++;
	}
	return count;
}
int main()
{
	char str[30];
	int vcount;
	cout << "\nEnter the String=";
	gets(str);
	vcount=VowelCount::count_vowel(str);
	cout << "\nVowel Count=" << vcount;
	return(0);
}
