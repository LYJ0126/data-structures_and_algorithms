#include<iostream>
#include<cmath>
#include "Shortes_Hamilton_Path.h"
using namespace std;
int n, m, x, y, w;
vector<vector<int>>graph;
vector<vector<int>>dp;

int main()
{
	cin >> n >> m;
	int len = (1 << n) - 1;
	//初始化
	graph.resize(n, vector<int>(n, 99999999));
	dp.resize(len + 1, vector<int>(n, 99999999));
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> w;
		graph[x - 1][y - 1] = graph[y - 1][x - 1] = min(graph[x - 1][y - 1], w);//注意！可能有重边
	}
	for (int x = 0; x < n; x++) dp[1 << x][x] = 0;
	int res = 0x3f3f3f3f;
	shortest_hamilton_path ss;
	for (int i = 0; i < n; i++) {
		res = min(res, ss.dfs(graph, dp, len, i));
	}
	if (res == 99999999) cout << -1;
	else cout << res;
	return 0;
}

/*
sample
input:
4 6
1 2 3
1 3 4
1 4 5
2 3 5
2 4 6
3 4 7
output:13
*/