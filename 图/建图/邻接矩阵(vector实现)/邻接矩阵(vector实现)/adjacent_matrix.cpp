#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void dfs1(vector<vector<int>>& graph, vector<bool>& visited, int x)
{
	visited[x] = true;
	cout << x << " ";
	int n = graph.size();
	for (int i = 0; i < n; i++)
	{
		if (graph[x][i] == 1 && visited[i] == false)
		{
			dfs1(graph, visited, i);
		}
	}
}
void bfs1(vector<vector<int>>& graph, int s) {
	int n = graph.size();
	vector<bool>visited(n, false);
	queue<int>q;
	q.push(s);
	visited[s] = true;
	while (!q.empty()){
		int size = q.size();
		while (size--) {
			int u = q.front();
			q.pop();
			cout << u << " ";
			for (int i = 0; i < n; i++) {
				if (graph[u][i] == 1 && visited[i] == false) {
					q.push(i);
					visited[i] = true;
				}
			}
		}
	}
}
/*int main()
{
	int n, m, x, y;
	cin>> n >> m;
	vector<vector<int>>graph(n+1, vector<int>(n+1, 0));//�ڽӾ�������Ϊ��Ȩͼ��������0��1��ʾ�Ƿ�����
	for (int i = 0; i < m; i++)
	{
		cin>> x >> y;
		graph[x][y] = 1;
		graph[y][x] = 1;//����ͼ
	}
	vector<bool>visited(n+1, false);
	dfs1(graph, visited, 1);
	cout << endl;
	bfs1(graph, 1);
	return 0;
}*/

int main()
{
	int n, m, x, y;
	cin>> n >> m;
	const int inf = 99999999;
	vector<vector<int>>graph(n + 1, vector<int>(n + 1, inf));//�ڽӾ�������Ϊ��Ȩͼ��������inf��ʾ������
	for (int i = 0; i < m; i++)
	{
		cin>> x >> y;
		graph[x][y] = 1;
		graph[y][x] = 1;//����ͼ
	}
	//��Ȩͼdfs��bfs����Ȩͼһ�������ﲻ���ظ�
}