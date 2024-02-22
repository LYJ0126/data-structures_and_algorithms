#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
	int n, a[10000];
	int minimum, maximum;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n & 1) {
		minimum = maximum = a[1];
		for (int i = 2; i < n; i += 2) {
			int lower = min(a[i], a[i + 1]);
			int upper = max(a[i], a[i + 1]);
			minimum = min(minimum, lower);
			maximum = max(maximum, upper);
		}
	}
	else {
		minimum = min(a[1], a[2]);
		maximum = max(a[1], a[2]);
		for (int i = 3; i < n; i += 2) {
			int lower = min(a[i], a[i + 1]);
			int upper = max(a[i], a[i + 1]);
			minimum = min(minimum, lower);
			maximum = max(maximum, upper);
		}
	}
	cout << minimum << ' ' << maximum;
	return 0;
}