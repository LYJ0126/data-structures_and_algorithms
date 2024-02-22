#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

void bfsfind(vector<vector<int>>& graph, int source, vector<int>& path, vector<bool>& visited)
{
	path[source] = 0;
	queue<int>que;
	que.push(source);
	visited[source] = true;
	int dis = 0;//距离
	while (!que.empty()) {
		int size = que.size();
		dis++;
		while (size) {
			int u = que.front();
			que.pop();
			for (int i = 0; i < graph[u].size(); i++) {
				if (!visited[graph[u][i]]) {
					que.push(graph[u][i]);
					visited[graph[u][i]] = true;
					path[graph[u][i]] = dis;
				}
			}
			size--;
		}
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>>graph(n + 1);
	int x, y;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		graph[x].push_back(y);
	}
	int source;
	cin >> source;
	vector<int>path(n + 1, -1);//开始赋值-1作为特殊标记（无穷标记）
	vector<bool>visited(n + 1, false);//初始化
	bfsfind(graph, source, path, visited);//广搜确定单源最短路
	for (int i = 1; i <= n; i++) {
		cout << i << " : ";
		if (path[i] == -1) cout << "No path." << '\n';
		else cout << path[i] << '\n';
	}
	return 0;
}

/*
sample 1 :
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
1 : 0
2 : 1
3 : 2
4 : 1
5 : No path.
6 : No path.
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
1 : No path.
2 : 3
3 : 1
4 : 2
5 : 0
6 : 1
*/