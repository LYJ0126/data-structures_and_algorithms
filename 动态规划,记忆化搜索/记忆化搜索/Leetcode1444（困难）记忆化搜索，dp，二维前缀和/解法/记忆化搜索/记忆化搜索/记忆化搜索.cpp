#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<functional>
using namespace std;

class matrixsum {
private:
    vector<vector<int>>sum;
public:
    matrixsum(vector<string>& matrix) {
        int m = matrix.size(), n = matrix[0].length();
        sum = vector<vector<int>>(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int tt = 0;
                if (matrix[i][j] == 'A') tt = 1;
                sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + tt;
            }
        }
    }
    int query(int r1, int c1, int r2, int c2) {
        return sum[r2][c2] - sum[r2][c1] - sum[r1][c2] + sum[r1][c1];//左闭右开
    }
};
class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        const int mod = 1e9 + 7;
        matrixsum ss(pizza);
        const int m = pizza.size(), n = pizza[0].length();
        //vector<vector<vector<int>>>book(k, vector<vector<int>>(m, vector<int>(n)));
        /*int*** book = new int** [k];
        for (int i = 0; i < k; i++) {
            book[i] = new int* [m];
            for (int j = 0; j < m; j++) {
                book[i][j] = new int[n];
            }
        }*/
        int book[12][52][52];
        memset(book, -1, sizeof(book));
        /*for (int i = 0; i < k; i++) {
            for (int j = 0; j < m; j++) {
                for (int t = 0; t < n; t++) {
                    book[i][j][t] = -1;
                }
            }
        }*/
        function<int(int, int, int)>cut = [&](int times, int i, int j)->int {
            if (times == 0) return ss.query(i, j, m, n) ? 1 : 0;
            if (book[times][i][j] != -1) return book[times][i][j];
            int& res = book[times][i][j];//引用，后面会修改book[times][i][j]
            res = 0;
            for (int verticalcut = j + 1; verticalcut < n; verticalcut++) {
                if (ss.query(i, j, m, verticalcut)) res = (res + cut(times - 1, i, verticalcut)) % mod;
            }
            for (int levelcut = i + 1; levelcut < m; levelcut++) {
                if (ss.query(i, j, levelcut, n)) res = (res + cut(times - 1, levelcut, j)) % mod;
            }
            return res;
        };
        return cut(k - 1, 0, 0);
    }
};
int main()
{
    int row, k;
    cin >> row >> k;
    vector<string>pizza(row);
    for (int i = 0; i < row; i++) {
        cin >> pizza[i];
    }
    Solution sol;
    cout << sol.ways(pizza, k);
    return 0;
}