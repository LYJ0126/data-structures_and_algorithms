#include<iostream>
#include<vector>
#include<cstring>
#include "KMP.h"
using namespace std;

vector<int> kmp::compute_prefix_function(string& p)//计算前缀函数
{
	int m = p.length();
	vector<int>exchange(m + 1);//前缀函数用数组表示
	exchange[0] = 0;
	int k = 0;
	for (int q = 1; q < m; q++) {
	//q是后面的数,k是前缀开始的地方
		while (k > 0 && p[k] != p[q]) k = exchange[k - 1];
		//当后面的组合与前缀不同时,前缀数-1继续匹配
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
			//如果匹配失败,往前找与前缀相同组合的位置
			q = exchange[q - 1];
			//只要next[q-1]不大于0,那么就是还没找到与前缀相同的组合
			//继续在循环中找到与前缀相同的组合,直到next[q-1]等于0
		}
		if (p[q] == t[i]) q++;
		if (q == m ) {
			cout << "Pattern occurs with shift " << i - m + 1 << endl;
			q = exchange[q - 1];
		}
	}
	vector<int>().swap(exchange);
}