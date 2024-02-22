#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
//这里选用领接表存储
//这里图为无向图

int cnt = 0;//cnt记录以source为根的广度优先树有多少结点
void bfs1(vector<vector<int>>& graph, int source)
{
	queue<int>que;
	vector<bool>visited(graph.size(), false);
	que.push(source);
	visited[source] = true;
	cnt++;
	while (!que.empty()) {
		int size = que.size();
		while (size) {
			int u = que.front();
			cout << u << ' ';
			que.pop();
			for (int j = 0; j < graph[u].size(); j++) {
				int v = graph[u][j];
				if (!visited[v]) {//不走回头路
					que.push(v);
					visited[v] = true;
					cnt++;
				}
			}
			size--;
		}
	}
}
//打印路径
//先bfs求出s为根的广度优先树，同时求得树上每个结点的前驱
void bfs2(vector<vector<int>>& graph, int source,vector<int>& pre)
{
	queue<int>que;
	vector<bool>visited(graph.size(), false);
	que.push(source);
	visited[source] = true;
	while (!que.empty()) {
		int size = que.size();
		while (size) {
			int u = que.front();
			que.pop();
			for (int j = 0; j < graph[u].size(); j++) {
				int v = graph[u][j];
				if (!visited[v]) {//不走回头路
					que.push(v);
					visited[v] = true;
					pre[v] = u;
				}
			}
			size--;
		}
	}
}
//打印路径
void printpath(vector<vector<int>>& graph, int s, int v, vector<int>& pre)
{
	if (v == s) cout << s << ' ';
	else if (pre[v] == -1) cout << "No path from " << s << " to " << v << " exsits." << '\n';
	else { 
		printpath(graph, s, pre[v], pre); 
		cout << v << ' ';
	}
}
int main()
{
	int n, m,source;//n点，m条边
	cin >> n >> m;
	vector<vector<int>>graph(n + 1);
	//存图
	int x, y;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	cin >> source;
	bfs1(graph, source);
	cout << '\n';
	cout << cnt << '\n';
	int start, end;
	cin >> start >> end;
	vector<int>pre(n + 1, -1);//-1表示没有前驱，即不在start为根节点的广度优先树上
	bfs2(graph, start, pre);//bfs求出前驱
	printpath(graph, start, end, pre);
	return 0;
}

/*
样例1：
7 6
1 2
2 3
4 2
3 5
5 4
3 6
1
1 5
*/
/*
输出1：
1 2 3 4 5 6
6
1 2 3 5
*/

/*
样例2：
7 6
1 2
2 3
4 2
3 5
5 4
3 6
1
6 2
*/
/*
输出2：
1 2 3 4 5 6
6
6 3 2
*/

/*
样例3：
7 6
1 2
2 3
4 2
3 5
5 4
3 6
2
3 7
*/
/*
输出3：
2 1 3 4 5 6
6
No path from 3 to 7 exsits.
*/