#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

bool bfs_judge(vector<vector<int>>& graph, vector<bool>& visited, int u, int v)
{
	if (v == u) return true;
	queue<int>que;
	que.push(u);
	visited[u] = true;
	while (!que.empty()) {
		int size = que.size();
		while (size) {
			int start = que.front();
			que.pop();
			for (int i = 0; i < graph[start].size(); i++) {
				if (v == graph[start][i]) return true;
				if (!visited[graph[start][i]]) {
					que.push(graph[start][i]);
					visited[graph[start][i]] = true;
				}
			}
			size--;
		}
	}
	return false;
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>>graph(n + 1);//领接表
	int x, y;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		graph[x].push_back(y);
	}
	int u, v;
	cin >> u >> v;
	//判断u,v之间是否存在路径
	vector<bool>visited(n + 1, false);
	cout << boolalpha << bfs_judge(graph, visited, u, v);
	return 0;
}
/*
sample 1:
7 8
1 2
1 4
2 3
3 4
4 2
5 3
5 6
6 6
5 2
*/
/*
output 1:
true
*/

/*
sample 2:
7 8
1 2
1 4
2 3
3 4
4 2
5 3
5 6
6 6
2 5
*/
/*
output 2:
false
*/

/*
sample 3:
7 8
1 2
1 4
2 3
3 4
4 2
5 3
5 6
6 6
1 7
*/
/*
output 3:
false
*/