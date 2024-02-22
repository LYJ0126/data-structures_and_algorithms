#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m, x, y;
vector<vector<int>>graph;
vector<int>book;
void bfs()
{
	queue<int>que;
	que.push(1);
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		book[u] = true;
		int len = graph[u].size();
		for (int i = 0; i < len; i++) {
			if (!book[graph[u][i]]) que.push(graph[u][i]);
		}
	}
}
int main()
{
	cin >> n >> m;
	graph.resize(n + 1);
	book.resize(n + 1, false);
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);//这里是无向图
	}
	bfs();
	bool flag = true;
	for (int i = 1; i <= n; i++) {
		if (!book[i]) {
			flag = false;
			break;
		}
	}
	if (flag) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}

/*
sample1:
input:
5 6
1 2
1 4
4 2
2 3
4 3
2 5
output:
Yes

sample2:
input:
5 5
1 2
1 4
4 2
2 3
4 3
output:
No
*/