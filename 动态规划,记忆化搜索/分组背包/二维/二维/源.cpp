#include<iostream>
#include<cmath>
using namespace std;

const int N = 110;
int f[N][N];  //只从前i组物品中选，当前体积小于等于j的最大值
int v[N][N], w[N][N], s[N];   //v为体积，w为价值，s代表第i组物品的个数
int n, m, k;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        for (int j = 0; j < s[i]; j++) {
            cin >> v[i][j] >> w[i][j];  //读入
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            f[i][j] = f[i - 1][j];  //不选 不选表示不选第 i 组物品的所有物品，只从前 i?1 组物品里面选
            for (int k = 0; k < s[i]; k++) {
                if (j >= v[i][k])     f[i][j] = max(f[i][j], f[i - 1][j - v[i][k]] + w[i][k]);
            }
        }
    }
    cout << f[n][m] << endl;
}
