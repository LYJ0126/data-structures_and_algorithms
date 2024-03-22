#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

//求一个数的约数个数
//时间复杂度O(sqrt(n))
//公式：n = p1^a1 * p2^a2 * ... * pk^ak, 约数个数为(a1+1)*(a2+1)*...*(ak+1)
int factor_num(int n)
{
	int res = 1;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			int cnt = 0;
			while (n % i == 0) {
				n /= i;
				++cnt;
			}
			res *= (cnt + 1);
		}
	}
	if (n > 1) res *= 2;//当最后剩下的n是一个大于sqrt(n)的质数，那么需要再乘以（1+1）= 2
	return res;
}

int main()
{
	int n;
	cin >> n;
	cout << factor_num(n) << endl;
	return 0;
}