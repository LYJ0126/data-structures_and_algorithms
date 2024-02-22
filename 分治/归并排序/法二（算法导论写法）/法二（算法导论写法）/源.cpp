#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define MAX 0x7fffffff;
int a[100];
void merge(int l, int mid, int r)//合并
{
	int L[100], R[100];
	for (int i = 1; i <= mid - l + 1; i++) L[i] = a[l + i - 1];
	for (int i = 1; i <= r - mid; i++) R[i] = a[mid + i];
	//开两个新数组来存储两半边
	L[mid - l + 2] = MAX;
	R[r - mid + 1] = MAX;
	int i = 1, j = 1;
	for (int k = l; k <= r; k++) {
		if (L[i] <= R[j]) {
			a[k] = L[i];
			i++;
		}
		else {
			a[k] = R[j];
			j++;
		}
	}
}
void mergesort(int l, int r)//合并排序
{
	if (l < r) {
		int mid = (l + r) >> 1;
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