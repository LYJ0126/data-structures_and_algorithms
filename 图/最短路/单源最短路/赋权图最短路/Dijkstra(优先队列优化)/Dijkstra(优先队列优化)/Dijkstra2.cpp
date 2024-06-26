#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;

int n, m, s, x, y, w;
//pair<int, int>pa;
vector<vector<pair<int, int>>>graph;
vector<int>d;
vector<bool>vis;
bool cmp(pair<int,int>& a, pair<int,int>& b)//定义小顶堆比较函数
{
	return a.second > b.second;
}
priority_queue < pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> pq(cmp);
void dijkstra()
{
	d[s] = 0;
	pq.push(make_pair(s, d[s]));
	int u, len, v;
	vector<pair<int, int>>::iterator it;
	while (!pq.empty()) {
		u = pq.top().first;//取当前优先队列中d值最小的进行更新
		pq.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (it = graph[u].begin(); it != graph[u].end(); it++) {//路径松弛
			v = it->first;
			int len = it->second;
			if (d[v] > d[u] + len) {
				d[v] = d[u] + len;
				if (!vis[v]) pq.push(make_pair(v, d[v]));
			}
		}
	}
}
int main()
{
	cin >> n >> m >> s;
	graph.resize(n + 1);
	d.resize(n + 1, 0x7f7f7f7f);
	vis.resize(n + 1, false);
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> w;
		graph[x].push_back(make_pair(y, w));
	}
	dijkstra();
	cout << "各个点到源点" << s << "的最短路为:\n";
	for (int i = 1; i <= n; i++) {
		cout << i << " : " << d[i] << '\n';
	}
	return 0;
}

/*
input:
5 10 1
1 2 3
1 5 5
2 3 6
2 5 2
3 4 2
4 3 7
4 1 3
5 2 1
5 3 4
5 4 6
output:
各个点到源点1的最短路为:
1 : 0
2 : 3
3 : 9
4 : 11
5 : 5
*/