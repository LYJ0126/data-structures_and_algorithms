#include<iostream>
#include<cmath>
using namespace std;

//����ŷ������a^phi(n) �� 1 (mod n) (a��n����)
//��phi(n)��ֵ,���ù�ʽphi(n) = n * (1 - 1/p1) * (1 - 1/p2) * ... * (1 - 1/pk)
int phi(int n)
{
	int res = n;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0) {//i��n��������
			res = res / i * (i - 1);
			while (n % i == 0) n /= i;//ȥ��n��������i
		}
	}
	if (n > 1) res = res / n * (n - 1);//���ʣ�µ�n�Ǵ���sqrt(n)��������
	return res;
}
//������
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