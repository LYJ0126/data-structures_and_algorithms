#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int n, m, x, y,times = 0;
vector<vector<int>>graph;
vector<bool>visited;//记录点是否搜索过
vector<int>dfn;//表示当前点遍历序列号
vector<int>low;//low[u]表示u及u的子结点通过非树边所能找到的最早的祖先节点的序列号
vector<int>parent;//parent表示该节点前一个访问的节点
vector<int>children;//children表示该结点在深度优先树中的子节点个数
vector<int>ans;//保存点割集
void dfscv(int u)
{
	times++;
	dfn[u] = times;
	low[u] = dfn[u];
	visited[u] = true;
	int len = graph[u].size();
	for (int i = 0; i < len; i++) {
		int v = graph[u][i];
		if (!visited[v]) {//u->v是树边，即节点v之前没被遍历过
			parent[v] = u;
			children[u]++;
			dfscv(v);//深搜
			low[u] = min(low[u], low[v]);//low[u]取low[u]和low[v]最小值
			if (parent[u] == INT_MIN && children[u] >= 2) ans.push_back(u);//当u是根且连接至少两个子树时，u是割点
			else if (parent[u] != INT_MIN && low[v] >= dfn[u]) ans.push_back(u);
			//当u不是根且low[v]>=dfn[u]，说明v及其子结点最多能指到u，没有其他路径能指到u的祖先，说明u是割点
		}
		else if (v!=parent[u]) {//v->u不是树边
			low[u] = min(low[u], dfn[v]);
			//u->v是一条后向边，即v此前以及被访问过了，v是u的祖先，取该祖先的遍历序列值和low[u]比较即可
		}
	}
}
int main()
{
	cin >> n >> m;
	graph.resize(n + 1);
	visited.resize(n + 1, false);
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);//这里为无向图
	}
	dfn.resize(n + 1, 0);
	low.resize(n + 1);
	parent.resize(n + 1);
	parent[1] = INT_MIN;//特殊标记，根节点(这里为1)没有双亲节点
	children.resize(n + 1, 0);
	dfscv(1);
	cout << "点割集为: ";
	for (int i : ans) cout << i << ' ';
	return 0;
}
/*
sample:
input:
7 8
1 2
1 4
2 4
3 2
3 4
5 2
1 6
6 7
output: 2 6 1
*/