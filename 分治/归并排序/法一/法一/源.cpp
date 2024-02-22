#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define MAX 0x7fffffff;
int a[100];
void merge(int l, int mid, int r)//合并
{
	int b[100];
	int i = l, j = mid + 1, k = l;//i记录左半边最靠左的数位置，j记录右半边最靠左是数位置
	while (i <= mid && j <= r) {//左右比较合并
		if (a[i] <= a[j]) {
			b[k] = a[i];
			i++;
			k++;
		}
		else {
			b[k] = a[j];
			j++;
			k++;
		}
	}
	//对剩下的数合并，有一半边已经空了
	while (i <= mid) {
		b[k] = a[i];
		k++;
		i++;
	}
	while (j <= r) {
		b[k] = a[j];
		k++;
		j++;
	}
	//b数组赋值给a
	for (int t = l; t <= r; t++) {
		a[t] = b[t];
	}
}
void mergesort(int l, int r)//归并排序
{
	if (l < r) {
		int mid = (l + r) >> 1;//中间数
		mergesort(l, mid);
		mergesort(mid + 1, r);
		merge(l, mid, r);
	}
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	mergesort(1, n);
	for (int i = 1; i <= n; i++) cout << a[i] << ' ';
	return 0;
}