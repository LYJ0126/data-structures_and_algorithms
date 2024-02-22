#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cmath>
#include<stdio.h>
using namespace std;
int a[5000005], k;
//注意是从0开始的，k所指的第几小也是从0开始的
void qsort(int left, int right)
{
	int i = left, j = right, mid = a[(left + right) / 2];
	do
	{
		while (a[j] > mid)
			j--;
		while (a[i] < mid)
			i++;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	} while (i <= j);
	//快排后数组被划分为三块： l<=j<=i<=r
	if (k <= j) qsort(left, j);//在左区间只需要搜左区间
	else if (i <= k) qsort(i, right);//在右区间只需要搜右区间
	else //如果在中间区间直接输出,i和j之间最多间隔有一个数
	{
		printf("%d", a[j + 1]);
		exit(0);
	}
}
int main()
{
	int n;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	qsort(0, n - 1);
}