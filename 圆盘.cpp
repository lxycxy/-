#include <iostream>
//编译预处理命令
#include<iostream>
using namespace std;

//圆盘类circle的定义与实现
class circle
{
private:
	int num[20];
	int Max[4];
	int Min[4];
	int num_max;
	int num_min;

public:
	circle(int* num1);
	circle()
	{

	}
	void Input(int* num1);
	void Copy();
	void Prin();

};
circle::circle(int* num1)
{
	for (int i = 0; i < 20; i++)
	{
		num[i] = num1[i];
	}
}
void circle::Input(int* num1)
{
	for (int i = 0; i < 20; i++)
	{
		this->num[i] = num1[i];
	}
}
void circle::Copy()
{

	int a = 0, b = 1, c = 2, d = 3;
	num_min = num_max = 0;
	for (int i = 0; i < 4; i++)
	{
		Max[i] = num[i];
		num_max += num[i];
	}
	for (int i = 0; i < 4; i++)
	{
		Min[i] = num[i];
		num_min += num[i];
	}

	while (true)
	{

		if (num[a] + num[b] + num[c] + num[d] > num_max)
		{
			num_max = num[a] + num[b] + num[c] + num[d];

			Max[0] = num[a];
			Max[1] = num[b];
			Max[2] = num[c];
			Max[3] = num[d];
		}
		if (num[a] + num[b] + num[c] + num[d] < num_min)
		{
			num_min = num[a] + num[b] + num[c] + num[d];

			Min[0] = num[a];
			Min[1] = num[b];
			Min[2] = num[c];
			Min[3] = num[d];
			
		}
		a++; b++; c++; d++;

		if (d > 19)d %= 20;
		if (c > 19)c %= 20;
		if (b > 19)b %= 20;
		if (a > 19)break;

	}

}

void circle::Prin()
{
	for (int i = 0; i < 20; i++)
	{
		cout << num[i] << " ";
	}
	cout << endl;
	cout << "Max=" << num_max << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << Max[i] << " ";

	}
	cout << endl;
	cout << "Min=" << num_min << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << Min[i] << " ";

	}
	cout << endl;
};


int main(void)
{
	circle a;  //圆盘类的对象a
        int i,test[20];
        //输入数据test
	for(i=0;i<20;i++)
	{
	cin>>test[i];
	}
	a.Input(test);
	for(i=0;i<20;i++)
	{
	cin>>test[i];
	}
	circle b(test);  //圆盘类的对象b
        //测试圆盘a,b
	cout<<"圆盘a:"<<endl;
	a.Copy();
	a.Prin();
	cout<<"圆盘b:"<<endl;
	b.Copy();
	b.Prin();
}

