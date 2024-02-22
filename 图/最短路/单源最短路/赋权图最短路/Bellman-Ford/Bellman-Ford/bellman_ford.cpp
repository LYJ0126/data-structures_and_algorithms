#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class edge
{
public:
	int u, v, w;
	edge() :u(0), v(0), w(0x7f7f7f7f) {};
	edge(int _u, int _v, int _w) :u(_u), v(_v), w(_w) {};
	~edge() {};
};
int n, m, s, x, y, weight;
vector<edge>graph;
vector<int>d;
bool bellman_ford()
{
	d[s] = 0;
	int uu, vv, ww;
	for (int i = 1; i < n; ++i) {
		for (int i = 1; i <= m; i++) {//对所有边进行路径松弛
			uu = graph[i].u;
			vv = graph[i].v;
			ww = graph[i].w;
			if (d[vv] > d[uu] + ww) {
				d[vv] = d[uu] + ww;
			}
		}
	}
	//判断是否有负权环路
	for (int i = 1; i <= m; i++) {
		uu = graph[i].u;
		vv = graph[i].v;
		ww = graph[i].w;
		if (d[vv] > d[uu] + ww) return false;
	}
	return true;
}
int main()
{
	cin >> n >> m >> s;
	graph.resize(m + 1);
	d.resize(n + 1, 0x7f7f7f7f);
	for (int i = 1; i <= m; i++) {
		cin >> x >> y >> weight;
		graph[i] = edge(x, y, weight);
	}
	bool flag = bellman_ford();
	if (!flag) cout << "存在负权环路,无法计算最短路\n";
	else {
		cout << "各个点到源点" << s << "的最短路为:\n";
		for (int i = 1; i <= n; i++) {
			cout << i << " : " << d[i] << '\n';
		}
	}
	return 0;
}
/*
input:
5 10 1
1 2 3
1 5 5
2 3 6
2 5 2
3 4 2
4 3 7
4 1 3
5 2 1
5 3 4
5 4 6
output:
各个点到1的距离为:
1 : 0
2 : 3
3 : 9
4 : 11
5 : 5
*/
/*
input:
5 10 1
1 2 6
1 5 7
2 3 5
2 4 -4
2 5 8
3 2 -2
4 3 7
4 1 2
5 3 -3
5 4 9
output:
各个点到源点1的最短路为:
1 : 0
2 : 2
3 : 4
4 : -2
5 : 7
*/
/*
input:
4 6 1
1 2 3
1 3 -1
2 4 -7
3 2 2
3 4 1
4 3 3
output:
存在负权环路,无法计算最短路
*/