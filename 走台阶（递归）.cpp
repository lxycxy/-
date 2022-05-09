#include<iostream>
using namespace std;
int find(int n)
{
	if(n==1)return 1;
	if(n==2)return 2;
	if(n==3)return 3;
	if(n>3)
	{
		return find(n-1)+find(n-2);
	}
}
int main()
{
	int n;
	cin>>n;
	cout<<find(n)<<endl;
	return 0;
 } 
