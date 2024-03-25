#include<iostream>
#include<cmath>
using namespace std;

void Decomposition_prime_factor(int n)
{
	bool first = true;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)//i是n的质因子
		{
			int s=0;//s是i的指数
			while (n % i == 0)
			{
				n /= i;
				s++;
			}
			if(first) first = false;//如果是第一个质因子，不输出乘号
			else cout<<"*";//输出乘号
			if(s==1) cout<<i;//输出i^1
			else cout<<i<<"^"<<s;//输出i^s
		}
	}
	if (n > 1)//如果n最后剩余是质数
	{
		if(first) first = false;//如果是第一个质因子，不输出乘号
		else cout<<"*";//输出乘号
		cout<<n;//输出n^1
	}
}
int main()
{
	int n;
	cin>>n;
	Decomposition_prime_factor(n);
	return 0;
}