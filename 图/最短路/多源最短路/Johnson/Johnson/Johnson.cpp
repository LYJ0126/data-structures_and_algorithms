#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

typedef long long ll;
const ll INF = 0x7ffffffffff;
vector<vector<pair<int, ll>>>graph;
vector<ll>d;
vector<ll>h;
vector<ll>tempd;
vector<bool>vis;
vector<vector<ll>>ans;
int n, m, x, y;
ll w;
bool bellman_ford()
{
	d[0] = 0;//�ƽ��ΪԴ��
	int uu, vv;
	ll ww;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {//�����б߽���·���ɳ�
			int len = graph[j].size();
			for (int k = 0; k < len; ++k) {
				uu = j, vv = graph[j][k].first, ww = graph[j][k].second;
				if (d[vv] > d[uu] + ww) d[vv] = d[uu] + ww;
			}
		}
	}
	//�ж��Ƿ��и�Ȩ��·
	for (int j = 0; j <= n; ++j) {
		int len = graph[j].size();
		for (int k = 0; k < len; ++k) {
			uu = j, vv = graph[j][k].first, ww = graph[j][k].second;
			if (d[vv] > d[uu] + ww) return false;
		}
	}
	return true;
}

bool cmp(pair<int, ll>& a, pair<int, ll>& b)//����С���ѱȽϺ���
{
	return a.second > b.second;
}
priority_queue < pair<int, ll>, vector<pair<int, ll>>, decltype(&cmp)> pq(cmp);
void dijkstra(int s)
{
	tempd[s] = 0;
	pq.push(make_pair(s, tempd[s]));
	int u, v;
	ll len;
	vector<pair<int, ll>>::iterator it;
	while (!pq.empty()) {
		u = pq.top().first;//ȡ��ǰ���ȶ�����dֵ��С�Ľ��и���
		vis[u] = true;
		pq.pop();
		for (it = graph[u].begin(); it != graph[u].end(); it++) {//·���ɳ�
			v = it->first;
			if (!vis[v]) {
				len = it->second;
				if (tempd[v] > tempd[u] + len) {
					tempd[v] = tempd[u] + len;
					pq.push(make_pair(v, tempd[v]));
				}
			}
		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	graph.resize(n + 1);
	ans.resize(n + 1, vector<ll>(n + 1));
	d.resize(n + 1, INF);
	tempd.resize(n + 1);
	h.resize(n + 1);
	vis.resize(n + 1);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d%lld", &x, &y, &w);
		graph[x].push_back(make_pair(y, w));
	}
	//�����ƽ��
	for (int i = 1; i <= n; ++i) {
		graph[0].push_back(make_pair(i, 0));
	}
	if (!bellman_ford()) printf("�и�Ȩ��\n");
	else {
		for (int i = 0; i <= n; ++i) h[i] = d[i];//����h[v]
		for (int j = 0; j <= n; ++j) {
			int len = graph[j].size();
			for (int k = 0; k < len; ++k) graph[j][k].second = graph[j][k].second + h[j] - h[graph[j][k].first];//�µı�Ȩ
		}
		//ÿ����ΪԴ�����һ��Dijkstra
		for (int i = 1; i <= n; ++i) {
			for (int p = 0; p <= n; ++p) {
				tempd[p] = INF;
				vis[p] = false;
			}
			dijkstra(i);
			ll olddis;
			for (int j = 1; j <= n; ++j) {
				if (tempd[j] == INF) olddis = INF;
				else olddis = tempd[j] + h[j] - h[i];
				ans[i][j] = olddis;
			}
		}
		printf("ȫԴ���·�������:\n");
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (ans[i][j] == INF) printf("INF\t");
				else printf("%lld\t", ans[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}

/*
input:
5 7
1 2 4
1 4 10
2 3 7
4 5 3
4 2 -2
3 4 -3
5 3 4
output:

*/