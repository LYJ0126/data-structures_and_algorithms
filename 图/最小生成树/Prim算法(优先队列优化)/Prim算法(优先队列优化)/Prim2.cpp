#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;

//这里我们认为图是连通的,即一定有生成树
int n, m, x, y, w;
vector<vector < pair<int, int>>>graph;
vector<bool>vis;
bool cmp(pair<int, int>& a, pair<int, int>& b)//最小堆比较函数
{
	return a.second > b.second;
}
priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)>pq(cmp);
//pair中第一个变量高位存parent,低位存该点;第二个变量存边权
//prim算法(优先队列优化)
void prim()
{
	//取任意一顶点开始扩展，这里选1
	pq.push(make_pair(1, 0));
	int pointleft = n;//剩余的点数
	int ans = 0;
	vector<pair<int, int>>::iterator it;
	cout << "最小生成树:\n";
	while (pointleft) {
		while (vis[pq.top().first & 0x00003fff]) pq.pop();//可能有的点已经被访问了,但边还储存在优先队列中，需要弹出
		int parent = (pq.top().first>>14), u=(pq.top().first&0x00003fff), v, weight;
		ans += pq.top().second;
		pq.pop();
		vis[u] = true;
		--pointleft;
		if (u != 1) {
			cout << "( " << parent << " , " << u << " )\n";
		}
		for (it = graph[u].begin(); it != graph[u].end(); it++) {
			v = it->first;
			weight = it->second;
			if (!vis[v]) {
				pq.push(make_pair((u << 14) + v, weight));
			}
		}
	}
	cout << "最小生成树权和:" << ans << endl;
}
int main()
{
	cin >> n >> m;
	graph.resize(n + 1);
	vis.resize(n + 1, false);
	for (int i = 0; i < m; ++i) {
		cin >> x >> y >> w;
		graph[x].push_back(make_pair(y, w));
		graph[y].push_back(make_pair(x, w));
	}
	prim();
	return 0;
}

/*
input:
7 11
1 2 7
1 4 5
2 4 9
2 3 8
2 5 7
3 5 5
4 5 15
4 6 6
5 6 8
5 7 9
6 7 11
output:
最小生成树:
( 1 , 4 )
( 4 , 6 )
( 1 , 2 )
( 2 , 5 )
( 5 , 3 )
( 5 , 7 )
最小生成树权和:39
*/