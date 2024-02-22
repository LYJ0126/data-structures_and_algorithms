#include<iostream>
#include "Solution.h"

int m, n;
int main()
{
	cin >> m >> n;
	vector<int>nums1(m), nums2(n);
	int x;
	for (int i = 0; i < m; i++) {
		cin >> x;
		nums1[i] = x;
	}
	for (int i = 0; i < n; i++) {
		cin >> x;
		nums2[i] = x;
	}
	Solution ss;
	cout << ss.findMedianSortedArrays(nums1, nums2);
	nums1.clear(), nums2.clear();
	system("pause");
	return 0;
}