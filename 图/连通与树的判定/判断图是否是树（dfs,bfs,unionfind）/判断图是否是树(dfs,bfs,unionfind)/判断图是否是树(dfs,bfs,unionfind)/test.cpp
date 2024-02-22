#include<iostream>
#include<cstring>
#include "TreeJudge.h"
using namespace std;

int n, m, x, y;
vector<vector<int>>graph;
vector<int>pa;//用于并查集的数组
bool flag = false;//判断是否有圈
int main()
{
	cin >> n >> m;
	graph.resize(n + 1);
	pa.resize(n + 1);
	treejudge ss;
	for (int i = 0; i <= n; i++) pa[i] = i;//初始化
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		//这里选择无向图
		graph[x].emplace_back(y);
		graph[y].emplace_back(x);
		if (ss.merge(pa, x, y)) flag = true;
	}
	//判断图是否是树
	cout << boolalpha << ss.bfs_judge(graph, 1) << endl;
	cout << boolalpha << ss.dfs_judge(graph, 1) << endl;
	cout << boolalpha << ss.unionfind_judge(pa, flag) << endl;
	return 0;
}
/*
sample1:
input:
5 4
1 2
2 3
4 3
5 2
output:
true
*/

/*
* sample2:
intput:
5 5
1 2
2 3
4 3
3 1
2 5
output:
false
*/