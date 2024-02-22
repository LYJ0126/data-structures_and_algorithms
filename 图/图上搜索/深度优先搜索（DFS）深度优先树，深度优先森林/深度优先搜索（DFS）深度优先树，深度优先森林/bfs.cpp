#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;


//��Դ��������������
int cnt = 0;
void dfs_visit(vector<vector<int>>& graph, int source, vector<bool>& visited)
{
	visited[source] = true;//���������߹�
	cout << source << ' ';
	cnt++;
	for (int i = 0; i < graph[source].size(); i++) {
		if (!visited[graph[source][i]]) dfs_visit(graph, graph[source][i], visited);
	}
}
//ͼ��������ȱ���
void dfs(vector<vector<int>>& graph, vector<bool>& visited)
{
	for (int i = 1; i < graph.size(); i++) {
		if (!visited[i]) dfs_visit(graph, i, visited);//û���������ĵ�ΪԴ��㿪ʼ����
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>>graph(n + 1);//��ӱ��ͼ������ѡ������ͼ
	int x, y;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		graph[x].push_back(y);
	}
	vector<bool>visited(n + 1, false);//����dfs_visit����¼��Щ����Ѿ�������
	int source;
	cin >> source;
	//dfs_visitԴ��㣬������ʵĽ��
	dfs_visit(graph, source, visited);
	cout << '\n';
	cout << cnt << '\n';
	//ͼ��������ȱ���
	for (int i = 1; i <= n; i++) visited[i] = false;//��ʼ��
	dfs(graph, visited);
	return 0;
}

/*
sample 1:
6 8
1 2
1 4
2 3
3 4
4 2
5 3
5 6
6 6
1
*/
/*
output 1:
1 2 3 4
4
1 2 3 4 5 6
*/

/*
sample 2:
6 8
1 2
1 4
2 3
3 4
4 2
5 3
5 6
6 6
5
*/
/*
output 2:
5 3 4 2 6
5
1 2 3 4 5 6
*/