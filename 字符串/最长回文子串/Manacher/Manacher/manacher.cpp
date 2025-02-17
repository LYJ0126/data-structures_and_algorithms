#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        // Manacher ģ��
        // �� s ����Ϊ t�������Ͳ���Ҫ���� s.length() ����ż�ԣ���Ϊ�´� t
        // ��ÿ�������Ӵ���������Ĵ������л������ģ� s �� t ���±�ת����ϵ��
        // (si+1)*2 = ti
        // ti/2-1 = si
        // ti Ϊż������Ӧ����Ĵ����� 2 ��ʼ��
        // ti Ϊ��������Ӧż���Ĵ����� 3 ��ʼ��
        string t = "^";
        for (char c : s) {
            t += '#';
            t += c;
        }
        t += "#$";

        // ����һ������Ĵ��Ļ��İ뾶=(����+1)/2���������������ģ�ȥ��һ����ʣ���ַ����ĳ���
        // half_len[i] ��ʾ�� t �ϵ��� t[i] Ϊ�������ĵ�������Ӵ��Ļ��İ뾶
        // �� [i-half_len[i]+1,i+half_len[i]-1] �� t �ϵ�һ�������Ӵ�
        vector<int> half_len(t.length() - 2);
        half_len[1] = 1;
        // box_r ��ʾ��ǰ�ұ߽��±����Ļ����Ӵ����ұ߽��±�+1
        // box_m Ϊ�û����Ӵ�������λ�ã����ߵĹ�ϵΪ r=mid+half_len[mid]
        int box_m = 0, box_r = 0, max_i = 0;
        for (int i = 2; i < half_len.size(); i++) {
            int hl = 1;
            if (i < box_r) {
                // �� i ���� box_m �ĶԳ�λ�� i'=box_m*2-i
                // ���� i' Ϊ���ĵ�������Ӵ���Χ�������� box_m
                // Ϊ���ĵĻ��Ĵ��ķ�Χ���� i+half_len[i'] >= box_r�� ��
                // half_len[i] Ӧ�ȳ�ʼ��Ϊ��֪�Ļ��İ뾶
                // box_r-i��Ȼ���ټ�������ƥ�� ���� half_len[i] �� half_len[i']
                // ���
                hl = min(half_len[box_m * 2 - i], box_r - i);
            }

            // ������չ
            // �㷨�ĸ��Ӷ�ȡ�����ⲿ��ִ�еĴ���
            // ������չ֮�� box_r ��Ȼ����£����ƣ�������չ�ĵĴ������� box_r
            // ���ƵĴ��� ����㷨�ĸ��Ӷ� = O(t.length()) = O(n)
            while (t[i - hl] == t[i + hl]) {
                hl++;
                box_m = i;
                box_r = i + hl;
            }

            half_len[i] = hl;
            if (hl > half_len[max_i]) {
                max_i = i;
            }
        }

        int hl = half_len[max_i];
        // ע�� t �ϵ�������Ӵ�������ߺ����ұ߶��� '#'
        // ����Ҫ��Ӧ�� s��������Ӵ����±��Ǵ� max_i-hl+2 �� max_i+hl-2
        // ������ĵ��±�ת����ϵ���õ����� s �ϵ��±귶Χ�Ǵ� (max_i-hl)/2 ��
        // (max_i+hl)/2-2
        return s.substr((max_i - hl) / 2, hl - 1);
    }
};

int main() {
    Solution s;
    string str = "aacabdkacaa";
    cout << s.longestPalindrome(str) << endl; // "aca"
    return 0;
}