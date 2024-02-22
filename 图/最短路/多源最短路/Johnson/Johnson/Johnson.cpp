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
	d[0] = 0;//哑结点为源点
	int uu, vv;
	ll ww;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {//对所有边进行路径松弛
			int len = graph[j].size();
			for (int k = 0; k < len; ++k) {
				uu = j, vv = graph[j][k].first, ww = graph[j][k].second;
				if (d[vv] > d[uu] + ww) d[vv] = d[uu] + ww;
			}
		}
	}
	//判断是否有负权环路
	for (int j = 0; j <= n; ++j) {
		int len = graph[j].size();
		for (int k = 0; k < len; ++k) {
			uu = j, vv = graph[j][k].first, ww = graph[j][k].second;
			if (d[vv] > d[uu] + ww) return false;
		}
	}
	return true;
}

bool cmp(pair<int, ll>& a, pair<int, ll>& b)//定义小顶堆比较函数
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
		u = pq.top().first;//取当前优先队列中d值最小的进行更新
		vis[u] = true;
		pq.pop();
		for (it = graph[u].begin(); it != graph[u].end(); it++) {//路径松弛
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
	//增加哑结点
	for (int i = 1; i <= n; ++i) {
		graph[0].push_back(make_pair(i, 0));
	}
	if (!bellman_ford()) printf("有负权环\n");
	else {
		for (int i = 0; i <= n; ++i) h[i] = d[i];//设置h[v]
		for (int j = 0; j <= n; ++j) {
			int len = graph[j].size();
			for (int k = 0; k < len; ++k) graph[j][k].second = graph[j][k].second + h[j] - h[graph[j][k].first];//新的边权
		}
		//每个点为源点进行一次Dijkstra
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
		printf("全源最短路结果矩阵:\n");
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