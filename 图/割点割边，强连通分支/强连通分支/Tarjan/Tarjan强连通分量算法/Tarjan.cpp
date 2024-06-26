#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<stack>
using namespace std;

int n, m, x, y;
vector<vector<int>>graph;
vector<bool>visited;
vector<int>d;//记录访问时间戳
vector<int>low;//low[u]记录u以及其后代顶点通过非树边关联的栈内(u以及其祖先节点)邻点的最先访问次序，即能访问到的最早的祖先的时间戳
stack<int>st;//记录栈内顶点
vector<bool>ins;//判断点是否在栈内
int times = 0;//时间戳
int part = 0;//强连通分支个数
void dfsscc(int u)
{
	times++;
	d[u] = times;
	low[u] = d[u];
	visited[u] = true;
	st.push(u);
	ins[u] = true;
	for (int v : graph[u]) {
		if (!visited[v]) {
			dfsscc(v);
			low[u] = min(low[u], low[v]);
		}
		else if (ins[v]) {//v在栈内
			low[u] = min(low[u], d[v]);
		}
	}
	if (low[u] == d[u]) {
		cout << "以下顶点组成强连通分支 " << ++part << endl;
		int p;
		do {
			p = st.top();
			st.pop();
			ins[p] = false;
			cout << p << ' ';
		} while (p != u);
		cout << endl;
	}
}
void tarjan()
{
	for (int s = 1; s <= n; ++s) {
		if (!visited[s]) dfsscc(s);
	}
}
int main()
{
	cin >> n >> m;
	graph.resize(n + 1);
	visited.resize(n + 1, false);
	d.resize(n + 1);
	low.resize(n + 1);
	ins.resize(n + 1, false);
	for (int i = 0; i < m; ++i) {
		cin >> x >> y;
		graph[x].push_back(y);//有向图
	}
	tarjan();
	return 0;
}

/*
input:
5 8
1 2
2 1
1 4
1 5
4 2
4 5
3 2
3 4
output:
以下顶点组成强连通分支 1
5
以下顶点组成强连通分支 2
4 2 1
以下顶点组成强连通分支 3
3
*/