#include<iostream>
using namespace std;

const int N = 1010;
const int M = 10010;
int n, m;
int v[N], w[N];
int dp[N][M];
int main()
{
	//完全背包问题
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i] >> w[i];//v[i]表示第i个物品的体积，w[i]表示第i个物品的价值
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (j < v[i])
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				//注意是dp[i][j - v[i]] + w[i]，不是dp[i - 1][j - v[i]] + w[i],因为是完全背包问题，可以重复选取
				//这么写，因为dp[i][j-v[i]]+w[i]包含了原来三重循环中的dp[i-1][j-v[i]]+w[i]和dp[i-1][j-2*v[i]]+2*w[i]...dp[i-1][j-k*v[i]]+k*w[i]...的情况
				dp[i][j] = max(dp[i - 1][j], dp[i][j - v[i]] + w[i]);
			}
		}
	}
	cout << dp[n][m] << endl;
	return 0;
}