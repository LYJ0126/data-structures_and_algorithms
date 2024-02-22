#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;


//从源结点深度优先搜索
int cnt = 0;
void dfs_visit(vector<vector<int>>& graph, int source, vector<bool>& visited)
{
	visited[source] = true;//标记这个点走过
	cout << source << ' ';
	cnt++;
	for (int i = 0; i < graph[source].size(); i++) {
		if (!visited[graph[source][i]]) dfs_visit(graph, graph[source][i], visited);
	}
}
//图的深度优先遍历
void dfs(vector<vector<int>>& graph, vector<bool>& visited)
{
	for (int i = 1; i < graph.size(); i++) {
		if (!visited[i]) dfs_visit(graph, i, visited);//没有搜索过的点为源结点开始深搜
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>>graph(n + 1);//领接表存图，这里选择有向图
	int x, y;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		graph[x].push_back(y);
	}
	vector<bool>visited(n + 1, false);//用于dfs_visit，记录哪些结点已经搜索过
	int source;
	cin >> source;
	//dfs_visit源结点，输出访问的结点
	dfs_visit(graph, source, visited);
	cout << '\n';
	cout << cnt << '\n';
	//图的深度优先遍历
	for (int i = 1; i <= n; i++) visited[i] = false;//初始化
	dfs(graph, visited);
	return 0;
}

/*
sample 1:
6 8
1 2
1 4
2 3
3 4
4 2
5 3
5 6
6 6
1
*/
/*
output 1:
1 2 3 4
4
1 2 3 4 5 6
*/

/*
sample 2:
6 8
1 2
1 4
2 3
3 4
4 2
5 3
5 6
6 6
5
*/
/*
output 2:
5 3 4 2 6
5
1 2 3 4 5 6
*/