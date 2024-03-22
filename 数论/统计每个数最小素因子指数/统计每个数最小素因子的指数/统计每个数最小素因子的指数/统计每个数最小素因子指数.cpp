#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

//统计每个数最小素因子的指数
const int N = 1000000;
int primes[N], cnt[N], num = 0;
bool visited[N];

void get_exponent(int n)
{
	memset(visited, 0, sizeof(visited));
	for (int i = 2; i <= n; ++i) {
		if (!visited[i]) {//i是素数
			cnt[i] = 1;
			primes[num++] = i;
		}
		for (int j = 0; j < num && 1ll * i * primes[j] <= n; ++j) {
			visited[i * primes[j]] = true;//合数标记
			if (i % primes[j] == 0) {//i*primes[j]的最小素因子是primes[j]，指数不为1
				cnt[i * primes[j]] = cnt[i] + 1;
				break;
			}
			else cnt[i * primes[j]] = 1;//i*primes[j]的最小素因子是primes[j]，指数为1
		}
	}
}

int main()
{
	int n;
	cin >> n;
	get_exponent(n);
	for (int i = 2; i <= n; ++i) {//输出每个数的最小素因子的指数
		cout << cnt[i] << ' ';
	}
	return 0;
}