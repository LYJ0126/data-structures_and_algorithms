#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

bool dfs_judge(vector<vector<int>>& graph, vector<bool>& visited, int u, int v)
{
	if (v == u) return true;
	visited[u] = true;
	for (int i = 0; i < graph[u].size(); i++) {
		if (!visited[graph[u][i]]) return dfs_judge(graph, visited, graph[u][i], v);
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
	//深搜判断
	vector<bool>visited(n + 1, false);
	cout << boolalpha << dfs_judge(graph, visited, u, v);
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