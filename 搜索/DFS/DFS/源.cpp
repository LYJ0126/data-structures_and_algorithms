#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int n, m, startx, starty, endx, endy;
vector<vector<int>>graph;
int ne[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
vector<pair<int, int>>path;
vector<vector<bool>>vis;
bool flag = false;
void dfs(int x, int y)
{
	if(flag) return;//如果找到了就不再继续搜索
	if (x == endx && y == endy) {//找到了终点
		flag = true;
		for (auto p : path) {//输出路径
			cout << "(" << p.first << "," << p.second << ")" << endl;
			graph[p.first][p.second] = 2;
		}
		return;
	}
	for (int i = 0; i < 4; ++i) {
		int nx = x + ne[i][0];
		int ny = y + ne[i][1];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && graph[nx][ny] == 0) {
			vis[nx][ny] = true;
			path.push_back({ nx,ny });
			dfs(nx, ny);
			vis[nx][ny] = false;
			path.pop_back();
		}
	}
}
int main()
{
	cin >> n >> m >> startx >> starty >> endx >> endy;
	graph.resize(n, vector<int>(m, 0));
	path.push_back({ startx,starty });
	vis.resize(n, vector<bool>(m, false));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> graph[i][j];
		}
	}
	vis[startx][starty] = true;
	dfs(startx, starty);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout<<graph[i][j]<<" ";
		}
		cout << endl;
	}
	return 0;
}

/*
input:
7 7 0 0 6 6
0 0 0 0 0 0 0
0 0 0 0 1 0 0
0 1 1 1 1 1 0
0 0 0 0 0 1 0
1 1 1 1 0 0 1
0 0 1 0 0 0 0
0 0 0 0 0 0 0
output:
(0,0)
(0,1)
(0,2)
(0,3)
(1,3)
(1,2)
(1,1)
(1,0)
(2,0)
(3,0)
(3,1)
(3,2)
(3,3)
(3,4)
(4,4)
(4,5)
(5,5)
(5,6)
(6,6)
2 2 2 2 0 0 0
2 2 2 2 1 0 0
2 1 1 1 1 1 0
2 2 2 2 2 1 0
1 1 1 1 2 2 1
0 0 1 0 0 2 2
0 0 0 0 0 0 2
*/