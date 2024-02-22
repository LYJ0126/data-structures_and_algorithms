#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int n, m, x, y;
bool flag = true;
vector<vector<int>>graph;
vector<bool>book;
void dfs(int u)
{
	book[u] = true;
	int len = graph[u].size();
	for (int i = 0; i < len; i++) {
		if (!book[graph[u][i]]) dfs(graph[u][i]);
	}
}
int main()
{
	cin >> n >> m;
	graph.resize(n + 1);
	book.resize(n + 1, false);
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		//这里选择无向图
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	dfs(1);
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