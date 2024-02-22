#include<cmath>
#include "Shortes_Hamilton_Path.h"
using namespace std;

int shortest_hamilton_path::dfs(vector<vector<int>>& graph, vector<vector<int>>& dp, int state, int v)
{
	if (dp[state][v] < 99999999) return dp[state][v];//���仯����
	int n = graph.size();
	int temp = 99999999, formerstate = state ^ (1 << v);
	for (int u = 0; u < n; u++) {
		if (u == v) continue;
		if (graph[u][v] == 99999999) continue;//û�б�
		if (!((formerstate >> u) & 1)) continue;//��һ��״̬��������u
		temp = min(temp, dfs(graph, dp, formerstate, u) + graph[u][v]);//���µݹ���������
	}
	dp[state][v] = temp;//���仯
	return temp;
}