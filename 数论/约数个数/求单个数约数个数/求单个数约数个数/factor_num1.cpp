#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

//��һ������Լ������
//ʱ�临�Ӷ�O(sqrt(n))
//��ʽ��n = p1^a1 * p2^a2 * ... * pk^ak, Լ������Ϊ(a1+1)*(a2+1)*...*(ak+1)
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
	if (n > 1) res *= 2;//�����ʣ�µ�n��һ������sqrt(n)����������ô��Ҫ�ٳ��ԣ�1+1��= 2
	return res;
}

int main()
{
	int n;
	cin >> n;
	cout << factor_num(n) << endl;
	return 0;
}