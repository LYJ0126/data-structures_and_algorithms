#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

class prefix_sum {
private:
	int* sum;
public:
	void init(int* array, int len)
	{
		sum = new int[len + 1];
		sum[0] = 0;
		for (int i = 1; i <= len; i++) {
			sum[i] = sum[i - 1] + array[i];
		}
	}
	int query(int left, int right) {
		return sum[right] - sum[left - 1];
	}
	~prefix_sum()
	{
		delete[] sum;
	}
};
int main()
{
	int n;
	cin >> n;
	int* a = new int[n+1];
	for (int i = 1; i <= n; i++) cin >> a[i];
	a[0] = 0;
	prefix_sum ss;
	ss.init(a, n);
	int ql, qr;
	cin >> ql >> qr;
	int ans = ss.query(ql, qr);
	cout << ans;
	delete[] a;
	return 0;
}