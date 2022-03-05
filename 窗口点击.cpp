#include<iostream>
using namespace std;
struct window{
	int num;
	int ux;
	int uy;
	int dx;
	int dy;
};
struct click
{
	int x;
	int y;
};
void input(window *wd,int n)
{
	for(int i=0;i<n;i++)
	{
		cin>>wd[i].num>>wd[i].ux>>wd[i].uy>>wd[i].dx>>wd[i].dy;
	}
}
void input1(click *ck,int m)
{
	for(int i=0;i<m;i++)
	{
		cin>>ck[i].x>>ck[i].y;
	}
}
void copy1(window *wd,click *ck,int n,int m)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(ck[i].x<=wd[j].dx&&ck[i].x>=wd[j].ux&&ck[i].y>=wd[j].dy&&ck[i].y<=wd[j].uy)
			{
				window t = wd[j];
				for(int k=j;k>=0;k--)
				{
					wd[k]=wd[k-1];
				}
				wd[0] = t ;
				break;
			}
		}
	}
}
int main()
{
	window wd[10];
	click ck[1000];
	int n,m;
	cin>>n;
	input(wd,n);
	cin>>m;
	input1(ck,m);
	copy1(wd,ck, n,m);
	for(int i=0;i<n;i++)
	{
		cout<<wd[i].num<<" ";
	}
	
 } 
