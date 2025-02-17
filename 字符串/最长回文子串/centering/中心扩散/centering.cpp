#include<iostream>
#include<cstring>
using namespace std;


//������ɢ�㷨
//ʱ�临�Ӷ�O(n^2)
//�ռ临�Ӷ�O(1)
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        //������ɢ
        int ans = 1;
        int leftpos = 0;
        for (int i = 0; i < n; ++i) {
            //�Դ��ַ�Ϊ������ɢ(��������)
            int left = i - 1, right = i + 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            if (right - left - 1 > ans) {
                leftpos = left + 1;
                ans = right - left - 1;
            }
            //�Դ��ַ��Լ��ұߵ��ַ�Ϊ������ɢ(ż������)
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