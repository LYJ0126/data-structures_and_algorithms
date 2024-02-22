#include<iostream>
#include<cmath>
using namespace std;

const int N = 1010;

int n, m;
int dp[N][N], v[N], w[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int k = 0; k * v[i] <= j; k++)//因为每一件物品都有无限件可用，我们只需要找出单件价值最高的商品就可以了
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * v[i]] + k * w[i]);
    cout << dp[n][m] << endl;
}
