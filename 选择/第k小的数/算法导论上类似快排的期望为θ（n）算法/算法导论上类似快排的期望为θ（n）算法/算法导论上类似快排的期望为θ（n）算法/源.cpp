#include<iostream>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<cstdlib>
using namespace std;

int randomized_partition(int a[], int p, int r)
{
	int t = (rand() % (r - p + 1) + p);
	swap(a[r], a[t]);
	int i = p - 1;
	int x = a[r];
	for (int j = p; j < r; j++) {
		if (a[j] <= x) {
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[r]);
	return i + 1;
}
int randomized_select(int a[], int p, int r, int k)
{
	if (p == r) return a[p];
	int q = randomized_partition(a, p, r);
	int t = q - p + 1;
	if (t == k) return a[q];
	else if (k < t) {
		return randomized_select(a, p, q - 1, k);
	}
	else return randomized_select(a, q + 1, r, k - t);
}
int main()
{
	srand((unsigned)time(NULL));
	int k, n, a[10000];
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cout << randomized_select(a, 1, n, k);
	return 0;
}