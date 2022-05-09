#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n,i=0,j=0,si=0,sj=0,ini,inj;
	cin>>n>>ini>>inj;
	int count=0;
	int k=1;
	ini--;inj--;
	if(n==1)
	{
		cout<<1<<endl;
		return 0;
	}
	while(k<n*n)
	{
		for(;j<n-si/2-1;j++,k++)if(ini==i&&inj==j)cout<<k;
		sj++;
		for(;i<n-sj/2-1;i++,k++)if(ini==i&&inj==j)cout<<k;
		si++;
		for(;j>si/2;j--,k++)if(ini==i&&inj==j)cout<<k;
		sj++;
		for(;i>sj/2;i--,k++)if(ini==i&&inj==j)cout<<k;
		si++;
	}
		if(ini==i&&inj==j)cout<<k;
		
	

}

