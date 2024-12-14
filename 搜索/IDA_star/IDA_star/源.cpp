#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

int n, m, startx, starty, endx, endy;
vector<vector<int>>graph;
int ne[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
vector<pair<int, int>>path;
bool flag = false;
vector<vector<bool>>vis;

inline int manhattan(int x, int y)//曼哈顿距离,启发式函数
{
	return abs(x - endx) + abs(y - endy);
}

bool IDA_star_search(int x, int y, int g, int bound)
{
	if (x == endx && y == endy)//到达终点
	{
		flag = true;
		return true;
	}
	if (g + manhattan(x, y) > bound)//当前路径长度+启发式函数值>限制长度
		return false;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + ne[i][0];
		int ny = y + ne[i][1];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && graph[nx][ny] != 1)
		{
			vis[nx][ny] = 1;
			path.push_back({ nx,ny });
			if (IDA_star_search(nx, ny, g + 1, bound))
				return true;
			vis[nx][ny] = 0;//回溯
			path.pop_back();//回溯
		}
	}
	return false;
}

void IDA_star(int sx, int sy, int ex, int ey)
{
	int bound = manhattan(sx, sy);//初始限制长度为启发式函数值
	while (!flag)
	{
		vis.clear();
		vis.resize(n, vector<bool>(m,false));
		vis[sx][sy] = true;
		path.push_back({ sx,sy });
		if (IDA_star_search(sx, sy, 0, bound))//搜索成功
			break;
		bound++;
		if(bound > abs(ex-sx)*abs(ey-sy))//无解
			break;
	}
	if (flag)
	{
		for (auto i : path) {
			cout << '(' << i.first << ',' << i.second << ')' << endl;
			graph[i.first][i.second] = 2;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << graph[i][j] << ' ';
			}
			cout << endl;
		}
	}
	else
		cout << "No path" << endl;
}

int main()
{
	cin >> n >> m >> startx >> starty >> endx >> endy;
	graph.resize(n, vector<int>(m));
	//vis.resize(n, vector<bool>(m, false));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> graph[i][j];
	IDA_star(startx, starty, endx, endy);
	return 0;
}

/*
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
2 0 0 0 0 0 0
2 0 0 0 1 0 0
2 1 1 1 1 1 0
2 2 2 2 2 1 0
1 1 1 1 2 2 1
0 0 1 0 0 2 2
0 0 0 0 0 0 2
*/