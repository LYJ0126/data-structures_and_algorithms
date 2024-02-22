#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;
const int N = 1e6 + 500;
int n, k, a[N], q[N], head = 1, tail;//head要+1 
int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        //求最小值 
        scanf("%d", &a[i]);
        while (head <= tail && q[head] <= i - k) head++;//队头显然是最早进入的,如果队头的下标大于i-k,该数便不在区间内了,从队头删除 
        while (head <= tail && a[q[tail]] >= a[i]) tail--;//当前数破坏了单调性,从队尾删除,直至队中数小于当前数
        q[++tail] = i;//当前元素进队 
        if (i >= k) printf("%d ", a[q[head]]);//输出每个区间最小值 
    }
    printf("\n");
    head = 1, tail = 0;
    for (int i = 1; i <= n; i++)
    {    //求最大值 
        while (head <= tail && q[head] <= i - k) head++;
        while (head <= tail && a[q[tail]] <= a[i]) tail--;
        q[++tail] = i;//当前元素进队 
        if (i >= k) printf("%d ", a[q[head]]);
    }
    return 0;
}