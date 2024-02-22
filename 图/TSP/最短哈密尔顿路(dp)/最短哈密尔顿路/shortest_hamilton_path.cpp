#include "Shortest_Hamilton_Path.h"
using namespace std;

int shortest_hamilton_path::findpath(vector<vector<int>>& graph, vector<vector<int>>& dp)
{
	//��ʼ����ֻ��һ�����·������Ϊ0
	int n = graph.size();
	for (int i = 0; i < n; i++) dp[1 << i][i] = 0;
	int len = (1 << n) - 1;
	for (int v = 0; v < n; v++) {//�оٵ�
		for (int state = 0; state <= len; state++) {//ö��״̬
			if ((state >> v) & 1) continue;//v�Ѿ���state״̬���ˣ����������
			for (int u = 0; u < n; u++) {
				if (graph[u][v] >= 0) {
					//��u,v����·ʱ�����Ŀǰ״̬���һ����uָ��v��·�������ԭ���İ���v��״̬�µ�·���̣�����
					dp[state | (1 << v)][v] = min(dp[state | (1 << v)][v], dp[state][u] + graph[u][v]);
				}
			}
		}
	}
	int ans = 0x33333333;
	for (int x = 0; x < n; x++) ans = min(ans, dp[len][x]);
	return ans;
}