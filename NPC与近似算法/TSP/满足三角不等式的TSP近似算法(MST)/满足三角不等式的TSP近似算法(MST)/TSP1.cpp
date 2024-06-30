#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;

//�������MST�ķ��������TSP����
//�����ҳ�ԭ����ȫͼ����С��������Ȼ��������С����������DFS�������γ�һ����·
//������·����TSP����Ľ��ƽ�

int n, x, y, w;
vector<vector<int>> graph;//ͼ���ڽӾ���
int ans = 0;//���չ��ܶ��ٻ�·�ĳ���
vector<vector<int>> tree;//��¼��С������
//prim�㷨����С������
bool cmp(pair<int, int>& a, pair<int, int>& b)
{
	return a.second > b.second;
}
//��С���ȶ��У���һ��Ԫ�ظ�λ��parent,��λ��ý�㣬�ڶ���Ԫ�ش�ߵ�Ȩֵ
priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)>pq(&cmp);

void prim()
{
	//ȡ����һ�������Ϊ��ʼ���
	pq.push(make_pair(1, 0));
	vector<bool> visited(n + 1, false);
	while (!pq.empty()) {
		int u = pq.top().first & 0x00003fff;
		int parent = pq.top().first >> 14;
		pq.pop();
		if (visited[u]) continue;
		visited[u] = true;
		if (parent != 0) {//parent��Ϊ0˵�����ǵ�һ�����,���ñ߼�����С������
			tree[parent].push_back(u);
			tree[u].push_back(parent);
		}
		for (int i = 1; i <= n; ++i) {
			if (graph[u][i] != 0 && !visited[i]) {
				pq.push(make_pair((u << 14) + i, graph[u][i]));
			}
		}
	}
}

int former = 0;//��¼���ܶ��ٻ�·��ǰһ�����
vector<bool> vis;//��¼dfs�ķ������
void dfs_find(int u)//��MST��dfs���ҵ����ܶ��ٻ�·
{
	vis[u] = true;
	if (former != 0) {
		cout<< former << "->" << u << endl;
		ans += graph[former][u];
	}
	former = u;
	for (int v : tree[u]) {
		if (!vis[v]) {
			dfs_find(v);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	graph.resize(n + 1, vector<int>(n + 1, 0));//��ȫͼ���ڽӾ���
	tree.resize(n + 1);
	int m = n * (n - 1) / 2;//��ȫͼ�ı���
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> w;
		graph[x][y] = w;
		graph[y][x] = w;
	}
	prim();
	former = 0;
	vis.resize(n + 1, false);
	cout << "���ܶ��ٻ�·Ϊ��" << endl;
	dfs_find(1);
	cout << former << "->1" << endl;
	ans += graph[former][1];
	cout << "��·����Ϊ��" << ans << endl;
	return 0;
}

/*
input:
5
1 2 6
1 3 3
1 4 2
1 5 4
2 3 5
2 4 1
2 5 8
3 4 10
3 5 9
4 5 7
output:
���ܶ��ٻ�·Ϊ��
1->4
4->2
2->3
3->5
5->1
��·����Ϊ��21
*/