#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cmath>
#include<stdio.h>
using namespace std;
int a[5000005], k;
//ע���Ǵ�0��ʼ�ģ�k��ָ�ĵڼ�СҲ�Ǵ�0��ʼ��
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
	//���ź����鱻����Ϊ���飺 l<=j<=i<=r
	if (k <= j) qsort(left, j);//��������ֻ��Ҫ��������
	else if (i <= k) qsort(i, right);//��������ֻ��Ҫ��������
	else //������м�����ֱ�����,i��j֮���������һ����
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