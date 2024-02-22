#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;

//!ע�⣬�������������DAG(�����޻�ͼ)��
//!ÿ��DAG���ٴ���һ����������
int n, m, x, y;
vector<vector<int>>graph;
vector<int>indeg;//������,ע�������
vector<int>ans;//��¼������
void bfs_topological_sort()
{
	int id = 0;
	queue<int>que;
	vector<bool>vis(n + 1, false);//��¼��Щ���Ѿ��������������
	for (int i = 1; i <= n; i++) {//�������Ϊ0����ӣ�����¼�������
		if (!indeg[i]) {
			que.push(i);
			ans[++id] = i;
			vis[i] = true;
		}
	}
	while (!que.empty()) {//bfs
		int size = que.size();
		while (size) {
			int u = que.front();
			que.pop();
			for (int v : graph[u]) {
				if (!vis[v]) {
					if (!--indeg[v]) {
						que.push(v);
						ans[++id] = v;
						vis[v] = true;
					}
				}
			}
			--size;
		}
	}
}
int main()
{
	cin >> n >> m;
	graph.resize(n + 1);
	indeg.resize(n + 1, 0);
	ans.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		graph[x].push_back(y);
		indeg[y]++;//y��ȼ�һ
	}
	bfs_topological_sort();
	cout << "����������:\n";
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << ' ';
	}
	return 0;
}
/*
input:
9 9
1 7
1 8
2 7
4 1
4 7
5 8
5 6
6 9
8 9
output:
����������:
2 3 4 5 1 6 7 8 9
*/