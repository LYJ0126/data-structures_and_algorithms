#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "Shortest_Hamilton_Path.h"
using namespace std;

int n, m, x, y, w;
vector<vector<int>>graph;
vector<vector<int>>dp;
int main()
{
	scanf("%d%d", &n, &m);
	graph.resize(n, vector<int>(n, -1));//邻接矩阵存图
	dp.resize((1 << n), vector<int>(n, 0x3f3f3f3f));//2^n个状态
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &x, &y, &w);
		if (graph[x - 1][y - 1] >= 0) graph[x - 1][y - 1] = graph[y - 1][x - 1] = min(graph[x - 1][y - 1], w);//有重边取最小
		else graph[x-1][y-1] = graph[y-1][x-1] = w;
	}
	shortest_hamilton_path ss;
	int res = ss.findpath(graph, dp);
	if (res == 0x33333333) cout << "No Hamilton path." << endl;
	else cout << ss.findpath(graph, dp) << endl;
	return 0;
}

/*
sample:
input:
4 6
1 2 3
1 3 4
1 4 5
2 3 5
2 4 6
3 4 7
output:
13
*/