#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int findmax(int a[], int n)
{
	int maximum = -10000000;
	for (int i = 1; i <= n; i++) {
		maximum = max(maximum, a[i]);
	}
	return maximum;
}
int findmin(int a[], int n)
{
	int minimum = 0x7fffffff;
	for (int i = 1; i <= n; i++) {
		minimum = min(minimum, a[i]);
	}
	return minimum;
}
int main()
{
	int n, a[1000];
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cout << findmin(a, n) << ' ' << findmax(a, n);
	return 0;
}