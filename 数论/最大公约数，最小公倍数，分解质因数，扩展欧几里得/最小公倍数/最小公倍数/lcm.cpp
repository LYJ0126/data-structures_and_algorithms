#include<iostream>
#include<cmath>
using namespace std;

int lcm1(int x, int y)//求法1
{
	int maximum = x > y ? x : y;
	int minimum = x < y ? x : y;
	for (int i = maximum; i <= x * y; i += maximum)
	{
		if (i % minimum == 0)
		{
			return i;
		}
	}
	return x * y;
}
int lcm2(int x, int y)//求法2,先用辗转相除法求最大公约数
{
	//求最大公约数
	long long mul = (long long)x * (long long)y;
	while (x != 0) {
		int temp = x;
		x = y % x;
		y = temp;
	}
	//返回xy/gcd(x,y)
	return mul / y;
}
int main()
{
	int x, y;
	cin >> x >> y;
	cout << lcm1(x, y) << endl;
	cout << lcm2(x, y) << endl;
	return 0;
}