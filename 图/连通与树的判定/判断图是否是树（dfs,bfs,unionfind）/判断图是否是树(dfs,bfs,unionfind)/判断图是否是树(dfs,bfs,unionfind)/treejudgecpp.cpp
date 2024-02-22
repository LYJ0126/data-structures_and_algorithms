#include<queue>
#include<functional>
#include "TreeJudge.h"
using namespace std;

bool treejudge::bfs_judge(vector<vector<int>>& graph, int s)
{
	int n = graph.size();
	queue<int>que;
	vector<bool>visited(n, false);
	vector<int>pa(n, 0);//记录没个节点的父亲节点，根节点父节点为0
	que.push(s);
	visited[s] = true;
	while (!que.empty()) {
		int size = que.size();
		while (size) {
			int u = que.front();
			que.pop();
			for (int i : graph[u]) {
				if (visited[i]) {
					if (i != pa[u]) return false;
				}//存在指向祖先节点(注意不是父节点)的边，即点u存在邻点v，v不是其父亲节点。说明存在圈，不是树
				else if (!visited[i]) {
					que.push(i);
					pa[i] = u;//i父亲节点更新为u
					visited[i] = true;
				}
			}
			size--;
		}
	}
	//判断图是否连通
	for (int i = 1; i < n; i++) {
		if (!visited[i]) return false;//图不连通
	}
	return true;
}

/*bool treejudge::dfs(vector<vector<int>>& graph, int s, vector<bool>& visited, vector<int>& pa)
{
	visited[s] = true;
	if (graph[s].size() == 0) return true;//走到了叶节点
	bool flag = true;
	int len = graph[s].size();
	for (int i = 0; i < len; i++) {
		if(visited[])
	}
	return flag;
}*/

bool treejudge::dfs_judge(vector<vector<int>>& graph, int s)
{
	bool flag = true;//判断是否有圈
	int n = graph.size();
	vector<bool>visited(n, false);
	visited[s] = true;
	vector<int>pa(n, 0);//记录根节点，设根节点的父亲节点为0
	function<void(int)>dfs = [&](int u)->void {//pa表示该节点的父亲节点
		if (!flag) return;//有圈，直接返回。不用再搜索了
		if (graph[u].size() == 0) return;//到了叶节点，返回
		int len = graph[u].size();
		for (int i = 0; i < len; i++) {
			int v = graph[u][i];
			if (visited[v]) {
				if (pa[u] != v) {//当u的邻点杯访问过且不是x的父亲节点，说明存在圈
					flag = false;
					return;
				}
			}
			else {
				visited[v] = true;
				pa[v] = u;
				dfs(v);
			}
		}
	};
	dfs(s);
	if (!flag) return false;
	//判断是否连通
	for (int i = 1; i < n; i++) {
		if (!visited[i]) return false;
	}
	return true;
}

int treejudge::findpa(vector<int>& pa, int x)
{
	if (pa[x] == x) return x;
	else return pa[x] = findpa(pa, pa[x]);//路径压缩
}
bool treejudge::merge(vector<int>& pa, int x, int y)
{
	int px = findpa(pa, x);
	int py = findpa(pa, y);
	pa[py] = px;
	if (px == py) return true;//并入的时候同根，说明有圈
	else return false;
}
bool treejudge::unionfind_judge(vector<int>& pa, bool flag)
{
	bool liantong = true;
	int n = pa.size();
	for (int i = 2; i < n; i++) {
		if (findpa(pa, i) != findpa(pa, i-1)) {
			liantong = false;
			break;
		}
	}
	if (!liantong || flag) return false;//不连通或者有圈
	return true;
}