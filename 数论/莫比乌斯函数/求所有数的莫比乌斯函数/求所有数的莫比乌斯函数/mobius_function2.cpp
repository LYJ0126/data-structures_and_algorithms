#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

//求所有数的莫比乌斯函数
//线性筛每次都是用最小质因子去筛每一个数
//分为3类：
//1.如果i是质数，那么mu[i] = -1
//2.i已经包含了最小质因子p,那么mu[i*p] = 0
//3.i不包含最小质因子p,那么mu[i*p] = -mu[i]

const int maxn = 1000000;
int mu[maxn+1];//mu[i]表示i的莫比乌斯函数的值
int prime[maxn+1];//primes[i]表示第i个素数
bool vis[maxn+1];

void Mobius(int n)
{
	memset(vis,0,sizeof(vis));
	mu[1] = 1;//1的莫比乌斯函数为1
	int cnt = 0;
	for (int i = 2; i <= n; ++i) {
		if (!vis[i]) {//i是质数
			prime[++cnt] = i;
			mu[i] = -1;
		}
		for (int j = 1; j <= cnt && i * prime[j] <= n; ++j) {
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0) {
				mu[i * prime[j]] = 0;//i已经包含了最小质因子prime[j]
				break;
			}
			else mu[i * prime[j]] = -mu[i];//i不包含最小质因子prime[j]
		}
	}
}

int main()
{
	int n;
	cin >> n;
	Mobius(n);
	for (int i = 1; i <= n; ++i) cout << mu[i] << '\n';
	return 0;
}