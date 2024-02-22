//注意输入输出用scanf和printf
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<stdio.h>
#include<cstdlib>
using namespace std;
int n, k;
int a[5000040];
//类似快排思想，快排每次排完后确定了基准数的位置，再将所要的位置序数与之比较，再只对包含k+1(在此数组从1开始)位置的那一段进行排列
void find(int left, int right)
{
	if (left >= right) return;
	int i = left, j = right;
	while (i < j)
	{
		while (a[j] >= a[left] && i < j) j--;
		while (a[i] <= a[left] && i < j) i++;
		if (i < j) {
			swap(a[i], a[j]);
		}
	}
	swap(a[left], a[i]);
	if (i == k) return;
	else if (i > k) find(left, i - 1);
	else find(i + 1, right);
	return;
}
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	find(1, n);
	printf("%d", a[k]);
	return 0;
}