#include<iostream>
#include<cmath>
using namespace std;

//计算单个数的欧拉函数
//计算公式:φ(n)=n(1-1/p1)(1-1/p2)(1-1/p3)……(1-1/pn)
int euler_function(int n)
{
	int res = n;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)//n有素因子i
		{
			res = res / i * (i - 1);
			while(n % i == 0) n /= i;//出去所有素因子i
		}
	}
	if(n > 1) res = res / n * (n - 1);//最后剩下的n是素数
	return res;
}

int main()
{
	int n;
	cin >> n;
	cout << euler_function(n) << endl;
	return 0;
}