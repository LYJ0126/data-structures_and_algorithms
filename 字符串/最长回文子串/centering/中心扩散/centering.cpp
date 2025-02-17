#include<iostream>
#include<cstring>
using namespace std;


//中心扩散算法
//时间复杂度O(n^2)
//空间复杂度O(1)
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        //中心扩散
        int ans = 1;
        int leftpos = 0;
        for (int i = 0; i < n; ++i) {
            //以此字符为中心扩散(奇数长度)
            int left = i - 1, right = i + 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            if (right - left - 1 > ans) {
                leftpos = left + 1;
                ans = right - left - 1;
            }
            //以此字符以及右边的字符为中心扩散(偶数长度)
            if (i < n - 1 && s[i] == s[i + 1]) {
                left = i - 1;
                right = i + 2;
                while (left >= 0 && right < n && s[left] == s[right]) {
                    left--;
                    right++;
                }
            }
            if (right - left - 1 > ans) {
                leftpos = left + 1;
                ans = right - left - 1;
            }
        }
        return s.substr(leftpos, ans);
    }
};

int main() {
    Solution sol;
    string s = "babad";
    cout << sol.longestPalindrome(s) << endl;//bab
    return 0;
}