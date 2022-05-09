#include<iostream>

using namespace std;


int main()
{
	int a,b,N;
	int coin[13]={1,2,5,10,20,50,100,200,500,1000,2000,5000,10000};
	int ans;
	float psum;
	while(true)
	{
		cin>>a>>b;
		if(a==0&&b==0)break;
		ans=0;
		for(int N=a;N<b;N++)
		{
		
			while(N>0)
			{
				for(int i=12;i>=0;i--)
				{
					if(N>=coin[i]){
					ans+=N/coin[i];
					N%=coin[i];
					break;
					} 
				}
			}
			
		}
		cout<<ans<<endl;
		// psum=float(ans/(b-a+1));
		
	}
 } 
