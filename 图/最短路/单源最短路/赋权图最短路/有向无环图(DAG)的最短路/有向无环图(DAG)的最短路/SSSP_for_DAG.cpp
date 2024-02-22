#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;

int n, m, x, y, w, s;
vector<vector<pair<int, int>>>graph;//第一个值为邻点，第二个值为权重
vector<int>indeg;//度序列,注意是入度
vector<int>sort_res;//记录排序结果
vector<int>d;//记录最短路
void bfs_topological_sort()//这里选择BFS拓扑排序
{
	int id = 0;
	queue<int>que;
	vector<bool>vis(n + 1, false);//记录哪些点已经放入答案数组中了
	for (int i = 1; i <= n; i++) {//所有入度为0的入队，并记录入答案数组
		if (!indeg[i]) {
			que.push(i);
			sort_res[++id] = i;
			vis[i] = true;
		}
	}
	vector<pair<int, int>>::iterator it;
	int v;
	while (!que.empty()) {//bfs
		int size = que.size();
		while (size) {
			int u = que.front();
			que.pop();
			for (it = graph[u].begin(); it != graph[u].end();it++) {
				v = it->first;
				if (!vis[v]) {
					if (!--indeg[v]) {
						que.push(v);
						sort_res[++id] = v;
						vis[v] = true;
					}
				}
			}
			--size;
		}
	}
}
void dag_shortest_path()
{
	bfs_topological_sort();
	int u, v, weight;
	d[s] = 0;
	vector<pair<int, int>>::iterator it;
	for (int i = 1; i <= n; ++i) {//按照拓扑排序顺序选取点并对其邻边进行松弛
		u = sort_res[i];
		for (it = graph[u].begin(); it != graph[u].end(); it++) {//路径松弛
			v = it->first, weight = it->second;
			if (d[v] > d[u] + weight) d[v] = d[u] + weight;
		}
	}
}
int main()
{
	cin >> n >> m >> s;
	graph.resize(n + 1);
	indeg.resize(n + 1, 0);
	sort_res.resize(n + 1);
	d.resize(n + 1, 0x7f7f7f7f);
	for (int i = 0; i < m; ++i) {
		cin >> x >> y >> w;
		graph[x].push_back(make_pair(y, w));
		indeg[y]++;
	}
	dag_shortest_path();
	cout << "各个点到源点" << s << "的最短路为:\n";
	for (int i = 1; i <= n; i++) {
		if (d[i] == 0x7f7f7f7f) cout << i << " : " << "INF" << '\n';
		else cout << i << " : " << d[i] << '\n';
	}
}

/*
input:
6 10 1
1 4 2
1 3 6
2 1 5
2 4 3
3 6 1
3 5 -1
4 3 7
4 5 4
4 6 2
5 6 -2
output:
各个点到源点1的最短路为:
1 : 0
2 : INF
3 : 6
4 : 2
5 : 5
6 : 3
*/