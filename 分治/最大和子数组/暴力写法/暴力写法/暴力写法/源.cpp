#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a[1000];
int main()
{
	int n,sum=-INT_MAX;
	int left = 0, right = 0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {//二重循环暴力搜索
		int cur_sum = 0;
		for (int j = i; j < n; j++) {
			cur_sum += a[j];
			if (cur_sum > sum) {//更新sum,left,right
				sum = cur_sum;
				right = j;
				left = i;
			}
		}
	}
	cout << "最大子数组和为：" << sum << "\n";
	cout << "最大子数组：";
	for (int i = left; i <= right; i++) cout << a[i] << ' ';
	return 0;
}