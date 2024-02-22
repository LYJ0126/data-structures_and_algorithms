#include<iostream>
#include "DFSCV.h"
using namespace std;

int n, m, x, y, times = 0;
vector<vector<int>>graph;
vector<int>ans, d, low, parent, children;
vector<bool>visited, iscut;
int main()
{
	cin >> n >> m;
	graph.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		//构建无向图
		graph[x].emplace_back(y);
		graph[y].emplace_back(x);
	}
	//初始化
	d.resize(n + 1);
	low.resize(n + 1);
	parent.resize(n + 1);
	parent[1] = -1;//根没有双亲节点
	children.resize(n + 1, 0);
	visited.resize(n + 1, false);
	iscut.resize(n + 1, false);
	//调用dfscv函数
	find_cut_point ss;
	ss.dfscv(graph, 1, times, d, low, visited, parent, children,iscut);
	for (int i = 1; i <= n; i++) {
		if (iscut[i]) ans.push_back(i);
	}
	if (!ans.size()) cout << "No cut point." << endl;
	else {
		for (int i : ans) cout << i << ' ';
	}
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
2
*/

/*
sample2:
input:
5 7
1 2
1 4
2 3
4 2
4 3
2 5
5 3
output:
No cut point.
*/