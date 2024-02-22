#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
using namespace std;

int n, q, k;
int p[100000008], prime[100000000];
int main()
{
	scanf("%d%d", &n, &q);
	int t = 1;
	for (int i = 2; i <= n; i++) {
		if (p[i] == 0) {
			prime[t] = i;
			t++;
		}
		for (int j = 1; j < t && i * prime[j] <= n; j++) {
			p[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}

	}
	for (int i = 1; i <= q; i++)
	{
		scanf("%d", &k);
		if(k > t) printf("³¬³ö·¶Î§\n");
		else
		printf("%d\n", prime[k]);
	}
	return 0;
}