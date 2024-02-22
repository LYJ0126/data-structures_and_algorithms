#include<iostream>
#include<vector>
#include<cmath>
#include<stack>
using namespace std;


//注意！拓扑排序只能用于DAG(有向无环图)中
//DAG一定含有至少一种拓扑排序
int n, m, x, y;
vector<vector<int>>graph;
vector<int>ans;//答案数组
stack<int>st;//递归过程中记录答案，最后输出即是拓扑序
vector<bool>vis;
void dfs(int u)//深搜到底后，回溯的时候点入栈。访问结束早的点先入栈，即被指向的点比指向它的点先入栈
{
	vis[u] = true;
	for (int v : graph[u]) {
		if (!vis[v]) dfs(v);
	}
	st.push(u);
}
void dfs_topological_sort()
{
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) dfs(i);
	}
}
int main()
{
	cin >> n >> m;
	graph.resize(n + 1);
	ans.resize(n + 1);
	vis.resize(n + 1, false);
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		graph[x].push_back(y);
	}
	dfs_topological_sort();
	cout << "拓扑排序结果:\n";
	while (!st.empty()) {
		cout << st.top() << ' ';
		st.pop();
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
5 6 4 3 2 1 8 9 7
*/