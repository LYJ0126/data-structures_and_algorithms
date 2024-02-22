#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
using namespace std;
vector<vector<int>>graph;
int cx[300], cy[300];//记录每个点其对应的匹配顶点,若没有则令为-1
int visited[300];//记录每次dfsap过程中哪些点已经被访问过了
int n, m, x, y, nx, ny;
vector<int>setx, sety;//二分图的两个顶点集合

int dfsap(int u)//寻找并扩展增广路,每次扩展,匹配的个数都加一
{
	visited[u] = 1;
	for (int v : graph[u]) {
		if (!visited[v]) {
			visited[v] = 1;
			//如果v没有匹配，则直接将v匹配给u。如果v已经匹配了，并且从cy[v],也就是从v之前已经匹配的x出发，
			//还能能够找到一条增广路，则也将v匹配给u,即将原来的匹配边改成非匹配边,非匹配边改成匹配边。匹配数加一。
			//如果第一个条件成立，则不会递归调用
			if (cy[v] == -1 || dfsap(cy[v])) {
				cx[u] = v;
				cy[v] = u;
				return 1;
			}
		}
	}
	return 0;
}
int Hungarian_match()
{
	int res = 0;
	memset(cx, -1, sizeof(cx));
	memset(cy, -1, sizeof(cy));
	for (int r : setx) {
		if (cx[r] == -1) {
			memset(visited, 0, sizeof(visited));
			res += dfsap(r);
		}
	}
	return res;
}
int main()
{
	cin >> n >> m;
	graph.resize(n + 1);
	for (int i = 0; i < m; ++i) {//邻接表存图
		cin >> x >> y;
		graph[x].emplace_back(y);
		graph[y].emplace_back(x);
	}
	//记录二分图两个顶点集
	cin >> nx >> ny;
	setx.resize(nx);
	sety.resize(ny);
	int point;
	for (int i = 0; i < nx; ++i) {
		cin >> point;
		setx[i] = point;
	}
	for (int i = 0; i < ny; ++i) {
		cin >> point;
		sety[i] = point;
	}
	int ans = Hungarian_match();
	cout << "匹配数量为: " << ans << endl;
	cout << "匹配:\n";
	for (int i : setx) {
		if (cx[i] != -1) {
			cout << "( " << i << ',' << cx[i] << " )\n";
		}
	}
	return 0;
}

/*
input:
7 7
1 2
2 3
3 4
2 5
5 4
5 6
7 6
4 3
1 3 5 7
2 4 6
output:
匹配数量为: 3
匹配:
( 1,2 )
( 3,4 )
( 5,6 )
*/
/*
input:
7 7
1 2
2 3
3 4
2 5
5 4
5 6
7 6
4 3
3 5 7 1
2 4 6
output:
匹配数量为: 3
匹配:
( 3,4 )
( 5,2 )
( 7,6 )
*/