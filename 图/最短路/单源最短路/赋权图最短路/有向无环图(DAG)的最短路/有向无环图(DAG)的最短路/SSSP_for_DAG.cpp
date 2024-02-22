#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;

int n, m, x, y, w, s;
vector<vector<pair<int, int>>>graph;//��һ��ֵΪ�ڵ㣬�ڶ���ֵΪȨ��
vector<int>indeg;//������,ע�������
vector<int>sort_res;//��¼������
vector<int>d;//��¼���·
void bfs_topological_sort()//����ѡ��BFS��������
{
	int id = 0;
	queue<int>que;
	vector<bool>vis(n + 1, false);//��¼��Щ���Ѿ��������������
	for (int i = 1; i <= n; i++) {//�������Ϊ0����ӣ�����¼�������
		if (!indeg[i]) {
			que.push(i);
			sort_res[++id] = i;
			vis[i] = true;
		}
	}
	vector<pair<int, int>>::iterator it;
	int v;
	while (!que.empty()) {//bfs
		int size = que.size();
		while (size) {
			int u = que.front();
			que.pop();
			for (it = graph[u].begin(); it != graph[u].end();it++) {
				v = it->first;
				if (!vis[v]) {
					if (!--indeg[v]) {
						que.push(v);
						sort_res[++id] = v;
						vis[v] = true;
					}
				}
			}
			--size;
		}
	}
}
void dag_shortest_path()
{
	bfs_topological_sort();
	int u, v, weight;
	d[s] = 0;
	vector<pair<int, int>>::iterator it;
	for (int i = 1; i <= n; ++i) {//������������˳��ѡȡ�㲢�����ڱ߽����ɳ�
		u = sort_res[i];
		for (it = graph[u].begin(); it != graph[u].end(); it++) {//·���ɳ�
			v = it->first, weight = it->second;
			if (d[v] > d[u] + weight) d[v] = d[u] + weight;
		}
	}
}
int main()
{
	cin >> n >> m >> s;
	graph.resize(n + 1);
	indeg.resize(n + 1, 0);
	sort_res.resize(n + 1);
	d.resize(n + 1, 0x7f7f7f7f);
	for (int i = 0; i < m; ++i) {
		cin >> x >> y >> w;
		graph[x].push_back(make_pair(y, w));
		indeg[y]++;
	}
	dag_shortest_path();
	cout << "�����㵽Դ��" << s << "�����·Ϊ:\n";
	for (int i = 1; i <= n; i++) {
		if (d[i] == 0x7f7f7f7f) cout << i << " : " << "INF" << '\n';
		else cout << i << " : " << d[i] << '\n';
	}
}

/*
input:
6 10 1
1 4 2
1 3 6
2 1 5
2 4 3
3 6 1
3 5 -1
4 3 7
4 5 4
4 6 2
5 6 -2
output:
�����㵽Դ��1�����·Ϊ:
1 : 0
2 : INF
3 : 6
4 : 2
5 : 5
6 : 3
*/