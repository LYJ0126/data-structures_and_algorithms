#include<cmath>
#include "Shortes_Hamilton_Path.h"
using namespace std;

int shortest_hamilton_path::dfs(vector<vector<int>>& graph, vector<vector<int>>& dp, int state, int v)
{
	if (dp[state][v] < 99999999) return dp[state][v];//记忆化搜索
	int n = graph.size();
	int temp = 99999999, formerstate = state ^ (1 << v);
	for (int u = 0; u < n; u++) {
		if (u == v) continue;
		if (graph[u][v] == 99999999) continue;//没有边
		if (!((formerstate >> u) & 1)) continue;//上一个状态不包含点u
		temp = min(temp, dfs(graph, dp, formerstate, u) + graph[u][v]);//向下递归找子问题
	}
	dp[state][v] = temp;//记忆化
	return temp;
}