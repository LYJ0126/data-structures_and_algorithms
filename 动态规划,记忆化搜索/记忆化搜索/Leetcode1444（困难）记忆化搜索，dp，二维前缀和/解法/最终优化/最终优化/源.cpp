#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<functional>
using namespace std;

class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        const int MOD = 1e9 + 7;
        int m = pizza.size(), n = pizza[0].length();
        vector<vector<int>> sum(m + 1, vector<int>(n + 1)); // ��ά��׺��
        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                sum[i][j] = sum[i][j + 1] + sum[i + 1][j] - sum[i + 1][j + 1] + (pizza[i][j] & 1);
                if (sum[i][j]) f[i][j] = 1; // ��ʼֵ
            }
        }

        while (--k) {
            vector<int> col_s(n); // colS[j] ��ʾ f �� j �еĺ�׺��
            for (int i = m - 1; i >= 0; i--) {
                int row_s = 0; // f[i] �ĺ�׺��
                for (int j = n - 1; j >= 0; j--) {
                    int tmp = f[i][j];
                    if (sum[i][j] == sum[i][j + 1]) // ��߽�û��ƻ��
                        f[i][j] = f[i][j + 1];
                    else if (sum[i][j] == sum[i + 1][j]) // �ϱ߽�û��ƻ��
                        f[i][j] = f[i + 1][j];
                    else // ��߽��ϱ߽綼��ƻ������ô������ô�ж���ƻ��
                        f[i][j] = (row_s + col_s[j]) % MOD;
                    row_s = (row_s + tmp) % MOD;
                    col_s[j] = (col_s[j] + tmp) % MOD;
                }
            }
        }
        return f[0][0];
    }
};

int main()
{
	int row, k;
	cin >> row >> k;
	vector<string>pizza(row);
	for (int i = 0; i < row; i++) cin >> pizza[i];
    Solution sol;
    cout << sol.ways(pizza, k);
    return 0;
}