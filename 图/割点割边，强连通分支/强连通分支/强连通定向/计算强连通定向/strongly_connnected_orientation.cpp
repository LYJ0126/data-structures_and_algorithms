#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<unordered_map>
using namespace std;
//����������Ϊԭ��������ͼ��ͨ��û�и�ߣ����ض�����ǿ��ͨ����(�ޱ�˹����)
int n, m, x, y;
vector<vector<int>>graph;
vector<vector<int>>graph2;
vector<bool>visited;
unordered_map<int, int>mp;//����ȷ�����Ƿ��Ѿ�����
void dfs_orientation(int s)
{
	visited[s] = true;
	for (int v : graph[s]) {
		if (!visited[v]) {
			graph2[s].push_back(v);//�������Ǹ����ָ���ӽ��
			mp[(s << 12) + v] = mp[(v << 12) + s] = 1;//��¼�ñ��Ѿ�����
			dfs_orientation(v);
		}
		else {
			if (!mp[(s << 12) + v]) {//����ú����û�б����
				mp[(s << 12) + v] = mp[(v << 12) + s] = 1;
				graph2[s].push_back(v);
			}
		}
	}
}
int main()
{
	cin >> n >> m;
	graph.resize(n + 1);
	graph2.resize(n + 1);//���涨�����ɵ�����ͼ
	visited.resize(n + 1, false);
	for (int i = 0; i < m; ++i) {
		cin >> x >> y;
		//��������ͼ
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	dfs_orientation(1);
	cout << "����Ϊ:" << endl;
	for (int u = 1; u <= n; ++u) {
		for (int v : graph2[u]) cout << u << " -> " << v << endl;
	}
	return 0;
}

/*
input:
5 7
1 2
4 1
4 2
1 5
2 5
3 2
3 4
output:
����Ϊ:
1 -> 2
2 -> 4
2 -> 5
3 -> 2
4 -> 1
4 -> 3
5 -> 1
*/