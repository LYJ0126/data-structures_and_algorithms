#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;
const int N = 1e6 + 500;
int n, k, a[N], q[N], head = 1, tail;//headҪ+1 
int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        //����Сֵ 
        scanf("%d", &a[i]);
        while (head <= tail && q[head] <= i - k) head++;//��ͷ��Ȼ����������,�����ͷ���±����i-k,�����㲻����������,�Ӷ�ͷɾ�� 
        while (head <= tail && a[q[tail]] >= a[i]) tail--;//��ǰ���ƻ��˵�����,�Ӷ�βɾ��,ֱ��������С�ڵ�ǰ��
        q[++tail] = i;//��ǰԪ�ؽ��� 
        if (i >= k) printf("%d ", a[q[head]]);//���ÿ��������Сֵ 
    }
    printf("\n");
    head = 1, tail = 0;
    for (int i = 1; i <= n; i++)
    {    //�����ֵ 
        while (head <= tail && q[head] <= i - k) head++;
        while (head <= tail && a[q[tail]] <= a[i]) tail--;
        q[++tail] = i;//��ǰԪ�ؽ��� 
        if (i >= k) printf("%d ", a[q[head]]);
    }
    return 0;
}