#include<iostream>
#include<vector>
#include<cstring>
#include "KMP.h"
using namespace std;

vector<int> kmp::compute_prefix_function(string& p)//����ǰ׺����
{
	int m = p.length();
	vector<int>exchange(m + 1);//ǰ׺�����������ʾ
	exchange[0] = 0;
	int k = 0;
	for (int q = 1; q < m; q++) {
	//q�Ǻ������,k��ǰ׺��ʼ�ĵط�
		while (k > 0 && p[k] != p[q]) k = exchange[k - 1];
		//������������ǰ׺��ͬʱ,ǰ׺��-1����ƥ��
		if (p[k] == p[q]) k++;
		exchange[q] = k;
	}
	return exchange;
}

void kmp::kmp_mathcer(string& t, string& p)
{
	int n = t.length(), m = p.length();
	vector<int>exchange = compute_prefix_function(p);
	int q = 0;
	for (int i = 0; i < n; i++) {
		while (q > 0 && p[q] != t[i]) { 
			//���ƥ��ʧ��,��ǰ����ǰ׺��ͬ��ϵ�λ��
			q = exchange[q - 1];
			//ֻҪnext[q-1]������0,��ô���ǻ�û�ҵ���ǰ׺��ͬ�����
			//������ѭ�����ҵ���ǰ׺��ͬ�����,ֱ��next[q-1]����0
		}
		if (p[q] == t[i]) q++;
		if (q == m ) {
			cout << "Pattern occurs with shift " << i - m + 1 << endl;
			q = exchange[q - 1];
		}
	}
	vector<int>().swap(exchange);
}