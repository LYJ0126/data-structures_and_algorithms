#include<iostream>
#include "Bipartite_Graph_Judge.h"
using namespace std;

int n, m, x, y;
vector<vector<int>>graph;
vector<bool>visited;
vector<int>color;
//输入保证图连通
int main()
{
	cin >> n >> m;
	graph.resize(n + 1);
	visited.resize(n + 1, false);
	color.resize(n + 1, 1);
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		//构建无向图
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	bipartite_graph_judge ss;
	cout << boolalpha << ss.dfsbpt(graph, color, visited, 1) << endl;
	for (int i = 0; i <= n; i++) color[i] = 1;
	cout << boolalpha << ss.bfsbpt(graph, color) << endl;
	return 0;
}
/*
sample1:
input:
5 6
1 4
1 5
2 4
5 2
3 4
3 5
output:
true
*/
/*
sample2:
input:
5 6
1 4
1 5
2 4
2 5
3 5
3 2
output:
false
*/