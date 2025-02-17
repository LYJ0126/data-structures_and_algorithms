#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

//暴力算法的时间复杂度为O(mn)
class Solution
{
public:
	string t, p;//t是原文，p是匹配模板
	void naive_string_matcher(string T, string P)
	{
		int n = T.length();
		int m = P.length();
		for (int i = 0; i <= n - m; i++) {//枚举偏移量
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