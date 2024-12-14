#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;

//这里采用MST的方法来解决TSP问题
//首先找出原来完全图的最小生成树，然后对这个最小生成树进行DFS遍历，形成一条回路
//这条回路就是TSP问题的近似解

int n, x, y, w;
vector<vector<int>> graph;//图的邻接矩阵
int ans = 0;//最终哈密尔顿回路的长度
vector<vector<int>> tree;//记录最小生成树
//prim算法求最小生成树
bool cmp(pair<int, int>& a, pair<int, int>& b)
{
	return a.second > b.second;
}
//最小优先队列，第一个元素高位存parent,低位存该结点，第二个元素存边的权值
priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)>pq(&cmp);

void prim()
{
	//取任意一个结点作为起始结点
	pq.push(make_pair(1, 0));
	vector<bool> visited(n + 1, false);
	while (!pq.empty()) {
		int u = pq.top().first & 0x00003fff;
		int parent = pq.top().first >> 14;
		pq.pop();
		if (visited[u]) continue;
		visited[u] = true;
		if (parent != 0) {//parent不为0说明不是第一个结点,将该边加入最小生成树
			tree[parent].push_back(u);
			tree[u].push_back(parent);
		}
		for (int i = 1; i <= n; ++i) {
			if (graph[u][i] != 0 && !visited[i]) {
				pq.push(make_pair((u << 14) + i, graph[u][i]));
			}
		}
	}
}

int former = 0;//记录哈密尔顿回路的前一个结点
vector<bool> vis;//记录dfs的访问情况
void dfs_find(int u)//在MST上dfs，找到哈密尔顿回路
{
	vis[u] = true;
	if (former != 0) {
		cout<< former << "->" << u << endl;
		ans += graph[former][u];
	}
	former = u;
	for (int v : tree[u]) {
		if (!vis[v]) {
			dfs_find(v);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	graph.resize(n + 1, vector<int>(n + 1, 0));//完全图，邻接矩阵
	tree.resize(n + 1);
	int m = n * (n - 1) / 2;//完全图的边数
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> w;
		graph[x][y] = w;
		graph[y][x] = w;
	}
	prim();
	former = 0;
	vis.resize(n + 1, false);
	cout << "哈密尔顿回路为：" << endl;
	dfs_find(1);
	cout << former << "->1" << endl;
	ans += graph[former][1];
	cout << "回路长度为：" << ans << endl;
	return 0;
}

/*
input:
5
1 2 6
1 3 3
1 4 2
1 5 4
2 3 5
2 4 1
2 5 8
3 4 10
3 5 9
4 5 7
output:
哈密尔顿回路为：
1->4
4->2
2->3
3->5
5->1
回路长度为：21
*/