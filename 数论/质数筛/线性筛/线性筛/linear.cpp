#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

//线性筛
const int N = 1000000;
int primes[N];
bool is_prime[N];
int linear(int n)
{
	int cnt = 0;
	memset(is_prime, true, sizeof(is_prime));
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= n; i++)
	{
		if (is_prime[i]) primes[cnt++] = i;
		for (int j = 0; j < cnt && 1ll * i * primes[j] <= n; j++)
		{
			is_prime[i * primes[j]] = false;
			if (i % primes[j] == 0) break;//保证每个合数只被它的最小质因子筛掉
		}
	}
	return cnt;
}

int main()
{
	int n;
	cin >> n;
	int cnt = linear(n);
	cout << cnt << endl;
	for (int i = 0; i < cnt; i++) cout << primes[i] << " ";
	return 0;
}