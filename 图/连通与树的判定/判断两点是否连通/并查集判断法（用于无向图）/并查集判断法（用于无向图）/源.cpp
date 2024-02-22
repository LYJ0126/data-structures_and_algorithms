#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

//***注意！用于无向图
int findpa(int id, vector<int>& parent)
{
	if (parent[id] == id) return id;
	return parent[id] = findpa(parent[id], parent);//查询同时路径压缩
}
void merge(int x, int y, vector<int>& parent)
{
	int px = findpa(x, parent);
	int py = findpa(y, parent);
	if (px != py) parent[py] = px;
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>>graph(n + 1);//领接表
	vector<int>parent(n + 1);
	for (int i = 1; i <= n; i++) parent[i] = i;//并查集初始化
	int x, y;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
		merge(x, y, parent);
	}
	int u, v;//查询u,v之间是否有路径
	cin >> u >> v;
	if (findpa(u, parent) == findpa(v, parent)) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}

/*
sample 1:
9 9
1 2
2 3
2 4
3 5
3 6
4 5
7 8
7 9
9 8
6 1
*/
/*
output 1:
Yes
*/

/*
sample 2:
9 9
1 2
2 3
2 4
3 5
3 6
4 5
7 8
7 9
9 8
9 5
*/
/*
output 2:
No
*/