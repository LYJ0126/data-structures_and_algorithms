#include <iostream>
#include <cstring>
#include <vector>
using namespace std;


//动态规划做法
//时间复杂度O(n^2)
//空间复杂度O(n^2)
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n < 2) return s;//特判
        int maxlen = 1;
        int begin = 0;
        //dp[i][j] 表示 s[i, j]是否是回文串
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;//单个字母是回文串
        }
        for (int j = 1; j < n; ++j) {
            for (int i = 0; i < j; ++i) {
                if (s[i] != s[j]) dp[i][j] = false;//头尾不等，不是回文串
                else {
                    if (j - i < 3) dp[i][j] = true;//长度不超过3的字符串只用判断头尾是否相等
                    else dp[i][j] = dp[i + 1][j - 1];//回文串性质：去掉头尾还是回文串
                }
                if (dp[i][j] && j - i + 1 > maxlen) {
                    maxlen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxlen);
    }
};

int main() {
    Solution sol;
    string s = "babad";
    cout << sol.longestPalindrome(s) << endl;//bab
    return 0;
}