#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

//求单个数的莫比乌斯函数值
int mobius(int x)
{
	int i;
	int num = 0;
	if(x == 1) return 1;//μ(1)=1
	for (i = 2; i <= sqrt(x); i++)
	{
		if (x % i == 0) {//有质因子i
			x /= i;
			num++;//质因子种类数加1
			if (x % i == 0) return 0;//x有平方因子
		}
	}
	if(x > 1) num++;//最后剩下的x是质数,质因子种类数加1
	//(-1)^num
	if(num % 2 == 0) return 1;
	else return -1;
}

int main()
{
	int n;
	cin >> n;
	cout << mobius(n) << endl;
	return 0;
}