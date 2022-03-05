#include<iostream> 
using namespace std;
int main()
{
	int n,n1,m=0,m1=0;
	cin>>n>>n1;
	int t=n,t1=n1;
	while(t!=0)
	{
		m=m*10+t%10;
		t/=10;
	}
	while(t1!=0)
	{
		m1=m1*10+t1%10;
		t1/=10;
	}
	if(n*n1==m*m1)
		cout<<n<<"*"<<n1<<"="<<m<<"*"<<m1<<endl;
	else
		cout<<n<<"*"<<n1<<"!="<<m<<"*"<<m1<<endl;
}
