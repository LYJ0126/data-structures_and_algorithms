#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<cstdlib>
#include<stack>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>num(26, 0);
        int len = s.length();
        for (int i = 0; i < len; i++) num[s[i] - 'a']++;//num记录目前栈内及栈后每种字符还剩多少
        vector<int>book(26, 0);//book记录单调栈内有哪些字符
        stack<char>st;//单调栈
        st.push(s[0]);
        book[s[0] - 'a'] = 1;
        for (int i = 1; i < len; i++) {
            if (s[i] > st.top() && book[s[i] - 'a'] == 0) {
                st.push(s[i]);
                book[s[i] - 'a'] = 1;
            }
            else if (s[i] < st.top()) {
                if (book[s[i] - 'a'] == 1) {
                    num[s[i] - 'a']--;
                }//栈内有s[i]的字符，为了保证单调性，跳过s[i]，记得减一
                else {//栈内没有s[i]，则要将s[i]放入
                    while (!st.empty() && st.top() > s[i] && num[st.top() - 'a'] > 1) {//当栈顶元素大于s[i]且后面还会出现这个元素时，弹出栈顶元素
                        book[st.top() - 'a'] = 0;
                        num[st.top() - 'a']--;
                        st.pop();
                    }
                    //将s[i]放入栈
                    st.push(s[i]);
                    book[s[i] - 'a'] = 1;
                }
            }
            else num[s[i] - 'a']--;//记得跳过的其数量减一
        }
        int anslen = st.size();
        vector<char>ansrev(anslen);
        for (int i = 0; i < anslen; i++) {
            ansrev[i] = st.top();
            st.pop();
        }
        string ans = "";
        for (int i = anslen - 1; i >= 0; i--) {
            ans += ansrev[i];
        }
        return ans;
    }
};
int main()
{
    Solution ss;
    string sample;
    cin >> sample;
    cout << ss.removeDuplicateLetters(sample);
    return 0;
}