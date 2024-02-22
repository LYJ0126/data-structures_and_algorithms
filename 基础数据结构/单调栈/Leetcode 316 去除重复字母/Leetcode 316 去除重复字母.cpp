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
        for (int i = 0; i < len; i++) num[s[i] - 'a']++;//num��¼Ŀǰջ�ڼ�ջ��ÿ���ַ���ʣ����
        vector<int>book(26, 0);//book��¼����ջ������Щ�ַ�
        stack<char>st;//����ջ
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
                }//ջ����s[i]���ַ���Ϊ�˱�֤�����ԣ�����s[i]���ǵü�һ
                else {//ջ��û��s[i]����Ҫ��s[i]����
                    while (!st.empty() && st.top() > s[i] && num[st.top() - 'a'] > 1) {//��ջ��Ԫ�ش���s[i]�Һ��滹��������Ԫ��ʱ������ջ��Ԫ��
                        book[st.top() - 'a'] = 0;
                        num[st.top() - 'a']--;
                        st.pop();
                    }
                    //��s[i]����ջ
                    st.push(s[i]);
                    book[s[i] - 'a'] = 1;
                }
            }
            else num[s[i] - 'a']--;//�ǵ���������������һ
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