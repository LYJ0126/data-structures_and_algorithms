#include "Bipartite_Graph_Judge.h"
#include<queue>
using namespace std;

bool bipartite_graph_judge::dfsbpt(vector<vector<int>>& graph, vector<int>& color, vector<bool>&visited, int u)
{
	visited[u] = true;
	bool flag = true;
	for (int v : graph[u]) {
		if (!visited[v]) {
			color[v] = -color[u];//u,vȾ��ͬɫ
			flag &= dfsbpt(graph, color, visited, v);
		}
		else if (color[u] == color[v]) flag &= false;//v�����ʹ������ڵ�ͬɫ
	}
	return flag;
}

bool bipartite_graph_judge::bfsbpt(vector<vector<int>>& graph, vector<int>& color)
{
	int n = graph.size();
	vector<bool>visited(n, false);
	queue<int>que;
	visited[1] = true;
	que.push(1);
	bool flag = true;
	while (!que.empty()) {
		int size = que.size();
		while (size) {
			int u = que.front();
			que.pop();
			for (int v : graph[u]) {
				if (!visited[v]) {//u,vȾ��ͬɫ
					color[v] = -color[u];
					que.push(v);
					visited[v] = true;
				}
				else if (color[v] == color[u]) {//v�����ʹ�����uͬɫ
					flag = false;
					break;
				}
			}
			if (!flag) break;
			size--;
		}
		if (!flag) break;
	}
	return flag;
}