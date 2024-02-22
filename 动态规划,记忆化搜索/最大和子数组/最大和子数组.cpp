#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

int n, nums[10000], dp[10000];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> nums[i];
	dp[0] = nums[0];
	int ans = nums[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + nums[i], nums[i]);
		ans = max(ans, dp[i]);
	}
	cout << ans;
	return 0;
}