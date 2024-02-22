#include<iostream>
#include<cmath>
#include "Find_Block.h"
using namespace std;

int n, m, x, y, num = 0, times = 0;
vector<vector<int>>graph;
vector<int>d, low, parent, children;
vector<bool>visited;
stack<pair<int, int>>block;
int main()
{
	cin >> n >> m;
	graph.resize(n + 1);
	for (int i = 0; i < m; ++i) {
		cin >> x >> y;
		//构建无向图
		graph[x].emplace_back(y);
		graph[y].emplace_back(x);
	}
	d.resize(n + 1);
	low.resize(n + 1);
	visited.resize(n + 1, false);
	parent.resize(n + 1);
	parent[1] = -1;//根节点没有父节点
	children.resize(n + 1, 0);
	find_block ss;
	ss.dfsblk(graph, 1, times, d, low, visited, block, parent, children, num);
	//注意！
	//如果出发点1不是割点，则算法运行结束时block不为空，而是存储了出发点所在块的边集，因此，还想额外输出这个块的边集
	if (!block.empty()) {
		num++;
		cout << "以下边组成块" << num << ':' << endl;
		pair<int, int>pp;
		while (!block.empty()) {
			pp = block.top();
			block.pop();
			cout << "( " << pp.first << " , " << pp.second << " ) ";
		}
		cout << endl;
	}
	return 0;
}

/*
sample
input:
6 7
1 2
1 4
2 4
2 3
4 3
2 5
5 6
output:
以下边组成块1:
( 5 , 6 )
以下边组成块2:
( 2 , 5 )
以下边组成块3:
( 3 , 2 ) ( 4 , 3 ) ( 4 , 1 ) ( 2 , 4 ) ( 1 , 2 )
*/