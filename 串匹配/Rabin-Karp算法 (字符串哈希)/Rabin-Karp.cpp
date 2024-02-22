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
	string p, t;//pΪ��ƥ���ģ�壬tΪԭ��
	void Rabin_Karp_Matcher(string T, string P,int d,int q)//"d" is the radix and "q" is the number which will be the mod
	{
		int n = t.length();
		int m = p.length();
		/*
			ÿ��������һλ��T��Ӧ����Ϊm�Ĵ��Ĺ�ϣֵt[s+1]=(d*(t[s]-T[s+1]*h)+T[s+m+1])
		*/
		ll h1 = fastpower((ll)d, (ll)(m - 1), (ll)q);
		int h = h1;
		int pattern = 0, temp = 0;//Ԥ�������p��t0
		for (int i = 0; i < m; i++) {
			pattern = (d * pattern + (int)P[i]) % q;
			temp = (d * temp + (int)T[i]) % q;
		}
		for (int s = 0; s <= n - m; s++) {
			if (pattern == temp) {//��ϣ�ɹ�����Ҫ������ַ����Ƿ����
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
				//������һ��ƫ������ԭ���г���Ϊm���ַ����Ĺ�ϣֵ
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
	ss.Rabin_Karp_Matcher(ss.t, ss.p, 96, 5999677);//ascll��ǰ32���޷�����ʾ���˴�ѡȡһ��7λ����
	return 0;
}

/*
����������
2359023141526739921
31415
*/