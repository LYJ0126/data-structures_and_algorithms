#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// 链式前向星
const int N = 10010;
const int M = 100010;
int head[N], weight[M], nxt[M], to[M], cnt = 0;
// head[i]表示以i为起点的第一条边的编号, weight[i]表示第i条边的权重
//next[i]表示编号为i的边的下一条边的编号, to[i]表示编号为i的边的终点
void add(int u, int v, int w) {
	to[++cnt] = v;//编号为cnt的边的终点为v
	weight[cnt] = w;//编号为cnt的边的权重为w
	nxt[cnt] = head[u];//编号为cnt的边的下一条边的编号为head[u]
	head[u] = cnt;//以u为起点的第一条边的编号为cnt
}
void delete_edge(int u, int v) {
	if (to[head[u]] == v) head[u] = nxt[head[u]];
	else {
		int former = head[u];
		for (int i = nxt[head[u]]; i; i = nxt[i]) {
			if (to[i] == v) {
				nxt[former] = nxt[i];
				break;
			}
			former = i;
		}
	}
}
void dfs(int s, vector<bool>&visited) {
	visited[s] = true;
	cout<<s<< " ";
	for (int i = head[s]; i; i = nxt[i]) {//遍历以s为起点的所有边
		int v=to[i];
		if (!visited[v]) dfs(v, visited);
	}
}
void bfs(int s, int n) {
	queue<int>q;
	q.push(s);
	vector<bool>vis(n + 1);
	vis[s] = true;
	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			int u = q.front();
			q.pop();
			cout << u << " ";
			for (int i = head[u]; i; i = nxt[i]) {
				int v = to[i];
				if (!vis[v]) {
					q.push(v);
					vis[v] = true;
				}
			}
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		add(u, v, w);
	}
	vector<bool>visited(n + 1);
	dfs(1, visited);	
	cout << endl;
	bfs(1, n);
	return 0;
}