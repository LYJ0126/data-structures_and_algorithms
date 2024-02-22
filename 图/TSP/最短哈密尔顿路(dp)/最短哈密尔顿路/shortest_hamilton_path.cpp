#include "Shortest_Hamilton_Path.h"
using namespace std;

int shortest_hamilton_path::findpath(vector<vector<int>>& graph, vector<vector<int>>& dp)
{
	//初始化。只有一个点的路径长度为0
	int n = graph.size();
	for (int i = 0; i < n; i++) dp[1 << i][i] = 0;
	int len = (1 << n) - 1;
	for (int v = 0; v < n; v++) {//列举点
		for (int state = 0; state <= len; state++) {//枚举状态
			if ((state >> v) & 1) continue;//v已经在state状态里了，不能再添加
			for (int u = 0; u < n; u++) {
				if (graph[u][v] >= 0) {
					//当u,v存在路时，如果目前状态添加一条从u指向v的路，相比于原来的包含v的状态下的路更短，更新
					dp[state | (1 << v)][v] = min(dp[state | (1 << v)][v], dp[state][u] + graph[u][v]);
				}
			}
		}
	}
	int ans = 0x33333333;
	for (int x = 0; x < n; x++) ans = min(ans, dp[len][x]);
	return ans;
}