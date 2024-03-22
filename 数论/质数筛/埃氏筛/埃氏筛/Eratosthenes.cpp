#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

// 埃氏筛法
int primes[1000000];
bool isPrime[100000005];

int Eratosthenes(int n) {// 返回小于等于n的素数个数
	int p = 0;
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) {
			primes[p++] = i;
			if (1ll * i * i <= n) {
				for (int j = i + i; j <= n; j += i) {
					isPrime[j] = false;
				}
			}
		}
	}
	return p;
}

int main() {
	int n;
	cin >> n;
	cout << Eratosthenes(n) << endl;
	return 0;
}