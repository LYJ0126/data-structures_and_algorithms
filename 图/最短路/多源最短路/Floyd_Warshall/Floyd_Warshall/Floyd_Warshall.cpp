#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int n, m, x, y, w;
const int INF = 0x7f7f7f7f;
vector<vector<int>>graph;//邻接矩阵存图
vector<vector<int>>ans;//全源最短路结果矩阵
int main()
{
	cin >> n >> m;
	graph.resize(n + 1, vector<int>(n + 1,INF));
	ans.resize(n + 1, vector<int>(n + 1, INF));
	for (int i = 0; i <= n; ++i) graph[i][i] = ans[i][i] = 0;//这里图不含负自环
	for (int i = 0; i < m; ++i) {
		cin >> x >> y >> w;
		graph[x][y] = min(graph[x][y], w); //可能有重边,排除重边影响
		ans[x][y] = min(ans[x][y], w);//可能有重边,排除重边影响
	}
	//floyd
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (!(ans[i][k] == INF || ans[k][j] == INF)) ans[i][j] = min(ans[i][j], ans[i][k] + ans[k][j]);
			}
		}
	}
	cout << "全源最短路结果矩阵:\n";
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (ans[i][j] == INF) cout << "INF\t";
			else cout << ans[i][j] << "\t";
		}
		cout << endl;
	}
	return 0;
}
/*
input:
5 7
1 2 4
1 4 10
2 3 7
4 5 3
4 2 -2
3 4 -3
5 3 4
output:
全源最短路结果矩阵:
0       4       11      8       11
INF     0       7       4       7
INF     -5      0       -3      0
INF     -2      5       0       3
INF     -1      4       1       0
*/