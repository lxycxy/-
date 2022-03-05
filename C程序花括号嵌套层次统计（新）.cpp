#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	fstream of;
	of.open("input.c");
	char str[100];
	int num=0;
	string str1;
	while(getline(of,str1))
	{
		for(int i=0;i<str1.length();i++)
		{
			if(str1[i]=='/')break;
			else if(str1[i]=='{'||str1[i]=='}')str[num++]=str1[i];
		}
	}
	int num1=0;
	int i=0,max=0;
	for(int i=0;i<num;i++)
	{
		if(num1>max)max=num1;
		if(str[i]=='}'&&str[i+1]=='{'&&i!=num-1)num1--;
		else if(str[i]=='{')num1++;
		
	}
	
	cout<<num1<<endl;
	cout<<str<<endl;
 } 
