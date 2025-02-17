#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

//����ת�ƺ���,����ʵ��Ϊģʽ��P����ĸ��������Ϊ�˷��㣬��ĸ����Ϊ26��Сд��ĸ
//���յõ���ת�ƺ�����ʾΪ״̬ת�Ʊ�
char table[26];
string t, p;
//����״̬ת�Ʊ�
vector<vector<int>> compute_transition_function(string P, char* T,int len)
{
	int m = P.length();
	vector<vector<int>>g(m + 1, vector<int>(26, 0));
	for (int q = 0; q <= m; q++) {
		for (int i = 0; i < len; i++) {
			int k = min(m, q + 1);
			int t1 = k - 1;
			//Ѱ�����k
			while (k>0) {
				if (P[k - 1] != T[i]) k--;//���������ַ��Ƿ�ƥ��
				else {//�������ַ�ƥ��ƥ������£�Pǰk-1�ַ�����ǰ׺�Ƿ�Ϊģʽ����׺
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

//DFAƥ��
void finite_automaton_matcher(string T, vector<vector<int>>& g, int m)
{
	int n = T.length();
	int q = 0;
	for (int i = 0; i < n; i++) {
		q = g[q][T[i] - 'a'];//״̬ת��
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