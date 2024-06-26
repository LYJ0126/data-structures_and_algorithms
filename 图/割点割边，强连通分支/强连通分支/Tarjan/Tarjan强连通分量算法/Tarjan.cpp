#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<stack>
using namespace std;

int n, m, x, y;
vector<vector<int>>graph;
vector<bool>visited;
vector<int>d;//��¼����ʱ���
vector<int>low;//low[u]��¼u�Լ���������ͨ�������߹�����ջ��(u�Լ������Ƚڵ�)�ڵ�����ȷ��ʴ��򣬼��ܷ��ʵ�����������ȵ�ʱ���
stack<int>st;//��¼ջ�ڶ���
vector<bool>ins;//�жϵ��Ƿ���ջ��
int times = 0;//ʱ���
int part = 0;//ǿ��ͨ��֧����
void dfsscc(int u)
{
	times++;
	d[u] = times;
	low[u] = d[u];
	visited[u] = true;
	st.push(u);
	ins[u] = true;
	for (int v : graph[u]) {
		if (!visited[v]) {
			dfsscc(v);
			low[u] = min(low[u], low[v]);
		}
		else if (ins[v]) {//v��ջ��
			low[u] = min(low[u], d[v]);
		}
	}
	if (low[u] == d[u]) {
		cout << "���¶������ǿ��ͨ��֧ " << ++part << endl;
		int p;
		do {
			p = st.top();
			st.pop();
			ins[p] = false;
			cout << p << ' ';
		} while (p != u);
		cout << endl;
	}
}
void tarjan()
{
	for (int s = 1; s <= n; ++s) {
		if (!visited[s]) dfsscc(s);
	}
}
int main()
{
	cin >> n >> m;
	graph.resize(n + 1);
	visited.resize(n + 1, false);
	d.resize(n + 1);
	low.resize(n + 1);
	ins.resize(n + 1, false);
	for (int i = 0; i < m; ++i) {
		cin >> x >> y;
		graph[x].push_back(y);//����ͼ
	}
	tarjan();
	return 0;
}

/*
input:
5 8
1 2
2 1
1 4
1 5
4 2
4 5
3 2
3 4
output:
���¶������ǿ��ͨ��֧ 1
5
���¶������ǿ��ͨ��֧ 2
4 2 1
���¶������ǿ��ͨ��֧ 3
3
*/