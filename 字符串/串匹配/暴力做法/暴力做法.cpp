#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

//�����㷨��ʱ�临�Ӷ�ΪO(mn)
class Solution
{
public:
	string t, p;//t��ԭ�ģ�p��ƥ��ģ��
	void naive_string_matcher(string T, string P)
	{
		int n = T.length();
		int m = P.length();
		for (int i = 0; i <= n - m; i++) {//ö��ƫ����
			bool flag = true;
			for (int j = 0; j < m; j++) {
				if (P[j] != T[i + j]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				cout << "Patter occurs with shift " << i << endl;
			}
		}
	}
};
int main()
{
	Solution ss;
	cin >> ss.t >> ss.p;
	ss.naive_string_matcher(ss.t, ss.p);
	return 0;
}