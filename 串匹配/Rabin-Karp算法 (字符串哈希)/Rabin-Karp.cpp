#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

typedef long long ll;
class Solution
{
private:
	ll fastpower(ll base, ll power, ll q)
	{
		ll ans = 1;
		while (power) {
			if (power & 1) {
				ans = (ans * base) % q;
			}
			power >>= 1;
			base = (base * base) % q;
		}
		return ans;
	}
public:
	string p, t;//p为待匹配的模板，t为原文
	void Rabin_Karp_Matcher(string T, string P,int d,int q)//"d" is the radix and "q" is the number which will be the mod
	{
		int n = t.length();
		int m = p.length();
		/*
			每次向右移一位，T对应长度为m的串的哈希值t[s+1]=(d*(t[s]-T[s+1]*h)+T[s+m+1])
		*/
		ll h1 = fastpower((ll)d, (ll)(m - 1), (ll)q);
		int h = h1;
		int pattern = 0, temp = 0;//预处理计算p和t0
		for (int i = 0; i < m; i++) {
			pattern = (d * pattern + (int)P[i]) % q;
			temp = (d * temp + (int)T[i]) % q;
		}
		for (int s = 0; s <= n - m; s++) {
			if (pattern == temp) {//哈希成功，还要检查两字符串是否相等
				bool flag = true;
				for (int j = 0; j < m; j++) {
					if (P[j] != T[s + j]) {
						flag = false;
						break;
					}
				}
				if (flag) {
					cout << "Patter occurs with shift " << s << endl;
				}
			}
			else {
				int jianqu = (h * (int)T[s]) % q;
				//计算下一个偏移量下原文中长度为m的字符串的哈希值
				if (temp > jianqu) {
					temp = (d * (temp - jianqu) + (int)T[s + m]) % q;
				}
				else {
					temp = (d * (temp + q - jianqu) + (int)T[s + m]) % q;
				}
			}
		}
	}
};
int main()
{
	Solution ss;
	cin >> ss.t >> ss.p;
	ss.Rabin_Karp_Matcher(ss.t, ss.p, 96, 5999677);//ascll码前32个无符号显示，此处选取一个7位质数
	return 0;
}

/*
测试样例：
2359023141526739921
31415
*/