#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;

//!注意，拓扑排序是针对DAG(有向无环图)的
//!每个DAG至少存在一种拓扑排序
int n, m, x, y;
vector<vector<int>>graph;
vector<int>indeg;//度序列,注意是入度
vector<int>ans;//记录排序结果
void bfs_topological_sort()
{
	int id = 0;
	queue<int>que;
	vector<bool>vis(n + 1, false);//记录哪些点已经放入答案数组中了
	for (int i = 1; i <= n; i++) {//所有入度为0的入队，并记录入答案数组
		if (!indeg[i]) {
			que.push(i);
			ans[++id] = i;
			vis[i] = true;
		}
	}
	while (!que.empty()) {//bfs
		int size = que.size();
		while (size) {
			int u = que.front();
			que.pop();
			for (int v : graph[u]) {
				if (!vis[v]) {
					if (!--indeg[v]) {
						que.push(v);
						ans[++id] = v;
						vis[v] = true;
					}
				}
			}
			--size;
		}
	}
}
int main()
{
	cin >> n >> m;
	graph.resize(n + 1);
	indeg.resize(n + 1, 0);
	ans.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		graph[x].push_back(y);
		indeg[y]++;//y入度加一
	}
	bfs_topological_sort();
	cout << "拓扑排序结果:\n";
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << ' ';
	}
	return 0;
}
/*
input:
9 9
1 7
1 8
2 7
4 1
4 7
5 8
5 6
6 9
8 9
output:
拓扑排序结果:
2 3 4 5 1 6 7 8 9
*/