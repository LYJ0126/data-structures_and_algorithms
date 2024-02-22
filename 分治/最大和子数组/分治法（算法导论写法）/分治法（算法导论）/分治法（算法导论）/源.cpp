#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int a[1000],n;
struct node
{
	int low, high, sum;
};
node find_max_crossing_subarray(int A[], int low,int mid,int high)
{
	int leftsum = -INT_MAX;
	int sum = 0,maxleft=0,maxright=0;
	for (int i = mid; i >= low; i--) {//从中点向左寻找最大子数组
		sum += A[i];
		if (sum > leftsum) {
			leftsum = sum;
			maxleft = i;
		}
	}
	int rightsum = -INT_MAX;
	sum = 0;
	for (int j = mid + 1; j <= high; j++) {//从中点+1向右寻找最大子数组
		sum += A[j];
		if (sum > rightsum) {
			rightsum = sum;
			maxright = j;
		}
	}
	node res;
	res.low = maxleft, res.high = maxright, res.sum = leftsum + rightsum;
	return res;
}
node find_maximum_subarray(int A[], int low,int high)
{
	if (high == low) {//base case:only one element
		node res;
		res.low = low, res.high = high, res.sum = A[low];
		return res;
	}
	else {
		int mid = (low + high) / 2;
		node leftarr, rightarr, crossarr;
		leftarr = find_maximum_subarray(A, low, mid);
		rightarr = find_maximum_subarray(A, mid + 1, high);
		crossarr = find_max_crossing_subarray(A, low, mid, high);
		if (leftarr.sum >= rightarr.sum && leftarr.sum >= crossarr.sum) {
			return leftarr;
		}
		else if (rightarr.sum >= leftarr.sum && rightarr.sum >= crossarr.sum) {
			return rightarr;
		}
		else return crossarr;
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	node ans = find_maximum_subarray(a, 0, n-1);
	cout << "最大子数组的和为：" << ans.sum << "\n";
	cout << "最大子数组：";
	for (int i = ans.low; i <= ans.high; i++) cout << a[i] << ' ';
	return 0;
}