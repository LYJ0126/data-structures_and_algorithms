#include <iostream>
#include <cstring>
#include <vector>
using namespace std;


//��̬�滮����
//ʱ�临�Ӷ�O(n^2)
//�ռ临�Ӷ�O(n^2)
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n < 2) return s;//����
        int maxlen = 1;
        int begin = 0;
        //dp[i][j] ��ʾ s[i, j]�Ƿ��ǻ��Ĵ�
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;//������ĸ�ǻ��Ĵ�
        }
        for (int j = 1; j < n; ++j) {
            for (int i = 0; i < j; ++i) {
                if (s[i] != s[j]) dp[i][j] = false;//ͷβ���ȣ����ǻ��Ĵ�
                else {
                    if (j - i < 3) dp[i][j] = true;//���Ȳ�����3���ַ���ֻ���ж�ͷβ�Ƿ����
                    else dp[i][j] = dp[i + 1][j - 1];//���Ĵ����ʣ�ȥ��ͷβ���ǻ��Ĵ�
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