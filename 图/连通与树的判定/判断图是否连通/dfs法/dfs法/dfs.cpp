#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int n, m, x, y,times = 0;
vector<vector<int>>graph;
vector<bool>visited;//��¼���Ƿ�������
vector<int>dfn;//��ʾ��ǰ��������к�
vector<int>low;//low[u]��ʾu��u���ӽ��ͨ�������������ҵ�����������Ƚڵ�����к�
vector<int>parent;//parent��ʾ�ýڵ�ǰһ�����ʵĽڵ�
vector<int>children;//children��ʾ�ý��������������е��ӽڵ����
vector<int>ans;//�����
void dfscv(int u)
{
	times++;
	dfn[u] = times;
	low[u] = dfn[u];
	visited[u] = true;
	int len = graph[u].size();
	for (int i = 0; i < len; i++) {
		int v = graph[u][i];
		if (!visited[v]) {//u->v�����ߣ����ڵ�v֮ǰû��������
			parent[v] = u;
			children[u]++;
			dfscv(v);//����
			low[u] = min(low[u], low[v]);//low[u]ȡlow[u]��low[v]��Сֵ
			if (parent[u] == INT_MIN && children[u] >= 2) ans.push_back(u);//��u�Ǹ�������������������ʱ��u�Ǹ��
			else if (parent[u] != INT_MIN && low[v] >= dfn[u]) ans.push_back(u);
			//��u���Ǹ���low[v]>=dfn[u]��˵��v�����ӽ�������ָ��u��û������·����ָ��u�����ȣ�˵��u�Ǹ��
		}
		else if (v!=parent[u]) {//v->u��������
			low[u] = min(low[u], dfn[v]);
			//u->v��һ������ߣ���v��ǰ�Լ������ʹ��ˣ�v��u�����ȣ�ȡ�����ȵı�������ֵ��low[u]�Ƚϼ���
		}
	}
}
int main()
{
	cin >> n >> m;
	graph.resize(n + 1);
	visited.resize(n + 1, false);
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);//����Ϊ����ͼ
	}
	dfn.resize(n + 1, 0);
	low.resize(n + 1);
	parent.resize(n + 1);
	parent[1] = INT_MIN;//�����ǣ����ڵ�(����Ϊ1)û��˫�׽ڵ�
	children.resize(n + 1, 0);
	dfscv(1);
	cout << "��Ϊ: ";
	for (int i : ans) cout << i << ' ';
	return 0;
}
/*
sample:
input:
7 8
1 2
1 4
2 4
3 2
3 4
5 2
1 6
6 7
output: 2 6 1
*/