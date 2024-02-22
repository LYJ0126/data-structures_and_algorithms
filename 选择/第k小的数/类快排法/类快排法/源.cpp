//ע�����������scanf��printf
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
//���ƿ���˼�룬����ÿ�������ȷ���˻�׼����λ�ã��ٽ���Ҫ��λ��������֮�Ƚϣ���ֻ�԰���k+1(�ڴ������1��ʼ)λ�õ���һ�ν�������
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