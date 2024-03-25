#include<iostream>
#include<cmath>
using namespace std;

//利用欧拉定理a^phi(n) ≡ 1 (mod n) (a与n互质)
//求phi(n)的值,利用公式phi(n) = n * (1 - 1/p1) * (1 - 1/p2) * ... * (1 - 1/pk)
int phi(int n)
{
	int res = n;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0) {//i是n的质因子
			res = res / i * (i - 1);
			while (n % i == 0) n /= i;//去掉n的质因子i
		}
	}
	if (n > 1) res = res / n * (n - 1);//最后剩下的n是大于sqrt(n)的质因子
	return res;
}
//快速幂
int qpow(int a, int b, int mod)
{
	int res = 1;
	while (b){
		if (b & 1) res = (long long)res * a % mod;
		a = (long long)a * a % mod;
		b >>= 1;
	}
	return res;
}

int main()
{
	int a, p;
	cin >> a >> p;
	cout << qpow(a, phi(p) - 1, p) << endl;
	return 0;
}