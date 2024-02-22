#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int x)
{
	visited[x] = true;
	cout<<x<<" ";
	for (int v : graph[x])
	{
		if(!visited[v])
			dfs(graph, visited, v);
	}
}

void bfs(vector<vector<int>>& graph, int s)
{
	queue<int>q;
	q.push(s);
	vector<bool>visited(graph.size(), false);
	visited[s] = true;
	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			int u=q.front();
			q.pop();
			cout<<u<<" ";
			for (int v : graph[u]) {
				if (!visited[v]) {
					visited[v] = true;
					q.push(v);
				}
			}
		}
	}
}
int main()
{
	int n, m, x, y;
	cin>>n>>m;
	vector<vector<int>>graph(n + 1);//�ڽӱ�,����Ϊ��Ȩͼ
	for (int i = 0; i < m; i++)
	{
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);//����ͼ
	}
	vector<bool>visited(n + 1, false);
	dfs(graph, visited, 1);
	cout<<endl;
	bfs(graph, 1);
	return 0;
}

/*int main()
{
	int n, m, x, y, w;
	cin >> n >> m;
	vector<vector<pair<int, int>>>graph(n + 1);//�ڽӱ�,����Ϊ��Ȩͼ
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> w;
		graph[x].push_back({ y, w });
		graph[y].push_back({ x, w });//����ͼ
	}
	//��Ȩͼ��dfs��bfs����Ȩͼ��һ�������ﲻ���ظ�
}*/