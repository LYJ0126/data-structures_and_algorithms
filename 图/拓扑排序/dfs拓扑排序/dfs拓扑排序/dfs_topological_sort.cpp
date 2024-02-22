#include<iostream>
#include<vector>
#include<cmath>
#include<stack>
using namespace std;


//ע�⣡��������ֻ������DAG(�����޻�ͼ)��
//DAGһ����������һ����������
int n, m, x, y;
vector<vector<int>>graph;
vector<int>ans;//������
stack<int>st;//�ݹ�����м�¼�𰸣�����������������
vector<bool>vis;
void dfs(int u)//���ѵ��׺󣬻��ݵ�ʱ�����ջ�����ʽ�����ĵ�����ջ������ָ��ĵ��ָ�����ĵ�����ջ
{
	vis[u] = true;
	for (int v : graph[u]) {
		if (!vis[v]) dfs(v);
	}
	st.push(u);
}
void dfs_topological_sort()
{
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) dfs(i);
	}
}
int main()
{
	cin >> n >> m;
	graph.resize(n + 1);
	ans.resize(n + 1);
	vis.resize(n + 1, false);
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		graph[x].push_back(y);
	}
	dfs_topological_sort();
	cout << "����������:\n";
	while (!st.empty()) {
		cout << st.top() << ' ';
		st.pop();
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
5 6 4 3 2 1 8 9 7
*/