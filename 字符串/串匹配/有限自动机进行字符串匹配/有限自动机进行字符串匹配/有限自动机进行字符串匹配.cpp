#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

//计算转移函数,参数实际为模式串P和字母表Σ，这里为了方便，字母表设为26个小写字母
//最终得到的转移函数表示为状态转移表
char table[26];
string t, p;
//构造状态转移表
vector<vector<int>> compute_transition_function(string P, char* T,int len)
{
	int m = P.length();
	vector<vector<int>>g(m + 1, vector<int>(26, 0));
	for (int q = 0; q <= m; q++) {
		for (int i = 0; i < len; i++) {
			int k = min(m, q + 1);
			int t1 = k - 1;
			//寻找最大k
			while (k>0) {
				if (P[k - 1] != T[i]) k--;//检查输入的字符是否匹配
				else {//在输入字符匹配匹配情况下，P前k-1字符构成前缀是否为模式串后缀
					int temp1 = t1-1, temp2 = k - 2;
					bool flag = true;
					while (temp2 >= 0) {
						if (P[temp1] != P[temp2]) {
							flag = false;
							break;
						}
						temp1--, temp2--;
					}
					if (flag) {
						break;
					}
					k--;
				}
			}
			g[q][i] = k;
		}
	}
	return g;
}

//DFA匹配
void finite_automaton_matcher(string T, vector<vector<int>>& g, int m)
{
	int n = T.length();
	int q = 0;
	for (int i = 0; i < n; i++) {
		q = g[q][T[i] - 'a'];//状态转移
		if (q == m) cout << "Pattern occurs with shift " << i - m + 1 << endl;
	}
}
int main()
{
	for (int i = 0; i < 26; i++) table[i] = (char)(i + 97);
	cin >> t >> p;
	vector<vector<int>>graph = compute_transition_function(p, table, 26);
	finite_automaton_matcher(t, graph, p.length());
	vector<vector<int>>().swap(graph);
	return 0;
}