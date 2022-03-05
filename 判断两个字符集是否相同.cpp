#include<iostream>
using namespace std;
int main()
{
	int arr[256]={0},arr1[256]={0};
	char str[20],str1[20];
	cin>>str>>str1;
	for(int i=0;i<20;i++)
	{
		if(str[i]=='/0')break;
		arr[str[i]]++;
	}
	for(int i=0;i<20;i++)
	{
		if(str1[i]=='/0')break;
		arr1[str1[i]]++;
	}
	int flag=1;
	for(int i=0;i<256;i++)
	{
		if(arr[i]!=arr1[i])
		{
			flag=0;
		}
		
	}
	cout<<flag<<endl;
	
	for(int i=0;i<256;i++)
	{
		if(arr[i]!=0)
		{
			cout<<char(i)<<" "<<arr[i]<<endl;
		}
		
	}
 } 


