#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
//����ѡ����ӱ�洢
//����ͼΪ����ͼ

int cnt = 0;//cnt��¼��sourceΪ���Ĺ���������ж��ٽ��
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
				if (!visited[v]) {//���߻�ͷ·
					que.push(v);
					visited[v] = true;
					cnt++;
				}
			}
			size--;
		}
	}
}
//��ӡ·��
//��bfs���sΪ���Ĺ����������ͬʱ�������ÿ������ǰ��
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
				if (!visited[v]) {//���߻�ͷ·
					que.push(v);
					visited[v] = true;
					pre[v] = u;
				}
			}
			size--;
		}
	}
}
//��ӡ·��
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
	int n, m,source;//n�㣬m����
	cin >> n >> m;
	vector<vector<int>>graph(n + 1);
	//��ͼ
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
	vector<int>pre(n + 1, -1);//-1��ʾû��ǰ����������startΪ���ڵ�Ĺ����������
	bfs2(graph, start, pre);//bfs���ǰ��
	printpath(graph, start, end, pre);
	return 0;
}

/*
����1��
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
���1��
1 2 3 4 5 6
6
1 2 3 5
*/

/*
����2��
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
���2��
1 2 3 4 5 6
6
6 3 2
*/

/*
����3��
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
���3��
2 1 3 4 5 6
6
No path from 3 to 7 exsits.
*/