#include<iostream>
#include<cmath>
using namespace std;
int arr[16]={0};
void move()
{
	int t=arr[15];
	for(int i=14;i>=0;i--)
	{
		arr[i+1]=arr[i];
	}
	arr[0]=t;
	
}
int main()
{

	int n,m;
	cin>>n>>m;
	int i=15;
	while(n!=0)
	{
		arr[i]=n%2;
		n/=2;
		i--;
	}
	for(int i=0;i<m;i++)
	{
		move();
	}
	for(int i=0;i<16;i++)
	{
		n+=arr[i]*pow(2,15-i);
	}
	cout<<n<<endl;
 } 
