#include<iostream>
#include<cmath>
using namespace std;

int n, m;
int w[1005], v[1005];
int dp[10010];
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> w[i] >> v[i];
	for (int i = 1; i <= n; i++) {
		for (int j = w[i]; j <= m; j++) {
			//分为两种情况，装或者不装。
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	cout << dp[m] << endl;
	return 0;
}