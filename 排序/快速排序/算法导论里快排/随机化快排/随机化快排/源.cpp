#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<ctime>
#include<stdlib.h>
using namespace std;

int  random_partition(int a[], int p, int r)
{
	//产生随机数，并将其作为基准数
	int t = (rand() % (r - p + 1) + p);
	cout << t << "\n";
	swap(a[t], a[r]);
	//下面和原来的partition一样
	int i = p-1, x = a[r];
	for (int j = p; j < r; j++) {
		if (a[j] <= x) {
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[r]);
	return i + 1;
}
void random_quicksort(int a[], int p, int r)
{
	if (p < r) {
		int q = random_partition(a, p, r);
		random_quicksort(a, p, q - 1);
		random_quicksort(a, q + 1, r);
	}
}
int main()
{
	int n, A[100];
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	srand((unsigned)time(NULL));
	random_quicksort(A, 1, n);
	for (int i = 1; i <= n; i++) cout << A[i] << ' ';
	return 0;
}