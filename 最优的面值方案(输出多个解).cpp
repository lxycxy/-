#include<iostream>
#include<cmath>
#include<cstring>
using namespace std; 
int coin3[17] = {1,1,1,1,10,10,10,10,100,100,100,100,1000,1000,1000,1000,10000 };
int coin2[13] = {1,1,1,10,10,10,100,100,100,1000,1000,1000,10000};
int coin1[9] = {1,1,10,10,100,100,1000,1000,10000 };
////初始化硬币数组
void initarr(int N,int a)
{
	
		for (int i = 0; i < 9; i++)
		{
			if (i % 2 != 0)coin1[i] = a * pow(10, (i + 1) / 2 - 1);
			else if(i%2==0)coin1[i]= pow( 10, (i + 2) / 2 - 1);
		}
		
		
}
void initarr(int N, int a,int b)
{

	for (int i = 0; i < 13; i++)
	{
		if (i%3==1)coin2[i] = a * pow(10, (i + 2) / 3 - 1);
		else if(i%3==2)coin2[i] = b * pow(10, (i + 1) / 3 - 1);
		else if(i%3==0)coin2[i]= pow(10, (i + 3) / 3 - 1);
	}
	
}
void initarr(int N, int a, int b,int c)
{

	for (int i = 0; i < 17; i++)
	{
		if (i % 4 == 1)coin3[i] = a * pow(10, (i + 3) / 4 - 1);
		else if (i % 4 == 2)coin3[i] = b * pow(10, (i + 2) / 4 - 1);
		else if (i % 4 == 3)coin3[i] = c * pow(10, (i + 1) / 4 - 1);
		else if (i % 4 == 0) coin3[i] = pow(10, (i + 4) / 4 - 1);
	}

}
//处理平均找零硬币树
float cope1(int N)
{
	int ans = 0;
	float psum;
	for (int i = 1; i <= 10000; i++)
	{
		int t = i;
		while (t > 0)
		{
			for (int j = 8; j >= 0; j--)
			{
				if (t >= coin1[j])
				{
					ans += t / coin1[j];
					t %= coin1[j];
					break;
				}
			}
			
		}
	
	}
	psum = double(ans / 10000.0);
	return psum;
}
float cope2(int N)
{
	int ans = 0;
	float psum;
	for (int i = 1; i <= 10000; i++)
	{
		int t = i;
		while (t > 0)
		{
			for (int j = 12; j >= 0; j--)
			{
				if (t >= coin2[j])
				{
					ans += t / coin2[j];
					t %= coin2[j];
					break;
				}
			}
		}

	}
	psum = double(ans / 10000.0);
	return psum;
}
float cope3(int N)
{
	int ans = 0;
	float psum;
	for (int i = 1; i <= 10000; i++)
	{
		int t = i;
		while (t > 0)
		{
			for (int j = 16; j >= 0; j--)
			{
				if (t >= coin3[j])
				{
					ans += t / coin3[j];
					t %= coin3[j];
					break;
				}
			}
		}

	}
	psum = double(ans / 10000.0);
	return psum;
}
int main()
{
	int N;
	
	
	while (true)
	{
		cin >> N;
		if (N==0)break;
		if (N == 2)
		{
			int index[8]={0};
			int num = 0;
			float ans[8]={0};
			for (int i = 2; i <= 9; i++)//八种情况的平均硬币数
			{
				initarr(N, i);
				ans[i - 2] = cope1(i);
			}
			index[0] = 0;
			float min = ans[0];
			for (int i = 1; i < 8; i++)//找到最小值
			{
				if (min >= ans[i])
				{
					min = ans[i];
				}
			}
			for (int i = 0; i < 8; i++)//给最小值标记
			{
				if (ans[i] == min)
				{
					index[num] = i; num++;
				}
			}
			int b = 0;
			int r = 0;
			for (int i = 2; i <= 9; i++)//打印最小值组合
			{
				if (b == num)break;
				if (index[b] == r)
				{
					cout << 1 << " " << i << endl;
					b++;
				}
				r++;
			}
			
		}
		else if (N == 3)
		{
			int xb = 0;
			float ans[28] = { 0 };
			for (int i = 2; i <= 9; i++)
			{
				for (int j = i + 1; j <= 9; j++)
				{
					initarr(N, i, j);
					ans[xb++]=cope2(N);
				}
			}
			
			int index[28] = { 0 };
			float min = ans[0];
			int num = 0;
			for (int i = 1; i < 28; i++)
			{
				if (min >= ans[i])
				{
					min = ans[i];	
				}
			
			}
			for (int i = 0; i < 28; i++)
			{
				if (ans[i] == min)
				{
					index[num] = i; num++;
				}
			}
			int b = 0;
			int r = 0;
			for (int i = 2; i <= 9; i++)
			{
				for (int j = i + 1; j <= 9; j++)
				{
					if (b == num)break;
					if (index[b] == r)
					{
						cout << 1 << " " << i << " " << j << endl;
						b++;
					}
					r++;
				}
			}
		}
		else if (N == 4)
		{
			int xb = 0;
			float ans[56] = { 0 };
			for (int i = 2; i <= 9; i++)
			{
				for (int j = i + 1; j <= 9; j++)
				{
					for (int k = j + 1; k <= 9; k++)
					{
						initarr(N, i, j, k);
						ans[xb++]= cope3(N);
					}
				}
			}
			int index[56] = { 0 };
			float min = ans[0];
			int num = 0;
			for (int i = 1; i < 56; i++)
			{
				if (min >= ans[i])
				{
					min = ans[i];
				}
			}
			for (int i = 0; i < 56; i++)
			{
				if (ans[i] == min)
				{
					index[num] = i;
					num++;
				}
			}
			int b = 0;
			int r = 0;
			for (int i = 2; i <= 9; i++)
			{
				for (int j = i + 1; j <= 9; j++)
				{
					for (int k = j + 1; k <= 9; k++)
					{
						if (b == num)break;
						if (index[b] == r)
						{
							cout << 1 << " " << i << " " << j<<" "<<k << endl;
							b++;
						}
						r++;
					}
				}
			}

		}
		

	}
}