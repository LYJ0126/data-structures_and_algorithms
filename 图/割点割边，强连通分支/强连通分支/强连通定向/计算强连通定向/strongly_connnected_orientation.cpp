#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<unordered_map>
using namespace std;
//这里我们认为原来的无向图连通且没有割边，即必定存在强连通定向(罗宾斯定理)
int n, m, x, y;
vector<vector<int>>graph;
vector<vector<int>>graph2;
vector<bool>visited;
unordered_map<int, int>mp;//用于确定边是否已经定向
void dfs_orientation(int s)
{
	visited[s] = true;
	for (int v : graph[s]) {
		if (!visited[v]) {
			graph2[s].push_back(v);//树边上是父结点指向子结点
			mp[(s << 12) + v] = mp[(v << 12) + s] = 1;//记录该边已经定向
			dfs_orientation(v);
		}
		else {
			if (!mp[(s << 12) + v]) {//如果该后向边没有被标记
				mp[(s << 12) + v] = mp[(v << 12) + s] = 1;
				graph2[s].push_back(v);
			}
		}
	}
}
int main()
{
	cin >> n >> m;
	graph.resize(n + 1);
	graph2.resize(n + 1);//后面定向生成的有向图
	visited.resize(n + 1, false);
	for (int i = 0; i < m; ++i) {
		cin >> x >> y;
		//输入无向图
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	dfs_orientation(1);
	cout << "定向为:" << endl;
	for (int u = 1; u <= n; ++u) {
		for (int v : graph2[u]) cout << u << " -> " << v << endl;
	}
	return 0;
}

/*
input:
5 7
1 2
4 1
4 2
1 5
2 5
3 2
3 4
output:
定向为:
1 -> 2
2 -> 4
2 -> 5
3 -> 2
4 -> 1
4 -> 3
5 -> 1
*/